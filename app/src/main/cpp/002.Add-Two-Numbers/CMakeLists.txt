cmake_minimum_required(VERSION 2.8.2)
project(ProjectName)

add_library(sln1 solution1.cpp solution.h)
add_library(sln2 solution2.cpp solution.h)

add_executable(ProjectName1 main.cpp)
add_executable(ProjectName2 main.cpp)

target_link_libraries(ProjectName1 sln1)
target_link_libraries(ProjectName2 sln2)

