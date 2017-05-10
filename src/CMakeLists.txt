if(CMAKE_HOST_WIN32 OR CMAKE_HOST_APPLE)
    cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
else()
    cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
endif()

set(YI_PROJECT_NAME Game)
set(YI_DISPLAY_NAME “a game with you.i engine“)
project (${YI_PROJECT_NAME})

set(YI_REL_SRC_DIR .)
set (YI_SRC_FILES
    ${YI_REL_SRC_DIR}/GameApp.cpp
    ${YI_REL_SRC_DIR}/GameAppFactory.cpp
)

set(YI_REL_PATH_TO_ROOT ../youiengine)
include(${YI_REL_PATH_TO_ROOT}/AppCommon/build/AppCommon.cmake)

YiIncludeDefaultLibraries()
