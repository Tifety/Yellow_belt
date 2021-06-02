cmake_minimum_required(VERSION 3.17)
project(decompose)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(decompose
        bus_manager.cpp
        bus_manager.h
        main.cpp
        query.cpp
        query.h
        responses.cpp
        responses.h)
