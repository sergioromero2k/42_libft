/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 23:36:32 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/29 23:46:54 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks whether c is a 7-bit unsigned char value that fits into the ASCII character set.
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int ft_isascii(char character){
    if (character >=0 && character<=127){
        return 42;
    }
    return 0;
}

