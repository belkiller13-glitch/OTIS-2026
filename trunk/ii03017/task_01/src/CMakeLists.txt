cmake_minimum_required(VERSION 3.15)

project(OTIS_Task_01_Variant_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(otis_task_01
    main.cpp
    Model1_3.cpp
    Model2_5.cpp
    Model3_7.cpp
    InputSignal.cpp
)

target_include_directories(otis_task_01 PRIVATE src)
