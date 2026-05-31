cmake_minimum_required(VERSION 4.2)
project(Multime_TD_LI)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MultimeCMake
        App.cpp
        IteratorMultime.cpp
        IteratorMultime.h
        Multime.cpp
        Multime.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h
        LSI.cpp
        LSI.h
        IteratorLSI.cpp
        IteratorLSI.h)