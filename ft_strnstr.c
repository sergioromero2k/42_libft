/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:57:39 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/01 11:57:57 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h> // Librería necesaria para strstr

// locate a substring in a string
/* 
* Busca una subcadena dentro de una cadena principal, pero solo hasta un número máximo de caracteres (n) especificado. 
* Si encuentra la subcadena dentro de esa porción limitada de la cadena principal, devuelve un puntero al primer carácter de la aparición. 
* Si la subcadena no se encuentra o la sucadena es vacía, devuelve  NULL (o string1 en algunos casos).
*/
char * ft_strnstr (const char *big,	const char *little, size_t len){
    size_t i;
    size_t result;

    i=0;
    while(*big && *little && (i<len)){
        if(*big==*little)
            result++;
        big++;
        little++;
        i++;
    }  
    if (result == len)
        return (char *)big;
    return NULL;
}

int main(void){
    const char big[]="Hola mmundo";
    const char little[]="ola";

    char *ptr_ft=ft_strnstr(big,little,4);
    char *ptr=strnstr(big,little,4);
    printf("%p",ptr_ft);
    printf("%p",ptr);
}