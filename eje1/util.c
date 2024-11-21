#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void mostrarMenu() {
    printf("Seleccione una opcion:\n");
    printf("1. Agregar estudiante\n");
    printf("2. Ver estudiantes\n");
    printf("3. Eliminar estudiante\n");
    printf("4. Salir\n");
}

void manejarOpcion(int opcion, struct Nodo **listaEstudiantes) {
    char nombre[50];
    int edad;
    float promedio;

    switch (opcion) {
        case 1:
            printf("Ingrese el nombre del estudiante: ");
            fgets(nombre, sizeof(nombre), stdin);
            nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea
            printf("Ingrese la edad del estudiante: ");
            if (scanf("%d", &edad) != 1) {
                fprintf(stderr, "Entrada no válida\n");
                while (getchar() != '\n'); // Limpiar el buffer de entrada
                return;
            }
            printf("Ingrese el promedio del estudiante: ");
            if (scanf("%f", &promedio) != 1) {
                fprintf(stderr, "Entrada no válida\n");
                while (getchar() != '\n'); // Limpiar el buffer de entrada
                return;
            }
            agregarEstudiante(listaEstudiantes, nombre, edad, promedio);
            break;
        case 2:
            verEstudiantes(*listaEstudiantes);
            break;
        case 3:
            printf("Ingrese el nombre del estudiante a eliminar: ");
            fgets(nombre, sizeof(nombre), stdin);
            nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea
            eliminarEstudiante(listaEstudiantes, nombre);
            break;
        case 4:
            liberarLista(listaEstudiantes);
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida. Intente de nuevo.\n");
    }
}

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