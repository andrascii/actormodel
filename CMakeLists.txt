# %SS_DEPS%\qt\msvc_2017_%SS_PLATFORM%

if(WIN32)
    cmake_minimum_required(VERSION 3.15)
else()
    cmake_minimum_required(VERSION 3.13)
endif()

set(PROJECT_NAME actormodel)
set(CMAKE_CXX_STANDARD 17)
SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_INSTALL_PREFIX)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

include(add_msvc_precompiled_header)
include(configure_msvc_runtime)

find_package(Qt5 REQUIRED Core Network Xml COMPONENTS)
project(${PROJECT_NAME} C CXX)
add_subdirectory(${PROJECT_NAME})
