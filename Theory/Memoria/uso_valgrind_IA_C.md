## Valgrind
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

