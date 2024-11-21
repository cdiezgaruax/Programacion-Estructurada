#ifndef COPIA_DE_ESTRUCTURAS_H
#define COPIA_DE_ESTRUCTURAS_H

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

struct Estudiante copiarEstudiante(const struct Estudiante *est);
void mostrarEstudiante(const struct Estudiante *est);
void manejarOpcion(struct Estudiante *est, struct Estudiante *estCopia, int opcion);
void mostrarMenu();
void ejecutar();

#endif // COPIA_DE_ESTRUCTURAS_H