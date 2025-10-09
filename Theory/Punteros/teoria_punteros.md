## Los punteros
---

### 1. Historia y motivación de los punteros
C surgió a principios de los 70, diseñado por Dennies Ritchie en los laboratorios Bell. 
Los punteros surgieron por varias razones:

* **Acceso directo a memoria:** C necesitaba permitir al programador manipular memoria de manera eficiente. Antes de C, lenguajes como Fortran o COBOL no daban tanto control sobre la memoria.
* **Eficiencia:** Pasar grandes estructuras de datos (como arrays o structs) por valor consume tiempo y memoria. Con punteros, solo pasas la dirección.
* **Manipulación de datos dinámicos:** Permiten manejar memoria dinámica, listas enlazadas, árboles, etc.
* **Interacción con hardware:** En programación de sistemas o drivers, necesitas direcciones de memoria exactas.
Los punteros permiten control, eficiencia y flexibilidad.

### 2. ¿Qués es un puntero?
Un puntero es una variable que almacena la dirección de memoria de otra variable.
```c
#include <stdio.h>

int main() {
    int x = 10;
    int *p;  // p es un puntero a entero
    p = &x;  // &x obtiene la dirección de memoria de x

    printf("Valor de x: %d\n", x);
    printf("Dirección de x: %p\n", &x);
    printf("Valor de p (dirección almacenada): %p\n", p);
    printf("Valor al que apunta p: %d\n", *p); // *p es "desreferenciar"
}
```
* Salida esperada
```ymal
Valor de x: 10
Dirección de x: 0x7ffda2c3...
Valor de p: 0x7ffda2c3...
Valor al que apunta p: 10
```
* `*p` -> acceder al valor almacenado en la dirección a la que apunta.
* `&x` -> obtener la dirección de la variable.

### 3. ¿Cuándo se necesita un puntero?
* **Pasar argumentos por referencia:** Si quieres que una función modifique la variable original.
* **Arrays dinámicos o memoria dinámica:** Con malloc, calloc, realloc.
* **Estructuras complejas:** Listas enlazadas, árboles, grafos.
* **Optimización:** Evitar copiar grandes estructuras de datos.

```c
// Ejemplo: pasar por referencia
#include <stdio.h>

void incrementar(int *num) {
    *num += 1;
}

int main() {
    int a = 5;
    incrementar(&a);
    printf("a = %d\n", a); // a = 6
}
```
### 4. Punteros y arrays
En C, un array y un puntero están íntimamente relacionados:
```c
int arr[3] = {1,2,3};
int *p = arr;  // el nombre del array es un puntero a su primer elemento

printf("%d\n", arr[0]); // 1
printf("%d\n", *(p+0)); // 1
printf("%d\n", *(p+1)); // 2
```
* `arr` → dirección del primer elemento.
* `p + i` → apunta al elemento i.
* Es común definir punteros cuando quieres recorrer o manipular arrays dinámicos.

### 5. Punteros a punteros (doble puntero)
Un `doble puntero` (`int **pp`) es un puntero que apunta a otro puntero.

Se usa como:
* Necesitas modificar un puntero dentro de una función.
* Trabajas con arrays de punteros (como matrices de strings).

##### Ejemplo: doble puntero
```c
#include <stdio.h>

void cambiar_puntero(int **pp) {
    static int y = 20;
    *pp = &y; // cambia la dirección a la que apunta el puntero
}

int main() {
    int x = 10;
    int *p = &x;

    printf("Antes: %d\n", *p); // 10
    cambiar_puntero(&p);
    printf("Después: %d\n", *p); // 20
}
```

##### Ejemplo real: array de strings
```c
char *nombres[] = {"Ana", "Luis", "Juan"};
char **ptr = nombres;

for(int i=0; i<3; i++){
    printf("%s\n", ptr[i]);
}
```
Aquí:
* `nombres` es un array de putneros a `char`.
* `ptr` es un puntero a puntero, útil para recorrer arrays dinásmicos de strings.

### 6. Diferencia entre puntero y array
| Concepto   | Array                                                 | Puntero                            |
| ---------- | ----------------------------------------------------- | ---------------------------------- |
| Definición | Bloque de memoria contigua                            | Variable que almacena dirección    |
| Tamaño     | Fijo en tiempo de compilación (para arrays estáticos) | Puede cambiar (punteros dinámicos) |
| Sintaxis   | `int arr[10];`                                        | `int *p = malloc(10*sizeof(int));` |
| Acceso     | `arr[i]`                                              | `*(p+i)` o `p[i]`                  |

* `Definir array`: cuando conoces tamaño y no necesitas mover la memoria.
* `Definir puntero`: cuando quieres flexibilidad, tamaño dinámico, o pasar por referencia.

