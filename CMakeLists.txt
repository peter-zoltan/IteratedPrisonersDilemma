cmake_minimum_required(VERSION 3.29)

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_C_COMPILER "gcc" )

project(IteratedPrisonersDilemma)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_compile_definitions(MEMTRACE)

#add_compile_definitions(CPORTA)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_executable(IteratedPrisonersDilemma
        main.cpp
        player.cpp
        player.h
        gameManager.cpp
        gameManager.h
        memtrace.cpp
        memtrace.h
        menu.cpp
        menu.h
        fileManager.cpp
        fileManager.h
        test.cpp
        test.h
        gtest_lite.h
)
