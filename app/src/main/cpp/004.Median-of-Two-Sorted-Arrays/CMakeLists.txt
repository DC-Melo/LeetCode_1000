cmake_minimum_required(VERSION 2.8.2)
project(ProjectName)

set(CMAKE_BUILD_TYPE debug)

add_library(lib1 solution1.cpp)

add_executable(sln1 main.cpp)

target_link_libraries(sln1 lib1)

