#include <stdio.h>
#include "uniones.h"

int main() {
    union Dato dato;
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
        manejarOpcion(&dato, opcion);
    } while (opcion != 5);

    return 0;
}