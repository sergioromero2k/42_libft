## Malloc en C
---
`malloc` (**memory allocation**) reserva un bloque de memoria en el **heap** y devuelve un puntero al inicio de ese bloque.

### Sintaxis
```c
#include <stdlib.h>

void* malloc(size_t size);
```
* `size`: número de **bytes** que quieres reservar.
* Retorna: un **puntero** `void*` (que normalmente conviertes al tipo de dato que necesitas).
* Si no puede reservar memoria - devuelve `NULL`.

### Ejmeplo
Reservar memoria para un **entero**

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p=(int *) malloc(sizeof(int));
    if (p == NULL){
        printf("Error: no se pudo asignar memoria. \n");
        return 1;
    }
    *p = 42; // Uso de memoria reservada
    printf("Valor guardado: %d\n", *p)

    free(p); // liberar la memoria
    return 0;
}
```
