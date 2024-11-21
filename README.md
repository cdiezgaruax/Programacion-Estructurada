# Programación Estructurada

[Repositorio en GitHub](https://github.com/cdiezgaruax/Programacion-Estructurada)

## Enunciado

Recuerda que estos ejercicios están diseñados para **C**, no para **C++**, por lo que no incluyen características específicas de C++ como el operador `new` o la programación orientada a objetos.

---

### 1. Estructuras

#### a. Constitución de una estructura

Defina una estructura `Estudiante` que contenga:  
- `nombre` (una cadena de caracteres).  
- `edad` (un entero).  
- `promedio` (un flotante).

#### b. Instanciación de estructuras

Crea una instancia de la estructura `Estudiante` y asigna valores a sus miembros.

#### c. Instanciación con el operador `malloc`

Crea una instancia de la estructura `Estudiante` utilizando la función `malloc`.

#### d. Punteros y estructuras

Crea un puntero a una estructura `Estudiante` e inicialízalo.

#### e. Organización de la programación

Escribe una pequeña aplicación que cree una lista de estudiantes utilizando la estructura `Estudiante`. Deberías ser capaz de añadir, ver y eliminar estudiantes de la lista.

---

### 2. Uniones

Define una unión que pueda almacenar:  
- un entero,  
- un flotante,  
- o una cadena de caracteres.  

Crea una variable de esta unión y asigna diferentes tipos de valores para ver cómo se comporta.

---

### 3. Copia de estructuras

Escribe una función que tome una estructura `Estudiante` y devuelva una copia de la misma.

---

### 4. Creación de alias de tipos de estructuras

Usa `typedef` para crear un alias para la estructura `Estudiante`.

---

### 5. Estructuras y funciones

#### a. Pasar una estructura por valor como argumento

Escribe una función que tome una estructura `Estudiante` por valor y imprima sus miembros.

#### b. Pasar una estructura por referencia como argumento

Modifica la función anterior para que tome una estructura `Estudiante` por referencia.

#### c. Pasar una estructura por dirección como argumento

Modifica la función anterior para que tome una dirección a una estructura `Estudiante`.

#### d. De la programación funcional a la programación orientada a objetos

Aunque es un concepto más de **C++** que de **C**, intenta imaginar cómo podrías organizar el código de la lista de estudiantes en términos de objetos y métodos en lugar de funciones y estructuras.

---

## Propuesta de solución

### 1. Estructuras

#### a. Constitución de una estructura

```c
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};
```

#### b. Instanciación de estructuras

```c
struct Estudiante estudiante1;
strcpy(estudiante1.nombre, "Juan");
estudiante1.edad = 20;
estudiante1.promedio = 9.5;
```

#### c. Instanciación con el operador `malloc`

```c
struct Estudiante *estudiante2 = (struct Estudiante *) malloc(sizeof(struct Estudiante));
strcpy(estudiante2->nombre, "Ana");
estudiante2->edad = 22;
estudiante2->promedio = 9.8;
```

#### d. Punteros y estructuras

```c
struct Estudiante *punteroEst = &estudiante1;
printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", punteroEst->nombre, punteroEst->edad, punteroEst->promedio);
```

---

### 2. Uniones

#### Definición y uso

```c
union Dato {
   int i;
   float f;
   char str[20];
};

union Dato dato;

dato.i = 10;
printf("dato.i: %d\n", dato.i);

dato.f = 220.5;
printf("dato.f: %.2f\n", dato.f);

strcpy(dato.str, "C programming");
printf("dato.str: %s\n", dato.str);
```

*Nota:* El valor de las uniones se sobrescribe, solo se puede acceder a la última asignación.

---

### 3. Copia de estructuras

```c
struct Estudiante copiarEstudiante(struct Estudiante est) {
    struct Estudiante nuevoEst;
    strcpy(nuevoEst.nombre, est.nombre);
    nuevoEst.edad = est.edad;
    nuevoEst.promedio = est.promedio;
    return nuevoEst;
}
```

---

### 4. Creación de alias de tipos de estructuras

```c
typedef struct Estudiante Estudiante;

Estudiante estudiante3;
strcpy(estudiante3.nombre, "Pedro");
estudiante3.edad = 25;
estudiante3.promedio = 9.7;
```

---

### 5. Estructuras y funciones

#### a. Pasar una estructura por valor como argumento

```c
void imprimirEstudiante(Estudiante est) {
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", est.nombre, est.edad, est.promedio);
}
imprimirEstudiante(estudiante1);
```

#### b. Pasar una estructura por referencia como argumento

```c
void modificarEstudiante(Estudiante *est) {
    est->edad = 30;
}
modificarEstudiante(&estudiante1);
```

#### c. Pasar una estructura por dirección como argumento

```c
void imprimirEstudiante2(Estudiante *est) {
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", est->nombre, est->edad, est->promedio);
}
imprimirEstudiante2(&estudiante1);
