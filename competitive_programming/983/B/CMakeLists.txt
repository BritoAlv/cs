cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(checker checker.cpp)
add_executable(ok ok.cpp)
add_executable(test test.cpp)