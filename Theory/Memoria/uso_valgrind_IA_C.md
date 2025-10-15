## Valgrind in C
Es una herramienta muy útil para depurar programas en C (y C++): detecta **fugas de memoria, errores en el uso de memoria, acceso inválidos, doble liberación,**  y más.
A continuación te explico cómo usarlo con ejemplos paso a paso.

### 1. Instalar Valgrind
En sistemas Linux (Ubuntu/Debian):
```bash
sudo apt update
sudo apt install valgrind
```
En Fedora o CentOS
```bash
sudo dnf installl valgrind
```

### 2. Compilar tu programa con símbolos de depuración
Esto ayuda aque Valgrind te diga **en qué línea del código** ocurre el error.
```bash
gcc -g -o mi_programa mi_programa.c
```
* La opción `-g` incluye información de depuración.
* No uses `O2` ni optimizaciones al principio, pueden complicar la lectura de errores.

### 3. Ejecutar el programa con Valgrind
Ejemplo básico
```bash
valgrind ./mi_programa
```
Esto ya muestra información, pero lo más común es usar opciones para análisis detallado de memoria:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./mi_programa
```
##### Explicación:
* `--leak-check=full`: muestra información completa sobre las fugas.
* `--show-leak-kinds=all`: indica todos los tipos de fugas (definitive, indirect, possible, reachable).

### 4. Ejemplo práctico
**Código:** `fuga.c`
```c
#include <stdlib.h>
int main(){
    int *p=malloc(10*sizeof(int)); // Se reserva memoria
    p[0]=42;
    return 0; // No se libera la memoria
}
```
**Compila y ejecuta con Valgrind**
```bash
gcc -g -o fuga fuga.c
valgrind --leak-check=full --show-leak-kinds=all ./fuga
```
**Resultado esperado (resumen)**
```yaml
==12345== HEAP SUMMARY:
==12345==    definitely lost: 40 bytes in 1 blocks
==12345== LEAK SUMMARY:
==12345==    definitely lost: 40 bytes in 1 blocks

Indica que hay una fuga de memoria(la malloc no se liberó).
```
### 5. Solución del error
##### Código corregido
```c
#include <stdlib.h>

int main(){
    int *p = malloc(10*sizeof(int));
    p[0]=42;
    free(p);
    return 0;
}
```
**Ejecutando Valgrind otra vez:**
```yaml
==12346== HEAP SUMMARY:
==12346==    definitely lost: 0 bytes in 0 blocks
==12346== All heap blocks were freed -- no leaks are possible
```

### 6. Detección de accesos inválidos
Ejemplo : `error_mem.c`
```c
#include <stdlib.h>

int main() {
    int *p = malloc(3 * sizeof(int));
    p[3] = 10; // ❌ Acceso fuera de los límites (índices válidos: 0,1,2)
    free(p);
    return 0;
}
```
**Ejecución:**
```bash
valgrind ./error_mem
```
**Ejecutando Valgrind otra vez:**
```yaml
==12347== Invalid write of size 4
==12347==    at 0x10915B: main (error_mem.c:5)
==12347==  Address 0x4a5c044 is 0 bytes after a block of size 12 alloc'd
```
**Valgrind** te dice exactamente dónde y por qué accediste fuera del rango.

### 7. Guardar los resultados en un archivo
```bash
valgrind --leak-check=full --log-file=valgrind.log ./mi_programa
```
Luego puedes revisar `valgrind.log` con calma.

### 8. Resumen de opciones útiles
| Opción                   | Descripción                                             |
| ------------------------ | ------------------------------------------------------- |
| `--leak-check=full`      | Muestra detalles completos de fugas                     |
| `--show-leak-kinds=all`  | Muestra todos los tipos de fugas                        |
| `--track-origins=yes`    | Muestra de dónde provienen los valores no inicializados |
| `--log-file=archivo.log` | Guarda el reporte en un archivo                         |
| `--tool=memcheck`        | Usa el detector de memoria (por defecto)                |

### Consejos
Valgrind **no analiza código estático** (no examina funciones sueltas), sino que observa lo que ocurre en tiempo de ejecución, es decir, **necesita que tu función se ejecute realmente dentro del programa.**
