#include <stdio.h>
#include "util.h"

int main() {
    struct Nodo *listaEstudiantes = NULL;
    int opcion;

    do {
        mostrarMenu();
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            fprintf(stderr, "Entrada no válida\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            continue;
        }
        getchar(); // Limpiar el buffer de entrada
        manejarOpcion(opcion, &listaEstudiantes);
    } while (opcion != 4);

    return 0;
}