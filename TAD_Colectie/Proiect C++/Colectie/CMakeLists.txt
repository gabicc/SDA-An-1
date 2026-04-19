cmake_minimum_required(VERSION 4.2)
project(Colectie)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ColectieCMake
        App.cpp
        Colectie.cpp
        Colectie.h
        IteratorColectie.cpp
        IteratorColectie.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
