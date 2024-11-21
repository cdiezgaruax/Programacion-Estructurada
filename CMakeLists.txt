cmake_minimum_required(VERSION 3.29)
project(Programacion_Estructurada C)

set(CMAKE_C_STANDARD 11)

include_directories(eje1)

add_executable(eje1
        eje1/estudiantes.c
        eje1/estudiantes.h
        eje1/main.c
        eje1/util.c
        eje1/util.h)

add_executable(eje2
        eje2/main.c
        eje2/uniones.c
        eje2/uniones.h)

add_executable(eje3
        eje3/main.c
        eje3/Copia-de-estructuras.c
        eje3/Copia-de-estructuras.h
)

add_executable(eje4
        eje4/main.c
        eje4/Creacion-de-alias.c
        eje4/Creacion-de-alias.h
)

add_executable(eje5
        eje5/main.c
        eje5/estructuras.c
        eje5/estructuras.h)