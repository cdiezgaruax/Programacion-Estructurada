#ifndef UNIONES_H
#define UNIONES_H

union Dato {
    int i;
    float f;
    char str[20];
};

void mostrarMenu();
void manejarOpcion(union Dato *dato, int opcion);

#endif // UNIONES_H