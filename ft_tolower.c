/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:42:21 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/30 22:05:04 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int tolower(int c)
{
    if (c < 65 && c > 90)
        return c;
    return c + 32;
}

/* int main(void){
    char letter='A';

    printf("%c",tolower(letter));
} */