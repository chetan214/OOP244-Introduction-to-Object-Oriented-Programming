cmake_minimum_required(VERSION 3.27)
project(ws3)

set(CMAKE_CXX_STANDARD 17)

add_executable(ws3 main.cpp
        Item.cpp
        Item.h
        Bill.cpp
        Bill.h
        ItemTester.cpp
        main_prof.cpp)
