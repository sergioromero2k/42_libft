## Valgrind

Es una herramienta de depuración y análisis de memoria que se utiliza principalmente en programas escritos en C y C++. Su objetivo es ayudarte a encontrar errores relacionados con el manejo de memoria y también a medir el rendimiento de tus programas.

#### ¿Qué hace Valgrind?
Valgrind en realidad es un framework que contiene varias herramientas. 
Las más conocida es **Memcheck**, que sirve para detectas:
* **Fugas de memoria** (memory leaks): memoria reservada con `malloc` o `new` que nunca se libera.
* **Lectura/esctrituras inválidas:** cuando accedes a memoria fuera de los límites de un array o a memoria ya liberada.
* **Uso de variables no inicializadas.**
* **Errores en la getión de punteros.**
Otras herramientas de Valgrind permiten hacer **profiling de rendimiento** o análisis de threads.

#### Instalación
En linux normalmente se instala así:
```bash
sudo apt-get install valgrind   # Debian/Ubuntu
sudo dnf install valgrind       # Fedora
sudo pacman -S valgrind         # Arch
```

#### Uso básico
Supongamos que tienes un programa compilado en C llamado `programa`.
```c
valgrind ./programa
```
Eso ejecuta el programa bajo Memcheck(la herramienta por defecto). Verás un reporte en consola con los posibles errores de memoria.

Si quieres reportes más detallados
```bash
valgrind  --leak-check=full ./programa
```
Con más opciones:
* `--show-leak-kinds=all`: muestra todos los tipos de fugas de memoria.
* `--track-origins=yes`: muestra de dónde vienen las variables no inicializadas (útil, pero hace más lento el análisis).
* `--verbose`: más información.
Ejemplo completo:
```bash
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./programa
```
##### Interpretando la salida
Un ejemplo de salida típica:
```bash
==1234== Memcheck, a memory error detector
==1234== Invalid read of size 4
==1234==    at 0x4005D3: main (main.c:10)
==1234==  Address 0x51fc040 is 0 bytes after a block of size 40 alloc'd
==1234==    at 0x4C2FB55: malloc (vg_replace_malloc.c:299)
==1234==    by 0x4005A6: main (main.c:8)
```
* Esto te dice que en la línea 10 de `main.c` estás leyendo fuera de los límites de la memoria que reservaste.
* Al final del programa, Valgrind suele mostrar un resumen de memoria perdida (fugas de memoria).

#### Buenas prácticas al usar Valgrind

1. Compila con símbolos de depuración: `gcc -g programa.c -o programa`
    Así Valgrind puede mostrarte en qué línea ocurre el error.
2. **No lo uses para medir tiempos de ejecución directamente:** Valgrind ralentiza mucho el programa.
3. **Úsalo durante desarrollo y pruebas** para asegurarte de que tu programa no tiene fugas ni errores de memoria.