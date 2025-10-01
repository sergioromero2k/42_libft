/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:44:19 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/01 18:00:35 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memcpy - copy memory area
// Standard C library (libc, -lc)
// Copia un bloque de memoria de ubicación de origen
// ¿Cuando hay solapamiento? Cuando el bugger de origen es menor que el buffer de destino.

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *des;

    if (dest == NULL && src == NULL)
        return NULL;

    des = (unsigned char *)dest;
    while (n--)
        *des++ = *((unsigned const char *)src++);
    return dest;
}

/* int main(void){
    char origin[]="Hola pepe";
    char destiny[100];

    char ft_origin[]="Hola pepe";
    char ft_destiny[150];

    // The truth
    memcpy(destiny,origin,strlen(origin)+1);
    printf("%s",destiny);
    printf("\n");

    // The false
    ft_memcpy(ft_destiny,ft_origin,strlen(ft_origin)+1);
    printf("%s",ft_destiny);
} */

// int main(void){
//     char str[] ="Hola mundo";
//     ft_memcpy(str+7,str,5);
//     printf("%s",str);
// }
// stack smashing detected ***: terminated
// [1]    38227 IOT instruction (core dumped)  ./ft_memcpy