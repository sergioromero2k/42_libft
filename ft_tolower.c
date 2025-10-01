/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:42:21 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/01 18:53:05 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
    if (c < 65 && c > 90) // Esto era probar
        return c;
    return c + 32;
}

/* int main(void){
    char letter='A';

    printf("%c",tolower(letter));
} */