cmake_minimum_required(VERSION 3.16)

set(This googletest)

set(Sources test.cpp)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
        gtest
        pthread
        lib.h)
