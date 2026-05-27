cmake_minimum_required(VERSION 4.2)
project(randomwalk)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 CONFIG REQUIRED)

add_executable(randomwalk main.cpp
        walker.cpp
        walker.h)

target_link_libraries(randomwalk PRIVATE SDL3::SDL3)