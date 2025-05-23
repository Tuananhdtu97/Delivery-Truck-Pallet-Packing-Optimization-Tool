cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        data.cpp
        data.h
        approximation.h
        approximation.cpp
        bruteforce.cpp
        bruteforce.h
        ilp.cpp
        ilp.h)

add_compile_definitions(SOURCE_DIR="${CMAKE_SOURCE_DIR}")
