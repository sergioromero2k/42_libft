/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#s+   +#+           */
/*   Created: 2025/09/30 07:05:30 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/30 08:16:41 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fill memory with a constant byte

#include <stdlib.h>

void *ft_memset(void *s, int c, size_t n){

    unsigned char *pr;

    pr=(unsigned char *)s;
    while(n--)
        *pr++=(unsigned char)c;
    return s;
}

#include <stdio.h>
#include <string.h>

int main(void){
    char text[]="Hola pepe jojojojo";
    char text_mem[]="Hola pepe jojojojo";

    // memset
    memset(text_mem,'.',5);

    printf("%s",text_mem);
    printf("\n");

    // ft_memset
    ft_memset(text,'.',5);
    printf("%s", text);
    
}


/* #include <stdio.h>
#include <string.h>

int main(){
    char str[50] = "GeeksForGeeks is for programming geeks.";

    memset(str+13, '.',8*sizeof(char));
    printf("%s",str);
    
} */


    