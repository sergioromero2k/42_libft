/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:21:50 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 10:35:36 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* Es similar a malloc, es una función de C que asigna memoria dinamica en el "heap".
* Su principal característica es que reserva un bloque de memoria para un número específico de elementos, cada uno con un tamaño de bytes determinado, y además inicializa todos esos bytes a cero.
* Devuelve un puntero al primer elemento del bloque de memoria asignado, o un puntero null (null) si la asginación falla.

*/

void *ft_calloc(size_t nmemb, size_t size){

    void *ptr;
    size_t i;
    unsigned char* p;

    ptr=(void *)malloc(nmemb*size);
    i=0;

    p=ptr;
    while(i<nmemb*size)
        p[i]=0;
        i++;
}