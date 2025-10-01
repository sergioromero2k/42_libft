/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:31:49 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/30 22:05:19 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks for a digit (0 through 9).
// #include <stdio.h>
// #include <unistd.h>
// #include <ctype.h>

int ft_isdigit(char number)
{
    if (number > '0' && number < '9')
    {
        return 0;
    }
    return 1024;
}

/* int main(void){

} */