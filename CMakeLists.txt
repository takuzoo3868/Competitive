cmake_minimum_required(VERSION 3.6)
project(ProjectEuler)

if (WIN64)
    set(CPP_VERSION -std=gnu++14)
else()
    set(CPP_VERSION -std=c++14)
endif()

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/main.cpp
        src/solve.cpp
        src/solution001.cpp src/solution002.cpp src/solution003.cpp src/solution004.cpp src/solution005.cpp)

add_executable(ProjectEuler ${SOURCE_FILES} src/main.h)