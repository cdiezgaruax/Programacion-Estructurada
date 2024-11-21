#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiantes.h"

void agregarEstudiante(struct Nodo **cabeza, const char *nombre, int edad, float promedio) {
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        return;
    }
    strncpy(nuevoNodo->estudiante.nombre, nombre, sizeof(nuevoNodo->estudiante.nombre) - 1);
    nuevoNodo->estudiante.nombre[sizeof(nuevoNodo->estudiante.nombre) - 1] = '\0';
    nuevoNodo->estudiante.edad = edad;
    nuevoNodo->estudiante.promedio = promedio;
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

void verEstudiantes(const struct Nodo *cabeza) {
    const struct Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", actual->estudiante.nombre, actual->estudiante.edad, actual->estudiante.promedio);
        actual = actual->siguiente;
    }
}

void eliminarEstudiante(struct Nodo **cabeza, const char *nombre) {
    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    while (actual != NULL && strcmp(actual->estudiante.nombre, nombre) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Estudiante no encontrado\n");
        return;
    }

    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
}

void liberarLista(struct Nodo **cabeza) {
    struct Nodo *actual = *cabeza;
    struct Nodo *siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    *cabeza = NULL;
}