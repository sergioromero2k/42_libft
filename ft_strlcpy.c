/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:58:29 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/30 22:06:08 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// strlcpy : "String Length Copy"
// strlcpy : "Copiar Longitud de Cadena"
// Devuelve la cantidad de total de la cadena

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t count_src;

    i = 0;
    count_src = 0;

    while (i < size)
    {
        dst[i] = src[i];
        i++;
    }
    *dst = '\0';

    while (src[count_src] != '\0')
        count_src++;

    return count_src;
}

/* int main(void)
{
    char arr1[] = "Hola pepe";
    char arr2[2];

    char ft_arr1[] = "Hola pepe";
    char ft_arr2[2];

    strlcpy(arr2, arr1, sizeof(arr2));
    printf("%ld", strlcpy(arr2, arr1, sizeof(arr2)));
    printf("\n%s", arr2);

    printf("\n");

    ft_strlcpy(ft_arr2,ft_arr1,sizeof(ft_arr2));
    printf("%ld", ft_strlcpy(ft_arr2, ft_arr1, sizeof(ft_arr2)));
    printf("\n%s", ft_arr2);

} */