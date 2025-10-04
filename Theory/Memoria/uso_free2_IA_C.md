## Free
---
La función `free` se utiliza para desasignar (liberar) un bloque de memoria que fue previamente reservado con funciones de asignación dinámica como `malloc`, `calloc`, o `realloc()`.

Devuelve el bloque de memoria al sistema operativo para que pueda ser reutilizado en futua asignaciones.

### 1. Sintaxis
``void free(void *ptr);``

* `ptr`: Um puntero (de cualquier tipo) que apunta al inicio del bloque de memoria que deseas liberar. Este puntero debe haber sido devuelto por un llamada anterior a `malloc`, `calloc` o `realloc`.

La función `free()` **no devuelve ningún valor** (`void`).
Esta definida en el archivo de cabecera `<stdlib.h>`.
Si el puntero `ptr` es `NULL`, la función `free()`, no hace nada y regresa inmediatamente, lo cual es seguro.

### 2. ¿Por qué usar `free`?
Usar `free()` es obligatoria en C para la asignación dinámica, y la razón principal es evitar las **fugas de memoria(memoria leks)**.

1. **Evitar Fugas de Memoria**: Si asignas memoria dinámicamente (en el heap) y no la liberas cuando ya no la necesitas, esa memoria permanece ocupada por tu programa hasta que finaliza. Si esto ocurre repetidamente, tu programa consumirá cada vez más memoria del sistema, lo que puede provocar que el sistema se quede sin recursos.

2. **Control Manual**
A diferencia de lenguajes con "recolectores de basura" (como Java o Python), C **no tiene un recolector de basura automático**. Por lo tanto, el programador es el responsable director de gestionar y lebrar toda la memoria dinámica, ofreciendo un control preciso sobre cuándo se liberan los recursos.

3. **Eficiencia de Recursos** Garantiza que los recursos de memoria se utilicen de manera eficiente y estén disponibles para otros procesos o para futuros asignaciones dentro de tu propio programa.

### 3. Ejemplos Básicos de Uso de `free()`
#### Ejemplo 1: Puntero simple
```c
#include <stdlib.h>
#include <stdio.h>

int main(){
    int *p_entero=(int *)malloc(sizeof(int)); // 1. Asignar memoria para un entero 

    if(p_entero==NULL){
        prinf("Error: No se pudo asginar memoria\n");
        return 1;
    }
    *p_entero = 42 // Usar la memoria
    printf("Valor: %d\n", *p_memoria);

    free(p_entero);     // 2. Liberar la memoria
    p_entero = NULL     // 3. BUena práctica: Asginar NULL al puntero para evitar *dangling pointers*

    // Intentar acceder a *p_entero después de free es un error de tiempo de ejecución (acceso a memoria liberada).
}
```
##### ¿Cúando Usarlo?
Debes llamar a `free()` inmediatamente después de que hayas terminado de usar el bloque de memoria dinámicamente asginado y ya no necesites acceder a él.
* Al final de un función que usó memoria dinámica (y no la devuelve.)
* Antes de reasginar el puntero a otro bloque de memoria.
* Antes de que el puntero salga de su ámbito o se pierda.

### 4. `free()` para Punteros Múĺtiples (Matrices Dinámicas)
Cuando trabajas con **dobles punteros(**)** o triple punteros(***) para crear estructuras de datos complejas (como matrices o cubos dinámicos), debes liberar la memoria en el orden inverso al que se asignó.

La regla fundamental es: **liberar las "hojas" (datos) primeros, y luego el "tronco" (puntero de punteros)**.

#### Doble Puntero (Matriz Dinámica: `int **matriz`)
Una matriz dinámica se asigna en 2 pasos: primero, las filas(un array de punteros), y luego, cada columna (un array de datos).

##### Orden de Asignación 
1. Columnas (los datos de cada fila).
2 Filas (el puntero de punteros).

##### Orden de Liberación 
1. Columnas (los datos de cada fila) - Bucle
2. Filas (el puntero de putneros) - `free(matriz)`.

```c
// Supongamos que ya asginaste una matrix de 3x4:
// int **matriz = ...

// 1. Liberar los bloques de memoria de las colmnas (el contenido de cada fila)
while(i<3){
    free(matriz[i]);
    matriz[i]=NULL;
    i++;
}

// 2. Liberar el bloque de memoria de las filas (el puntero de punteros).
free(matriz);
matriz=NULL;
```
#### Triple puntero (Cubo Dinámico `int ***cubo`)
Para un cubo dinámico (un truple puntero), el proceso se extiende a tres niveles, liberando desde el nivel más interno al más externo:

1. Liberar el array de datos (***).
2. Liberar el array de punteros a punteros (**).
3. Liberar el puntero de punteros a punteros (*).
```c
// Supongamos un cubo de 3x4x5:
// int ***cubo = ...
// 1. Liberar los bloques de datos y el segundo nivel de punteros (lo más interno)
while(i<3){
    while(j<4){
        free(cubo[i][j]);
        cubo[i][j]=NULL;
        j++;
    }
    free(cubo[i]); // Liberar el array de 4 punteros a enteros (el 'y' de cada 'x') 
    cubo[i]=NULL;
    i++;
    j=0;
}
// 2. Liberar el puntero principal (lo más externo)
free(cubo)
cubo=NULL;
```

#### Función para Automatizar la Liberación (Doble Puntero)
Para evitar la repetición de código y asegurarse la correcta liberación, es una excelente práctica crear una función dedicada para manejar la desasignación de estructuras complejas, como matrices dinámicas:

```c
#include <stdlib.h>
#include <stddef.h> // Para size_t

// Función para liberar una matriz dinámica de enteros (int **)
void liberar_matriz(int **matriz, size_t filas){
    size_t i;

    i=0;
    if(matriz == NULL){
        return; // No hay nada que liberar
    }

    // 1. Liberar cada fila
    while(i<filas){
        free(matriz[i]);
        i++;
    }

    // 2. Liberar el array de punteros a filas
    free(matriz);
}


```