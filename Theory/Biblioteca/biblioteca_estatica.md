### Biblioteca estática
---
* Una biblioteca estática es un archivo que contiene código objeto compilado (`.o`) que puede ser enlazado a un programa.
* Extensión habitual: `.a` en Linux/macOS.
* Al enlazar un programa con una biblioteca estática, el código de la biblioteca se **copia dentro del ejecutable final**

#### Ventajas
* No necesitas distribuir los `.c` o `.o` junto con el ejecutable.
* Una vez enlazado, el programa no depende de archivos externos.

#### Desventajas:
* El ejecutable es más grande porque contiene todo el código de la biblioteca.
* Si la biblioteca cambia, necesitas recompilar el ejecutable.

### Flujo para crear una biblioteca estática
- Supongamos que tienes archivos fuente:
```bash
foo.c
bar.c
```

#### Paso 1: Compilar a objetos
```bash
cc -c foo.c -o foo.o
cc -c bar.c -o bar.o
```
* `-c` → compila pero no enlaza, produce .o.

#### Paso 2: Crear la biblioteca estática con ar
```bash
ar rcs libmylib.a foo.o bar.o
```
* ar → “archiver”, crea bibliotecas estáticas.

Opciones:
* `r` → reemplaza o agrega archivos en el archivo .a.
* `c` → crea el archivo si no existe.
* `s` → genera un índice para enlazado más rápido.
Resultado: `libmylib.a` contiene `foo.o` y `bar.o`

#### Paso 3: Usar la biblioteca en un programa
Supongamos un main.c que usa funciones de `foo.c`y `bar.c`:

```bash
cc main.c -L. -lmylib -o myprog
```
* `-L.` → busca librerías en el directorio actual.
* `-lmylib` → enlaza con libmylib.a (lib + mylib + .a).

**Nota**: siempre se pone el prefijo `lib` en la biblioteca (`libmylib.a`) y luego solo se pasa `-lmylib `al enlazar.

#### Paso 4: Flujo completo en Makefile
```makefile
NAME = myprog
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c foo.c bar.c
OBJ = $(SRC:.c=.o)
LIB = libmylib.a

.PHONY: all clean fclean

all: $(NAME)

$(LIB): foo.o bar.o
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): main.o $(LIB)
	$(CC) $(CFLAGS) main.o -L. -lmylib -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(LIB)
```
* Primero se crean los .o de foo y bar.
* Luego ar rcs libmylib.a crea la biblioteca estática.
* Finalmente, main.o se enlaza con -lmylib para generar el ejecutable.
