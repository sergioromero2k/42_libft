# Estructuras C
---
Una estructura es un **tipo de dato compuesto** que te permite agrupar diferentes variables bajo un mismo nombre.
* Cada variable dentro de la estructura se llama **miembro o campo**.
* Los campos pueden ser de distinto tipos: `int`, `float`. `char[]`, otras estructuras, punteros, etc.
### Ventaja
* Puedes manejar información relacionada como un solo bloque, en lugar de varias variables sueltas.
```c
#include <stdio.h>

struct Persona {
    char nombre[50];
    int edad;
    float altura;
};

int main(){
    struct Persona p1;

    // Asignación de valores
    p1.edad = 25;
    p1.altura = 1.75;
    snprintf(p1.nombre, 50,"Juan");

    // Acceso a campos
    printf("Nombre: %s\nEdad: %d\nAltura: %.2f\n", p1.nombre, p1.edad, p1.altura);
    return 0;
}
```
```makefile
Nombre: Juan
Edad: 25
Altura: 1.75
```
### Declaración y tipos de acceso
#### 1. Declaración de la estructura
```c
struct NombreStruct {
    tipo campo1;
    tipo campo2;
    ...
};
```
#### 2. Definición de variables
```c
struct NOmbreStruct variable1;
struct NombreStruct variable2;
```

#### 3. Acceso a miembros
* Si tienes **variable directa**: `variable.campo`
* Si tienes **un puntero a la estructura**: `puntero->campo`
```c
struct Persona p;
struct Persona *ptr = &p;

p.edad = 30;       // acceso directo
ptr->edad = 30;    // acceso por puntero
```

### Tipos avanzados
#### Array de estructuras
```c
struct Persona lista[10]; // 10 personas
lista[0].edad = 20;
```
#### Estructura anidada
```c
struct Fecha {
    int dia, mes, anio;
};

struct Evento {
    char nombre[50];
    struct Fecha fecha;
};
```
#### Typedef para no escribir struct siempre
```c
typedef struct Persona {
    char nombre[50];
    int edad;
} Persona;

Persona p; // ya no necesitas poner `struct`
```




