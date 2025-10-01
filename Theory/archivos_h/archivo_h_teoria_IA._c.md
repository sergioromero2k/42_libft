# Que es un archivo `.h` en C?
---
Un archivo **de cabecera (`.h`)** se usa para declarar funciones, constantes, macros, tipos de datos y variables globales que leugo se definen en un archivo `.c`.

* `.h` = **declaraciones** (qué existe).
* `.c` = **definiciones** (cómo funciona).

De esta forma, separas **la interfaz** (lo que el usuario de tu librería ve) de **la implementación** (cómo está hecha).

### 2. Ventajas de usar `.h`

* **Reutilización**: Escribes funciones una sola vez y las usas en varios programas.
* **Modularidad**: Cada archivo .c tiene un .h asociado.
* **Mantenimiento**: Si cambias algo en la implementación, no afecta a quien solo usa tu librería.
* **Legibilidad**: El .h sirve como "manual" de tu librería.

### 3. Estructura básica de una librería en C
Supongamos que quieres hacer una librería con funciones matemáticas básicas.

**(a) El archivo de cabecera** --> `mimath.h`
```c
#ifndef MIMATH_H        // ifndef → if not defined = si no está definido.
#define MIMATH_H        // define el símbolo (por ejemplo MIMATH_H).

// Declaraciones de funciones (solo firmas)
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
float division(float a, float b);

#endif
```
* `#ifndef ... #define ... #endif` → se llama include `guard` (evita incluir el archivo dos veces).
* Solo ponemos las firmas (prototipos de funciones).
* No se escriben cuerpos de funciones aquí.

**(b) El archivo de implementación** --> `mimath.h`
```c
#include "mimath.h"  // Incluye las declaraciones

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int multiplicacion(int a, int b) {
    return a * b;
}

float division(float a, float b) {
    if (b == 0) return 0; // Evita división entre cero
    return a / b;
}
```
##### Explicación
* Aquí escribimos cómo funcionan las funciones.
* Siempre incluimos el .h correspondiente para mantener consistencia.

**(c) El programa principal que usa la librería** --> `mimath.h`
```c
#include <stdio.h>
#include "mimath.h"  // Usamos comillas para incluir librerías propias

int main() {
    int x = 10, y = 5;

    printf("Suma: %d\n", suma(x, y));
    printf("Resta: %d\n", resta(x, y));
    printf("Multiplicacion: %d\n", multiplicacion(x, y));
    printf("Division: %.2f\n", division(x, y));

    return 0;
}
```

### 4. Cómo compilarlo
Cuando tienes varios archivos (`main.c`, `mimath.c`, `mimath.h`), compilas así:
```bash
gcc main.c mimath.c -o programa
# Y ejecutas:
./programa
```

### 5. ¿Qué es una librería en C?
En C puedes tener dos tipos de librerías:
1. `Estática (.a)` → Se empaqueta el código dentro del ejecutable.
2. `Dinámica (.so en Linux, .dll en Windows)` → Se enlaza en tiempo de ejecución.

Para tu trabajo seguramente basta con manejar la idea de módulos (.c + .h) y compilar varios archivos juntos.