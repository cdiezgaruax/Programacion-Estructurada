#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

void mostrarEstudiante(const Estudiante *est);

#endif // ESTRUCTURAS_H