## Conceptos general: funciones `mem*`
En C, las funciones `mem`... (de memory) trabajan con bloques de memoria sin importar qué contienen:
pueden ser texto, números, estructuras, bytes binarios, etc.

🔹 A diferencia de las funciones `str`... (como `strcpy`, `strlen`, `strchr`),
que paran en el primer `'\0'`, las funciones mem... no consideran `'\0'` como especial — porque operan sobre bytes, no sobre “cadenas terminadas en cero”.

| Función                 | Qué hace                                                     | Ejemplo de uso                      |
| ----------------------- | ------------------------------------------------------------ | ----------------------------------- |
| `memcpy(dest, src, n)`  | Copia **n bytes** desde `src` a `dest`.                      | Copiar un bloque de memoria.        |
| `memmove(dest, src, n)` | Igual que `memcpy`, pero **seguro si las zonas se solapan**. | Mover datos dentro del mismo array. |
| `memset(s, c, n)`       | Rellena **n bytes** de `s` con el valor `c`.                 | Inicializar a 0 un bloque.          |
| `memcmp(a, b, n)`       | Compara los primeros **n bytes** de `a` y `b`.               | Saber si dos bloques son iguales.   |
| `memchr(s, c, n)`       | Busca el primer byte `c` en los primeros `n` bytes.          | Buscar un valor dentro de memoria.  |

### Ejemplo visual
Supón este bloque de memoria:
| Dirección | Contenido (hex) | Caracter |
| --------- | --------------- | -------- |
| 0x1000    | 41              | 'A'      |
| 0x1001    | 00              | '\0'     |
| 0x1002    | 42              | 'B'      |

* `strchr((char*)0x1000, 'B')` → ❌ no llega nunca a 'B' (se detiene en '\0').
* `memchr((void*)0x1000, 'B', 3)` → ✅ la encuentra, porque busca por bytes.