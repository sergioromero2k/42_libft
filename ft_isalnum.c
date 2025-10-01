/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:36:16 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/01 17:44:06 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks for an alphanumeric character; it is equivalent to (isalpha(c) || isdigit(c)).

#include "libft.h"

int	ft_isalnum(int c){

    if(ft_isalpha(c) || ft_isdigit(c))
        return 42;
    return 0;
}
/* int main(void){
    
} */