cmake_minimum_required(VERSION 2.8.2)
# project(Two-Sum)

SET(CMAKE_BUILD_TYPE Debug)

add_library(solution1 solution1.cpp)
add_library(solution2 solution2.cpp)

add_executable(Two-Sum1 main.cpp)
add_executable(Two-Sum2 main.cpp)

target_link_libraries(Two-Sum1 solution1)
target_link_libraries(Two-Sum2 solution2)

