#ifndef CREACION_DE_ALIAS_H
#define CREACION_DE_ALIAS_H

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

void mostrarEstudiante(const Estudiante *est);
void ejecutar();

#endif // CREACION_DE_ALIAS_H