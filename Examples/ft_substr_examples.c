/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_examples.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:53:37 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/18 14:04:17 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
char *ft_substr(char const *s, unsigned int start, size_t len){
    char *str;
    char *str_result;
    
    if(!s)
        return NULL;
    str=(char *)s;
    ft_strlcpy(str_result,s+start,len);
    return str_result;    
}
