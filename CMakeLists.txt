cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

project(zestawB)

file(GLOB zestawB_src
        "src/*.h"
        "src/*.cpp"
        )

add_executable(zestawB ${zestawB_src})