cmake_minimum_required(VERSION 3.23)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_library(func.h func.cpp func.h)

add_subdirectory(googletests)

add_executable(lab5 main.cpp
        func.h
        func.cpp)
