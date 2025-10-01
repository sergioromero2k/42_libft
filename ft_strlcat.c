/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:37:25 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/30 20:21:25 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_len(char *str){
    int i;

    i=0;
    while(str[i])
        i++;
    return i;
}

size_t	ft_strlcat(char *dst, const char *src, size_t size){
        size_t i;
        size_t dst_len;
        size_t src_len;

        i=0;
        dst_len=ft_len(dst);
        src_len=ft_len(src);

        while(src[i]<size && src[i]){
            dst[dst_len+i]=src[i];
            i++
        }
        dst[dst_len+i]='\0';
        return (dst_len+src_len);
}

