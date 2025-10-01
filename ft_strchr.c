/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:52:58 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/30 22:06:00 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
 * Retorna un puntero a la primera ocurrencia del 'c'.
 * En la cadena 's', o NULL si el carácter no se encuentra.
 * El tipo de retorno debe ser 'const char *' para no perder.
 * El calificador de const del argumento de entrada.
 */

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
        {
            return (char *)s;
        }
        s++;
    }

    if ((char)c == '\0')
        return (char *)s;

    return NULL;
}
// int main(void){

//     char s[]="Hola mundo";
//     char search='a';

//     char *ptr=(ft_strchr(s,search));
//     printf("%p",ptr);
// }