/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:47:16 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/01 17:57:38 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bzero, explicit_bzero - zero a byte string
// The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by
// writing zeros (bytes containing '\0') to that area.

#include "libft.h"

void	ft_bzero(void *s, size_t n){
    unsigned char *pr;
    pr = (unsigned char *)s;
    
    while(n--)
        *pr++='\0';
}

/* int main(void){
    // My own ft_bzero
    unsigned char arr_ft[]="Sobreviviendo a estos 12 dias";
    unsigned char arr[]="Sobreviviendo a estos 12 dias";

    ft_bzero(arr_ft,sizeof(arr_ft));
    printf("%s", arr_ft);
    
    printf("\n");
    
    bzero(arr,sizeof(arr));
    printf("%s", arr);
} */


