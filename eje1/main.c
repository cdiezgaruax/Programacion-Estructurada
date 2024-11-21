#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiantes.h"

void mostrarMenu() {
    printf("Seleccione una opcion:\n");
    printf("1. Agregar estudiante\n");
    printf("2. Ver estudiantes\n");
    printf("3. Eliminar estudiante\n");
    printf("4. Salir\n");
}

int main() {
    struct Nodo *listaEstudiantes = NULL;
    int opcion;
    char nombre[50];
    int edad;
    float promedio;

    do {
        mostrarMenu();
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            fprintf(stderr, "Entrada no válida\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            continue;
        }
        getchar(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del estudiante: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea
                printf("Ingrese la edad del estudiante: ");
                if (scanf("%d", &edad) != 1) {
                    fprintf(stderr, "Entrada no válida\n");
                    while (getchar() != '\n'); // Limpiar el buffer de entrada
                    continue;
                }
                printf("Ingrese el promedio del estudiante: ");
                if (scanf("%f", &promedio) != 1) {
                    fprintf(stderr, "Entrada no válida\n");
                    while (getchar() != '\n'); // Limpiar el buffer de entrada
                    continue;
                }
                agregarEstudiante(&listaEstudiantes, nombre, edad, promedio);
                break;
            case 2:
                verEstudiantes(listaEstudiantes);
                break;
            case 3:
                printf("Ingrese el nombre del estudiante a eliminar: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea
                eliminarEstudiante(&listaEstudiantes, nombre);
                break;
            case 4:
                liberarLista(&listaEstudiantes);
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}