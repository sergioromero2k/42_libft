/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:08:15 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/01 22:03:50 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n){
    size_t i;

    i=0;
    while(*s1 && *s2 && (i<n)){
        if(*s1>*s2){
            return -1;
        }else if(*s1<*s2){
            return 1;
        }
        s1++;
        s2++;
        i++;
    }
    return 0;
}

/* int main(void){
    const char buffer[7]="JoelAll";
    const char buffer2[4]="Joel";

    int result=ft_strncmp(buffer,buffer2,5);

    printf("%d",result);
} */