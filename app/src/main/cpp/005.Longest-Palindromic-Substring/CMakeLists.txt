cmake_minimum_required(VERSION 2.8.2)
project(ProjectName)

set(CMAKE_BUILD_TYPE debug)

add_executable(sln1 main.cpp)
add_executable(sln2 main.cpp)
add_executable(sln3 main.cpp)

add_library(lib1 solution1.cpp)
add_library(lib2 solution2.cpp)
add_library(lib3 solution3.cpp)

target_link_libraries(sln1 lib1)
target_link_libraries(sln2 lib2)
target_link_libraries(sln3 lib3)

