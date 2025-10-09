## free
### 1. ¿Qué pasa `free(ptr)`?
`free(ptr)` **libera la memoria previamente reservada con** `malloc`, `calloc`o `realloc`.
* **No borra los valores "físicamente"** en memoria, los datos pueden seguir ahí temporalmente, pero el sistema operativo ahora puede **reutilizar esa memoria** para otros fines.
* Después de llamar a `free`, el puntero sigue apuntando a la dirección antigua, pero ese puntero se vuelve `dangling` (colgante).
* Por eso es recomendable hacer:
```c
free(ptr);
ptr = NULL; // Evita usar memoria liberada
```
### 2. ¿Qué pasa si no usas `free`?
Si olvidas liberar la memoria:

1. **Memory leak (fuga de memoria):**

* El bloque reservado sigue consumiendo memoria en el heap.
* Si tu programa corre poco tiempo y la memoria es pequeña, puede que no notes nada.
* Pero si el programa corre mucho tiempo o reserva muchos bloques sin liberar, la memoria del sistema se va agotando.

2. **Consecuencias:**
* Programas lentos.
* Crash por falta de memoria.
* Sistemas embebidos o servidores pueden fallar seriamente.

```c
// Ejemplo de fuga de memoria:
#include <stdlib.h>

int main() {
    for(int i = 0; i < 1000000; i++) {
        int *ptr = malloc(1000 * sizeof(int));
        // free(ptr); // Si no liberamos, vamos acumulando memoria
    }
    return 0;
}
```
* Este programa consume cada vez más RAM y puede colapsar tu sistema.