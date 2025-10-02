/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:26:52 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 00:26:01 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Busca la ultimá aparición de un carácter dentro de una cadena de caracteres y devuelve un puntero a la posición
de ese carácter en la cadena, o un puntero nulo si el carácter no se encuentra en la cadena.
*/

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int len_s;
    char *ptr;

    len_s = ft_strlen(s);
    ptr=(char *)s;
    
    if ((unsigned char)c == '\0')
        return &ptr[len_s];

    while (len_s > 0)
    {
        if (ptr[len_s] == (unsigned char)c)
            return &ptr[len_s];
        len_s--;
    }
    return NULL;
}
/* int main(void){

    char s[]="Hola munda";
    char search='a';

    char *ft_ptr=(ft_strrchr(s,search));
    char *ptr=(strrchr(s,search));

    printf("%p\n",ft_ptr);
    printf("%p",ptr);

} */