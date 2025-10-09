## Malloc 

### 1. ¿Qué es `malloc`?
`malloc` significa **memory allocation** (asignación de memoria). 
Es una función de la biblioteca estándar de C (`stdlib.h`) que:
* Reserva un bloque de memoria de un tamaño específico en el **heap** (memoria dinámica).
* Devuelve un **puntero** al inicio de ese bloque.
* No inicializa la memoria (los valores son **indeterminados**, basura).

#### Sintaxis
```c
#include <stdlib.h>

void* malloc(size_t size);
```
* `size`: número de bytes que quieres reservar.
* Devuelve un puntero genérico(`void*`), que normalmente se convierte al tipo de dato que deseas.

### 2. Ejemplo básico de uso
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    // Reservamos memoria para 5 enteros
    ptr = (int*) malloc(5 * sizeof(int));

    if (ptr == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Inicializamos y usamos la memoria
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 10;
        printf("%d ", ptr[i]);
    }

    // Liberamos la memoria
    free(ptr);

    return 0;
}
```
**Explicación paso a paso:**
* `malloc(5 * sizeof(int))` reserva espacio suficiente para 5 enteros.
* `(int*)` convierte el puntero genérico a `int *`.
* Siempre verificamos si `malloc` en `NULL` (error al reservar memoria).
* Después de usar la memoria, **liberamos con `free(ptr)`** para evitar fugas de memoria.

### 3. Diferencia entre stack y heap
| Aspecto             | Stack                                | Heap                               |
| ------------------- | ------------------------------------ | ---------------------------------- |
| **Asignación**          | Automática                           | Manual (malloc/calloc)             |
| **Vida de la variable** | Local a la función                   | Hasta que se libera explícitamente |
| **Tamaño**              | Limitado                             | Mayor, solo limitado por RAM       |
| **Inicialización**      | Puede ser automática (ej. `int a=0`) | No inicializada con malloc         |

### 4. Errores comunes con `malloc`

1. **No verificar NULL**
```c
int *ptr = malloc(1000000000 * sizeof(int));
// Si malloc falla, ptr será NULL
```

2. **Fuga de memoria (memory leak)**
Olvidar liberar memoria:
```c
int *ptr = malloc(10 * sizeof(int));
ptr = malloc(20 * sizeof(int)); // Pierdes el puntero al primer bloque
```

3. **Acceso fuera de límites**
```c
int *arr = malloc(5 * sizeof(int));
arr[5] = 10; // ERROR, índice 0-4
```

4. **Usar memoria después de liberar (dangling pointer)**
```c
free(ptr);
ptr[0] = 10; // ERROR
```
### 5. Funciones relacionadas
* `calloc`: similar a malloc, pero inicializa la memoria a cero.
```c
int *arr = (int*) calloc(5, sizeof(int));
```
* `realloc`: cambia el tamaño de un bloque previamente asignado.
```c
int *arr = (int*) calloc(5, sizeof(int));
```
* `free`: libera la memoria asignada.

### 6. Reglas importantes
1. Cada `malloc` **debe tener un** `free` correspondiente.
2. No se puede acceder a memoria fuera del bloque asignado.
3. El tamaño debe ser calculado correctamente: `n * sizeof(tipo)`.
4. Punteros devueltos pueden ser `NULL` si la memoria no se pudo asignar.

