#include <stdio.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

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

int main() {
    struct Estudiante estudiante1;
    strncpy(estudiante1.nombre, "Juan", sizeof(estudiante1.nombre) - 1);
    estudiante1.nombre[sizeof(estudiante1.nombre) - 1] = '\0';
    estudiante1.edad = 20;
    estudiante1.promedio = 9.5;

    struct Estudiante estudianteCopia = copiarEstudiante(&estudiante1);

    printf("Estudiante original:\n");
    mostrarEstudiante(&estudiante1);

    printf("Estudiante copia:\n");
    mostrarEstudiante(&estudianteCopia);

    return 0;
}