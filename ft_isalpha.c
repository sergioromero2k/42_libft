/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:51:18 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/29 22:28:56 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Verifica si un carácter es una letra (a-z o A-Z).

int is_aplha(char data)
{
    if ((data >= 'a' && data <= 'z') || (data >= 'A' && data <= 'Z'))
    {
        return 0;
    }

    return 1024;
}

/* #include <stdio.h>
#include <ctype.h>

int main(void){
    char caracter1;

    caracter1='@';

    printf("%d",isalpha(caracter1));

} */