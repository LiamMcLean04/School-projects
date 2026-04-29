cmake_minimum_required(VERSION 4.1)
project(2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2
        DirectedGraph.cpp
        DirectedGraph.h
        driver.cpp
        Edges.cpp
        Edges.h
        Graph.cpp
        Graph.h
        Vertex.cpp
        Vertex.h)
