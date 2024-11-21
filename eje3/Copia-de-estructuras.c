#include <stdio.h>
#include <string.h>
#include "Copia-de-estructuras.h"

struct Estudiante copiarEstudiante(const struct Estudiante *est) {
    struct Estudiante nuevoEst;
    strncpy(nuevoEst.nombre, est->nombre, sizeof(nuevoEst.nombre) - 1);
    nuevoEst.nombre[sizeof(nuevoEst.nombre) - 1] = '\0';
    nuevoEst.edad = est->edad;
    nuevoEst.promedio = est->promedio;
    return nuevoEst;
}

void mostrarEstudiante(const struct Estudiante *est) {
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", est->nombre, est->edad, est->promedio);
}

void mostrarMenu() {
    printf("Seleccione una opcion:\n");
    printf("1. Introducir datos del estudiante\n");
    printf("2. Copiar estudiante\n");
    printf("3. Mostrar estudiante original\n");
    printf("4. Mostrar estudiante copia\n");
    printf("5. Salir\n");
}

void manejarOpcion(struct Estudiante *est, struct Estudiante *estCopia, int opcion) {
    switch (opcion) {
        case 1:
            printf("Ingrese el nombre del estudiante: ");
            fgets(est->nombre, sizeof(est->nombre), stdin);
            est->nombre[strcspn(est->nombre, "\n")] = '\0'; // Eliminar el salto de línea
            printf("Ingrese la edad del estudiante: ");
            if (scanf("%d", &est->edad) != 1) {
                fprintf(stderr, "Entrada no valida\n");
                while (getchar() != '\n'); // Limpiar el buffer de entrada
                return;
            }
            printf("Ingrese el promedio del estudiante: ");
            if (scanf("%f", &est->promedio) != 1) {
                fprintf(stderr, "Entrada no valida\n");
                while (getchar() != '\n'); // Limpiar el buffer de entrada
                return;
            }
            getchar(); // Limpiar el buffer de entrada
            break;
        case 2:
            *estCopia = copiarEstudiante(est);
            break;
        case 3:
            printf("Estudiante original:\n");
            mostrarEstudiante(est);
            break;
        case 4:
            printf("Estudiante copia:\n");
            mostrarEstudiante(estCopia);
            break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida. Intente de nuevo.\n");
    }
}

void ejecutar() {
    struct Estudiante estudiante1 = {"", 0, 0.0};
    struct Estudiante estudianteCopia = {"", 0, 0.0};
    int opcion;

    do {
        mostrarMenu();
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            fprintf(stderr, "Entrada no valida\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            continue;
        }
        getchar(); // Limpiar el buffer de entrada
        manejarOpcion(&estudiante1, &estudianteCopia, opcion);
    } while (opcion != 5);
}