#include <stdio.h>
#include <string.h>
#include "estructuras.h"

int main() {
    Estudiante estudiante1;
    strncpy(estudiante1.nombre, "Juan", sizeof(estudiante1.nombre) - 1);
    estudiante1.nombre[sizeof(estudiante1.nombre) - 1] = '\0';
    estudiante1.edad = 20;
    estudiante1.promedio = 9.5;

    printf("Estudiante:\n");
    mostrarEstudiante(&estudiante1);

    return 0;
}