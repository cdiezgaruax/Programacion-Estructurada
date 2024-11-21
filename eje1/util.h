//
// Created by carlo on 21/11/2024.
#ifndef UTIL_H
#define UTIL_H

struct Nodo {
    struct Estudiante {
        char nombre[50];
        int edad;
        float promedio;
    } estudiante;
    struct Nodo *siguiente;
};

void mostrarMenu();
void manejarOpcion(int opcion, struct Nodo **listaEstudiantes);
void agregarEstudiante(struct Nodo **cabeza, const char *nombre, int edad, float promedio);
void verEstudiantes(const struct Nodo *cabeza);
void eliminarEstudiante(struct Nodo **cabeza, const char *nombre);
void liberarLista(struct Nodo **cabeza);

#endif // UTIL_H