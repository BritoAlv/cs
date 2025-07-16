cmake_minimum_required(VERSION 3.29)
project(Codes)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Codes
    Dijkstra.cpp
    Dinic.cpp
    Extensions.cpp
    Gauss.cpp
    HashStruct.cpp
    Mex.cpp
    PowComb.cpp
    PrefixSum.cpp
        main.cpp)
