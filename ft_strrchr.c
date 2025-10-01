/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:26:52 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/30 22:06:11 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Busca la ultimá aparición de un carácter dentro de una cadena de caracteres y devuelve un puntero a la posición
de ese carácter en la cadena, o un puntero nulo si el carácter no se encuentra en la cadena.
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_len(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

char *ft_strrchr(const char *s, int c)
{
    int len_s;

    len_s = ft_len(s);

    while (len_s > 0)
    {
        if (s[len_s] == (char)c)
            return (char *)s;
        len_s--;
    }
    if ((char)c == '\0')
        return (char *)s;

    return NULL;
}
/* int main(void){

    char s[]="Hola munda";
    char search='a';

    char *ptr=(ft_strrchr(s,search));
    printf("%p",ptr);
} */