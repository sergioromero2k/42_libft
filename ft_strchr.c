/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:52:58 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/01 20:04:03 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Retorna un puntero a la primera ocurrencia del 'c'.
 * En la cadena 's', o NULL si el carácter no se encuentra.
 * El tipo de retorno debe ser 'const char *' para no perder.
 * El calificador de const del argumento de entrada.
 */

char	*ft_strchr(const char *s, int c)
{
    if ((unsigned char)c == '\0')
        return (char *)s;
    
    while (*s)
    {
        if (*s == (unsigned char)c)
            return (char *)s;
        s++;
    }
    return NULL;
}
// int main(void){

//     char s[]="Hola mundo";
//     char search='a';

//     char *ptr=(ft_strchr(s,search));
//     printf("%p",ptr);
// }