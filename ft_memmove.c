/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:58:35 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/30 18:58:05 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copy memory area
// Function copies n bytes from memory area src to memory area dest. The memory areas may overlap: copying takes
// Returns a pointer to dest.
// Pendiente

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/* void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *ft_dest;
    const unsigned char *ft_src;
    
    size_t i;

    if (!src && !dest) // Verify
        return 0;

    if (src < dest)
    {
        i=n;
        while (i--)
            *ft_dest++ = *ft_src++;
    }
    else{
        i=0;
        while(i<n)
        {
            ft_dest[i]=ft_src[i];
            i++;
        }
    }
    return dest;
} */

#include <stdio.h>
#include <string.h> // Incluir string.h para usar memmove

int main() {
    char buffer[] = "holajosenose"; // Buffer original
    printf("Buffer original: %s\n", buffer);

    memmove(buffer + 1, buffer + 2, 4); // Mover 4 bytes desde 'cdef' a 'bcde'

    printf("Buffer después de memmove: %s\n", buffer); // Salida esperada: "abcdcdefg"

    return 0;
}


    // printf("%s\n",ft_buffer);


