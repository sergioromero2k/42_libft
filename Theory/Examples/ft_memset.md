# Ejemplos memset a, ayudas
---

```c
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = (unsigned char) c;
	return (s);
}
```
- ¿Qué hace `memset`? llena un bloque de memoria con un valor determinado.
```c
char arr[5]
ft_memset(arr,'A',5); // arr = "AAAAAS"
// Aquí, todos los 5 bytes de arr se llenan con 'A'.
```

1. `void *s` 
* Es un puntero generico que apunta al bloque de memoria que quieres llenar.
* Se usa `void *` porque `memset` debe funcionar con cualquier tipo de mmeoria (char, int, structs, etc.).
* `size_t n` cantidad de bytes que quieres llenar.

### Línea por línea
```c
unsigned char *ptr;
```
* Se define un puntero a unsigned char.
* ¿Por qué unsigned char? Porque en C, el tipo más pequeño direccionable es un byte y se quiere manipular memoria byte a byte.
* Usar unsigned char evita problemas con valores negativos (a diferencia de signed char).