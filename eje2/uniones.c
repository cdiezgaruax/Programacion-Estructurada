#include <stdio.h>
#include <string.h>
#include "uniones.h"

void mostrarMenu() {
    printf("Seleccione una opcion:\n");
    printf("1. Asignar entero\n");
    printf("2. Asignar flotante\n");
    printf("3. Asignar cadena\n");
    printf("4. Ver valor\n");
    printf("5. Salir\n");
}

void manejarOpcion(union Dato *dato, int opcion) {
    int entero;
    float flotante;
    char cadena[20];

    switch (opcion) {
        case 1:
            printf("Ingrese un entero: ");
            if (scanf("%d", &entero) != 1) {
                fprintf(stderr, "Entrada no valida\n");
                while (getchar() != '\n'); // Limpiar el buffer de entrada
                return;
            }
            dato->i = entero;
            break;
        case 2:
            printf("Ingrese un flotante: ");
            if (scanf("%f", &flotante) != 1) {
                fprintf(stderr, "Entrada no valida\n");
                while (getchar() != '\n'); // Limpiar el buffer de entrada
                return;
            }
            dato->f = flotante;
            break;
        case 3:
            printf("Ingrese una cadena: ");
            fgets(cadena, sizeof(cadena), stdin);
            cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el salto de línea
            strcpy(dato->str, cadena);
            break;
        case 4:
            printf("Valor actual:\n");
            printf("Entero: %d\n", dato->i);
            printf("Flotante: %.2f\n", dato->f);
            printf("Cadena: %s\n", dato->str);
            break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida. Intente de nuevo.\n");
    }
}