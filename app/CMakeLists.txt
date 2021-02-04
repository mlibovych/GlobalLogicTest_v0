cmake_minimum_required(VERSION 3.16.2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -pipe -Wall -Wextra -Wpedantic -Wno-unused-parameter")

set(TARGET parent)

set(SOURCES src/main.cpp)

include_directories(inc)

add_executable(${TARGET} ${SOURCES})

set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../../)
