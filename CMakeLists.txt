cmake_minimum_required(VERSION 3.16.2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Wpedantic -Wno-unused-parameter")

set(CMAKE_CXX_EXTENSIONS OFF)

set(TARGET Parent)

project(${TARGET} LANGUAGES CXX)

add_subdirectory(app)
