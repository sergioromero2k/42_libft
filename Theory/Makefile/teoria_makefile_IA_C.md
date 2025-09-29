# MakeFile
---
Un Makefile es un archivo que define un conjunto de reglas para compilar y enlazar programas. Es muy útil en proyectos grandes para automatizar el proceso de construcción.

```makefile
# Comentarios
TARGET = nombre_del_programa
CC = gcc
CFLAGS = -Wall -g

# Archivos fuente
SRCS = archivo1.c archivo2.c
OBJS = $(SRCS:.c=.o)

# Regla principal
$(TARGET): $(OBJS) $(CC) $(OBJS) -o $(TARGET)

# Regla para compilar archivos .c a .o
%.o: %.c $(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)
```
### Componentes Clave
* **TARGET**: El nombre del programa a generar.
* **CC**: El compilador (por ejemplo, gcc).
* **CFLAGS**: Opciones de compilación (como -Wall para mostrar advertencias).
* **SRCS**: Lista de archivos fuente.
* **OBJS**: Archivos objeto generados a partir de los archivos fuente.
* **Reglas**: Definen cómo construir el objetivo a partir de sus dependencias.

### Comandos Comunes
* **make:** Compila el programa según el Makefile.
* **make clean:** Elimina los archivos objeto y el ejecutable.
