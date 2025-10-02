### 1. Memoria estática (Stack, pila)

#### Qué es:
* Se reserva en tiempo de compilación o al entrar a una función.
* La memoria se libera automáticamente cuando la variable sale del alcance (scope).
* No requiere `malloc` ni `free`.

### Características
| Característica | Detalle                                                                      |
| -------------- | ---------------------------------------------------------------------------- |
| Tiempo de vida | Hasta que la función termina o el programa termina (para variables globales) |
| Ubicación      | Stack / Segmento de datos (para globales)                                    |
| Inicialización | Automática para globales estáticas; local depende del tipo                   |
| Tamaño         | Debe conocerse en tiempo de compilación                                      |
| Liberación     | Automática al salir del scope                                                |

#### Ejemplo
```c
#include <stdio.h>

int main() {
    int a = 5;          // variable local, stack
    int arr[10];        // arreglo de tamaño fijo, stack

    printf("%d\n", a);
    return 0;           // al salir, memoria se libera automáticamente
}
```

### 2. Memoria dinámica (Heap/montón)
### Qué es:
* Se reserva **en tiempo de ejecución** usando `malloc`, `calloc`, o `realloc`.
* La memoria no se libera automáticamente; hay usar `free`.
* Útil cuando **no conoces el tamaño de antemano** o quieres que la memoria dure más allá de la función.

### Características
| Característica | Detalle                                       |
| -------------- | --------------------------------------------- |
| Tiempo de vida | Hasta que se libera explícitamente con `free` |
| Ubicación      | Heap                                          |
| Inicialización | Indeterminada (`malloc`), cero (`calloc`)     |
| Tamaño         | Puede ser determinado en tiempo de ejecución  |
| Liberación     | Manual con `free`                             |

#### Ejemplo
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(5 * sizeof(int)); // memoria dinámica

    if (ptr == NULL) {
        return 1; // error al reservar memoria
    }

    for (int i = 0; i < 5; i++)
        ptr[i] = i*10;

    free(ptr); // liberar memoria
    return 0;
}
```

### 3. Diferencias clave entre estática y dinámica
| Aspecto        | Memoria estática           | Memoria dinámica                             |
| -------------- | -------------------------- | -------------------------------------------- |
| Tiempo de vida | Limitado al scope          | Hasta que se llama `free`                    |
| Tamaño         | Fijo en compilación        | Variable en tiempo de ejecución              |
| Liberación     | Automática                 | Manual (`free`)                              |
| Ubicación      | Stack                      | Heap                                         |
| Inicialización | Automática (local depende) | No inicializada (`malloc`) o cero (`calloc`) |
