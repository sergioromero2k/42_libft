/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:36:16 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/29 23:36:06 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks for an alphanumeric character; it is equivalent to (isalpha(c) || isdigit(c)).
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int ft_isalnum(char character){
    if ((character >= 'a' && character <= 'z') || (character >='A' && character<='Z')){
        return 1024;
    }else if (character >= '0' && character <='9'){
        return 1024;
    }
    return 0;
}

/* int main(void){
    
} */