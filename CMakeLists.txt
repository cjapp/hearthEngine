project(2dGameEngine)

cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FindPkgConfig)

#Find and include SDL2 directories and libraries
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_MODULE_PATH "${2dGameEngine_SOURCE_DIR}/cmake")
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

add_subdirectory("src")
