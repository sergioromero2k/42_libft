### Etapas de compilación en C
---
Cuando compilas un archivo `.c`, normalmente pasa por tres etapas:

1. **Preprocesado**
* El preprocesador (`cpp`) reemplaza directivas como `#include`, `#define`, `#ifdef`, etc
* **Resultado**: un archivo .i (no siempre se guarda, pero existe internamente).

2. **Compilación**
* El compilador (`cc` o `gcc`) traduce el código C en **código ensamblador** de la máquina.
* Luego lo convierte en `código objeto (.o)`, que es código binario pero sin enlazar.
* Cada .o corresponde a un archivo .c.

3. **Enlazado (linking)**
* El linker (`ld`) combina todos los `.o` y las librerías necesarias en un ejecutable final (por ejemplo, programa o `a.out`).

### Por qué se genera un .o
---
* El archivo .o es un “bloque intermedio” de código compilado.
* Contiene instrucciones de máquina pero no está completo, porque aún no se han unido otros módulos ni librerías.


Esto permite:
* Compilar cada archivo por separado (muy útil en proyectos grandes).
* Recompilar solo lo que cambió, sin recompilar todo.