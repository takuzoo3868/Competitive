cmake_minimum_required(VERSION 3.6)
project(ProjectEuler)

if (WIN64)
    set(CPP_VERSION -std=gnu++14)
else()
    set(CPP_VERSION -std=c++14)
endif()

set(CMAKE_CXX_STANDARD 14)

# サブディレクトリ内のソースをすべてプロジェクトに入れるマクロ
MACRO(ADD_ALL_SUBDIR result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${curdir}/${child})
            LIST(APPEND dirlist ${child})
            # CMakeがディレクトリにあるか(1のパターン)無いか(2のパターン)で分岐
            IF(EXISTS ${curdir}/${child}/CMakeLists.txt)
                add_subdirectory(${child})
            ELSE()
                aux_source_directory(${child} SOURCE)
            ENDIF()
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()

ADD_ALL_SUBDIR(SUBDIRS ${ProjectEuler_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

IF(SOURCE)
    add_executable(PROJECTEULER ${SOURCE})
ENDIF()