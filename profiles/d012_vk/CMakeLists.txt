cmake_minimum_required(VERSION 3.20)
# Dissidia 012 Final Fantasy HD Remastered on PortableKit.
#
# Built on the PortableKit branch "d012": upstream PortableKit plus the patch series of the open-source port
# third_party/dissidia012-pc (stencil, pixel mask, streaming music, movies, the present thread and more), and
# built from that port's host code, which is credited and MIT-licensed (third_party/dissidia012-pc/LICENSE).
# The game's generated code and overlay libraries are made from the player's own disc and never committed; they
# live in work/ (generated/ and overlays/).
project(Dissidia012 VERSION 0.2.0 LANGUAGES C CXX)
if(WIN32)
    enable_language(RC)
endif()

set(PORTABLEKIT_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../third_party/PortableKit-d012" CACHE PATH
    "PortableKit source directory (the d012 branch: PortableKit plus the dissidia012-pc patches)")
if(NOT PORTABLEKIT_ROOT OR NOT EXISTS "${PORTABLEKIT_ROOT}/cmake/PortableKit.cmake")
    message(FATAL_ERROR "third_party/PortableKit-d012 is missing: run scripts/setup_portablekit.ps1 (Windows) or scripts/setup_portablekit.sh (Linux, macOS) first, or set PORTABLEKIT_ROOT")
endif()

get_filename_component(D012_REPO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
set(D012_PORT_DIR "${D012_REPO_ROOT}/third_party/dissidia012-pc/port")
set(D012_PROFILE_HOST "${D012_REPO_ROOT}/profiles/d012/host")
set(D012_WORK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../d012_pk/work" CACHE PATH
    "Folder with generated/ and overlays/ (made from the player's disc, never committed)")

set(PSPRECOMP_BUILD_TESTS OFF CACHE BOOL "Build reusable PSPRecomp tests")
# The sources are UTF-8 (PortableKit's menus and font samples have Japanese text); MSVC otherwise reads them in
# the PC's ANSI code page. Set before PortableKit so its targets get it too.
if(MSVC)
    add_compile_options(/utf-8)
endif()
add_subdirectory("${PORTABLEKIT_ROOT}" portablekit)

# portablekit_add_game() reads <profile>/config/nids.csv for NIDs the framework does not name.
configure_file("${D012_PORT_DIR}/config/nids.csv" "${D012_WORK_DIR}/config/nids.csv" COPYONLY)

portablekit_add_game(d012_native
    PROFILE_DIR "${D012_WORK_DIR}"
    SOURCES "${D012_PROFILE_HOST}/d012_profile.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/d012_hud_layout.cpp"
            "${D012_PORT_DIR}/host/d012_hle.cpp"
            "${D012_PORT_DIR}/host/d012_prx.cpp"
            "${D012_PORT_DIR}/host/d012_dlc.cpp"
            "${D012_PORT_DIR}/host/d012_decomp_harness.cpp"
            "${D012_PORT_DIR}/host/d012_decomp_pad.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/d012_no_bloom.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/d012_braviest_turning.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/d012_emendatus.cpp"
            "${D012_PORT_DIR}/host/d012_camera.cpp"
            "${D012_PORT_DIR}/host/d012_crash_report.cpp"
            "${D012_PORT_DIR}/host/d012_test_switches.cpp"
            "${D012_PORT_DIR}/host/d012_portable.cpp")
target_include_directories(d012_native PRIVATE "${D012_PORT_DIR}/host" "${D012_PROFILE_HOST}")
set(D012_PORTABLEKIT_DIR "${PORTABLEKIT_ROOT}")

# Decompiled game functions (C), run as native overrides (third_party/dissidia012-pc/port/decomp/). C is enabled
# in project() above: SDL3's CMake package compiles a C test program when PortableKit looks for it.
add_library(d012_decomp STATIC "${D012_PORT_DIR}/decomp/battle_camera.c"
                               "${D012_PORT_DIR}/decomp/pad.c"
                               "${D012_PORT_DIR}/decomp/pad_walk.c")
target_link_libraries(d012_native PRIVATE d012_decomp)

if(WIN32)
    # Icon of the .exe itself (Explorer, taskbar); the window icon is set at runtime
    target_sources(d012_native PRIVATE "${D012_PROFILE_HOST}/d012.rc")
    target_link_libraries(d012_native PRIVATE winmm gdi32 user32)
    # No console window: a windowed program that still starts at main(). Output redirected to a file
    # (`> log.txt`) keeps working; started from a terminal it prints nothing there, as expected.
    set_target_properties(d012_native PROPERTIES WIN32_EXECUTABLE TRUE)
    target_link_options(d012_native PRIVATE "/ENTRY:mainCRTStartup")
endif()
# The game looks for its overlay libraries in an "overlays" folder next to the executable, while the build writes
# them to bin/overlays/<config>. Without this copy, a rebuilt overlay never reaches the folder the game reads.
file(GLOB D012_OVERLAY_META CONFIGURE_DEPENDS "${D012_WORK_DIR}/overlays/*/meta.txt")
set(D012_OVERLAY_TARGETS "")
foreach(meta IN LISTS D012_OVERLAY_META)
    get_filename_component(overlay_dir "${meta}" DIRECTORY)
    get_filename_component(overlay_name "${overlay_dir}" NAME)
    if(TARGET overlay_${overlay_name})
        list(APPEND D012_OVERLAY_TARGETS overlay_${overlay_name})
    endif()
endforeach()
# Only for multi-config generators (Visual Studio, Xcode), which write overlays to bin/overlays/<config>.
# Single-config generators (Ninja, Makefiles) already write them to bin/overlays.
get_property(D012_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(D012_OVERLAY_TARGETS AND D012_MULTI_CONFIG)
    add_custom_target(d012_copy_overlays ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:d012_native>/overlays"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_BINARY_DIR}/bin/overlays/$<CONFIG>" "$<TARGET_FILE_DIR:d012_native>/overlays"
        COMMENT "Copying the overlay libraries next to the executable")
    add_dependencies(d012_copy_overlays ${D012_OVERLAY_TARGETS})
endif()
# An edition's corpus library (corpora/<key>.dll, such as the Emendatus mod's) is looked for next to the executable; the
# multi-config generators write it to bin/corpora/<config>, so it is copied beside the executable the same way.
file(GLOB D012_CORPUS_TARGETS_DIRS CONFIGURE_DEPENDS LIST_DIRECTORIES true "${D012_WORK_DIR}/generated-variants/*")
set(D012_CORPUS_TARGETS "")
foreach(variant_dir IN LISTS D012_CORPUS_TARGETS_DIRS)
    get_filename_component(variant_key "${variant_dir}" NAME)
    if(TARGET d012_native_corpus_${variant_key})
        list(APPEND D012_CORPUS_TARGETS d012_native_corpus_${variant_key})
    endif()
endforeach()
if(D012_CORPUS_TARGETS AND D012_MULTI_CONFIG)
    add_custom_target(d012_copy_corpora ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:d012_native>/corpora"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_BINARY_DIR}/bin/corpora/$<CONFIG>" "$<TARGET_FILE_DIR:d012_native>/corpora"
        COMMENT "Copying the edition corpora next to the executable")
    add_dependencies(d012_copy_corpora ${D012_CORPUS_TARGETS})
endif()
