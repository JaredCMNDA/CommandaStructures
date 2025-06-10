cmake_minimum_required(VERSION 3.31)
project(CommandaStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(CommandaStructures src/main.cpp)
target_include_directories(CommandaStructures PRIVATE include)
