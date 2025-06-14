cmake_minimum_required(VERSION 3.29)
project(mtam_hw3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(mtam_hw3
    main.cpp
    Person.cpp
    Person.h
    SortedList.h
    Task.cpp
    Task.h
    TaskManager.h
        Super_ptr.h
        SortedList.cpp
)
