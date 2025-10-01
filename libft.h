#ifndef LIBFT_H     // Protección contra inclusiones múltiples
#define LIBFT_H     // Es un identificador único que el preprocesador usa para saber si ese archivo ya fue incluido.
                    // En C es conveción escribir los macros (definiciones de preprocesador) en mayúsculas, para distinguirlas de variables, funciones y otros elementos.

// Incluir librerias del sistema                    
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Declaraciones (firma) de funciones
int ft_isalpha(int c);
int ft_isdigit(int c);
int	ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);







#endif

