# Especificadores de formato de printf en C
---

### 1. Sintaxis básica de `printf`
```c
printf("formato", lista_de_valores);
```
* `"formato"` → cadena con especificadores de formato, que indican cómo imprimir cada variable.
* `lista_de_valores` → las variables que quieres imprimir.

Los especificadores siempre empiezan con `%`.

### 2. Especificadores comunes
| Formato | Tipo de dato                    | Ejemplo                                         |
| ------- | ------------------------------- | ----------------------------------------------- |
| `%d`    | `int` (decimal con signo)       | `int x = 5; printf("%d", x);` → `5`             |
| `%i`    | `int` (igual que `%d`)          | Igual que `%d`                                  |
| `%u`    | `unsigned int`                  | `unsigned int x = 5; printf("%u", x);` → `5`    |
| `%f`    | `float` o `double`              | `float y = 3.14; printf("%f", y);` → `3.140000` |
| `%lf`   | `double`                        | Igual que `%f` para `double`                    |
| `%c`    | `char`                          | `char c='A'; printf("%c", c);` → `A`            |
| `%s`    | cadena de caracteres (`char*`)  | `char *s="Hola"; printf("%s", s);` → `Hola`     |
| `%p`    | puntero                         | `int *p; printf("%p", p);` → `0x7ffee...`       |
| `%x`    | entero hexadecimal (minúsculas) | `int a=255; printf("%x", a);` → `ff`            |
| `%X`    | entero hexadecimal (mayúsculas) | Igual que `%x` → `FF`                           |
| `%o`    | entero octal                    | `int a=8; printf("%o", a);` → `10`              |
| `%%`    | imprime el símbolo `%`          | `printf("%%");` → `%`                           |

### 3. Tamaños específicos y modificadores
Para tipos más grandes o específicos
| Modificador | Uso típico          | Ejemplo                                    |
| ----------- | ------------------- | ------------------------------------------ |
| `l`         | long (entero largo) | `long x=1000000; printf("%ld",x);`         |
| `ll`        | long long           | `long long y=123456789; printf("%lld",y);` |
| `z`         | `size_t` (tamaño)   | `size_t n=10; printf("%zu", n);` ✅         |
| `h`         | short               | `short s=5; printf("%hd",s);`              |
| `hh`        | char como entero    | `char c=5; printf("%hhd",c);`              |

---
### Extra
#### `%zu` explicado
* `z` -> indica `size_t`,que es el tipo que usan funciones como `sizeof`, `strlcpy`/`strlcat`, para tamaños.
* `u` -> imprime un **unsigned decimal**.

