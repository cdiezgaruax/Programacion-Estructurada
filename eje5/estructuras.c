#include <stdio.h>
#include <string.h>
#include "estructuras.h"

void mostrarEstudiante(const Estudiante *est) {
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", est->nombre, est->edad, est->promedio);
}