cmake_minimum_required(VERSION 3.16)
project(laba-3)

set(This laba-3)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

set(Header lib.h)
set(Sources lib.cpp)

add_library(lib.h STATIC ${Sources} ${Headers})

add_subdirectory(GoogleTest)

add_executable(main main.cpp lib.cpp lib.h)

