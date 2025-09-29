/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 23:49:06 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/09/29 23:53:43 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// calculate the length of a string

int ft_strlen(char *text){
    int i;

    i=0;
    while(*text){
        i++;
        text--;
    }
    return i;
}