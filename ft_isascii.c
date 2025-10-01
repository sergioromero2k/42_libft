/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 23:36:32 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/01 17:48:35 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks whether c is a 7-bit unsigned char value that fits into the ASCII character set.

#include "libft.h"

int ft_isascii(int c){
    if (c >=0 && c<=127)
        return 42;
    return 0;
}


