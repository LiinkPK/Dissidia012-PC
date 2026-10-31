cmake_minimum_required(VERSION 3.20)
# Dissidia 012 Final Fantasy HD Remastered on PortableKit.
#
# Built on the PortableKit branch "d012": upstream PortableKit plus the patch series of the open-source port
# third_party/dissidia012-pc (stencil, pixel mask, streaming music, movies, the present thread and more), and
# built from that port's host code, which is credited and MIT-licensed (third_party/dissidia012-pc/LICENSE).
# The game's generated code and overlay libraries are made from the player's own disc and never committed; they
# live in work/ (generated/ and overlays/).
project(Dissidia012 VERSION 0.2.0 LANGUAGES C CXX RC)

set(PORTABLEKIT_ROOT "" CACHE PATH
    "PortableKit source directory (the d012 branch: PortableKit plus the dissidia012-pc patches)")
if(NOT PORTABLEKIT_ROOT OR NOT EXISTS "${PORTABLEKIT_ROOT}/cmake/PortableKit.cmake")
    message(FATAL_ERROR "Set PORTABLEKIT_ROOT to the PortableKit source directory")
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
            "${CMAKE_CURRENT_SOURCE_DIR}/d012_no_versus.cpp"
            "${D012_PORT_DIR}/host/d012_hle.cpp"
            "${D012_PORT_DIR}/host/d012_prx.cpp"
            "${D012_PORT_DIR}/host/d012_json.cpp"
            "${D012_PORT_DIR}/host/d012_mod_manifest.cpp"
            "${D012_PORT_DIR}/host/d012_mods.cpp"
            "${D012_PORT_DIR}/host/d012_dlc.cpp"
            "${D012_PORT_DIR}/host/d012_nintendo_stream.cpp"
            "${D012_PORT_DIR}/host/d012_decomp_harness.cpp"
            "${D012_PORT_DIR}/host/d012_decomp_bgm.cpp"
            "${D012_PORT_DIR}/host/d012_decomp_pad.cpp"
            "${D012_PORT_DIR}/host/d012_bgm_playlist.cpp"
            "${D012_PORT_DIR}/host/d012_camera.cpp"
            "${D012_PORT_DIR}/host/d012_loading_layout.cpp"
            "${D012_PORT_DIR}/host/d012_crash_report.cpp"
            "${D012_PORT_DIR}/host/d012_test_switches.cpp"
            "${D012_PORT_DIR}/host/d012_portable.cpp")
target_include_directories(d012_native PRIVATE "${D012_PORT_DIR}/host" "${D012_PROFILE_HOST}")
set(D012_PORTABLEKIT_DIR "${PORTABLEKIT_ROOT}")

# Decompiled game functions (C), run as native overrides (third_party/dissidia012-pc/port/decomp/). C is enabled
# in project() above: SDL3's CMake package compiles a C test program when PortableKit looks for it.
add_library(d012_decomp STATIC "${D012_PORT_DIR}/decomp/bgm_table.c"
                               "${D012_PORT_DIR}/decomp/bgm_selector.c"
                               "${D012_PORT_DIR}/decomp/battle_camera.c"
                               "${D012_PORT_DIR}/decomp/pad.c"
                               "${D012_PORT_DIR}/decomp/pad_walk.c")
target_link_libraries(d012_native PRIVATE d012_decomp)

if(WIN32)
    # Icon of the .exe itself (Explorer, taskbar); the window icon is set at runtime
    target_sources(d012_native PRIVATE "${D012_PROFILE_HOST}/d012.rc")
    target_link_libraries(d012_native PRIVATE winmm gdi32 user32)
endif()
