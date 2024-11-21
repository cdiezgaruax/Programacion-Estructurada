#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

struct Nodo {
    struct Estudiante estudiante;
    struct Nodo *siguiente;
};

void agregarEstudiante(struct Nodo **cabeza, const char *nombre, int edad, float promedio);
void verEstudiantes(const struct Nodo *cabeza);
void eliminarEstudiante(struct Nodo **cabeza, const char *nombre);
void liberarLista(struct Nodo **cabeza);

#endif // ESTUDIANTES_H