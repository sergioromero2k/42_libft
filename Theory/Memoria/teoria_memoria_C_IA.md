# La memoria en lenguaje C
---
Cuando corres un programa en C, la memoria del proceso se divide en varias zonas principales:

### 1. Código (text  segment)
* Aquí está el código compilado de tu programa (las instrucciones máquina).
* Normalmente es de solo lectura.

### 2 Datos estáticos/globales
* Variables globales, `static`, constantes.
* Existen durante **toda la ejecución** del programa.

### 3. Heap(montículo)
* Aquí se guarda la **memoria dinámica** que tú reservascon funciones como tú como `malloc`, `calloc`, `realloc()`, y liberas con `free`.
* Crece o decrece en tiempo de ejecución, bajo tu control.

### 4. Stack (pila)
* Aquí se guardan variables locales y las llamadas a funciones.
* Es manejado automáticamente: cuando entras a una función se reservan varibales locales, cuando sales se liberan.
