### memcpy
* **Función**: Copia un bloque de memoria de un lugar a otro.
* **Prototipo:**
```c
void *memcpy(void *destino, const void *origen, size_t n);
```
##### Parámetros:
* `destino`: puntero al bloque de memoria donde se copiará.
* `origen`: puntero al bloque de memoria que se va a copiar.
* `n`: número de bytes a copiar.

##### Características
* Rápida.
* No garantiza el comportamiento correcto si las áreas de memoria se solapan (overlap).

##### Ejemplo
```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hola Mundo";
    char dest[20];

    memcpy(dest, src, strlen(src) + 1); // +1 para incluir el '\0'

    printf("Destino: %s\n", dest);
    return 0;
}
```
**Salida**
```makefile
Destino: Hola Mundo
```
* En este caso, `memcpy` funciona perfectamente porque `src` y `dest` no se solapan.

### memmove
Es una función de la librería estándar de C definida en `<string.h>`.
Su propósito es copiar un bloque de mmeoria de un lugar a otro, parecido a `memcpy`, pero con una diferencia clave:
**maneja correctamente los casos en que las regiones de memoria origen y destino se superponen**.

#### Prototipo
```c
void *memmove(void *dest, const void *src, size_t n);
```
##### Parámetros
* `dest:` puntero al destino.
* `src:` puntero al origen.
* `n:` número de bytes a copiar.

##### Características:
* Garantiza un comportamiento correcto incluso si las áreas de memoria se solapan.
* Un poco más lenta que memcpy porque internamente puede usar una copia temporal para evitar corrupción de datos.

##### Ejemplo con solapamiento
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "123456789";
    
    // Queremos mover los primeros 5 caracteres 2 posiciones a la derecha
    memmove(str + 2, str, 5);

    printf("Resultado: %s\n", str);
    return 0;
}
```
**Salida**
```makefile
Resultado: 12123456789
```
* Si hubiéramos usado `memcpy(str + 2, str, 5);`, el resultado sería indefinido porque las áreas se solapan.