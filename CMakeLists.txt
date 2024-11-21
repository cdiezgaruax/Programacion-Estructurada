cmake_minimum_required(VERSION 3.29)
project(Programacion_Estructurada C)

set(CMAKE_C_STANDARD 11)

include_directories(eje1)

add_executable(eje1
        eje1/estudiantes.c
        eje1/estudiantes.h
        eje1/main.c)

add_executable(eje2
        eje2/main.c)

add_executable(eje3
        eje3/main.c)

add_executable(eje4
        eje4/main.c)

add_executable(eje5
        eje5/main.c)
