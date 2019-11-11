cmake_minimum_required(VERSION 3.10)
project(cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp src/main.cpp src/Graph.cpp src/Graph.h ../generator/Generator.cpp ../generator/Generator.h)
add_executable(generator ../generator/main.cpp ../generator/Generator.cpp ../generator/Generator.h)