/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 01:58:32 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 07:42:39 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len){
    size_t i;
    size_t len_needle;
    size_t count;

    i=0;
    len_needle=ft_strlen(needle);
    count=0;
    
    while(i<len){
        if(haystack[i]==needle[i]){
            count++;
        }else{
            if(count==len_needle)
                return (char *)&(needle[i-len_needle]);
            count=0;
        }
        i++;
    }
    return NULL;
}

/* int main() {
    // const char *text = "hola mundo";
    // const char *needle = "mun";
    const char *ft_text = "hola mundo";
    const char *ft_needle = "mun";

    // char *res = strnstr(text, needle, 11); // len >= longitud de text
    char *ft_res = ft_strnstr(ft_text, ft_needle, 11); // len >= longitud de text

    // printf("%p",res);
    printf("%p",ft_res);

    return 0;
} */