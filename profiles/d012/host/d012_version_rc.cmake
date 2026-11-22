# The exe's version resource (Explorer's file properties), made from kReleaseVersion in d012_profile.cpp, so a release changes that
# one line only. Sets D012_RC_FILE to the generated resource script.
file(STRINGS "${CMAKE_CURRENT_LIST_DIR}/d012_profile.cpp" _d012_version_line REGEX "kReleaseVersion = \"v[0-9]+\.[0-9]+\.[0-9]+\"")
if(NOT _d012_version_line MATCHES "kReleaseVersion = \"v([0-9]+)\.([0-9]+)\.([0-9]+)\"")
    message(FATAL_ERROR "kReleaseVersion (vMAJOR.MINOR.PATCH) not found in ${CMAKE_CURRENT_LIST_DIR}/d012_profile.cpp")
endif()
set(D012_VERSION_COMMA "${CMAKE_MATCH_1},${CMAKE_MATCH_2},${CMAKE_MATCH_3},0")
set(D012_VERSION_TEXT "${CMAKE_MATCH_1}.${CMAKE_MATCH_2}.${CMAKE_MATCH_3}")  # shown as is in the file properties; the numeric version above has its fourth part
set(D012_ICON_PATH "${CMAKE_CURRENT_LIST_DIR}/d012.ico")
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/d012_profile.cpp" "${CMAKE_CURRENT_LIST_DIR}/d012.rc.in")
set(D012_RC_FILE "${CMAKE_CURRENT_BINARY_DIR}/d012.rc")
configure_file("${CMAKE_CURRENT_LIST_DIR}/d012.rc.in" "${D012_RC_FILE}" @ONLY)
