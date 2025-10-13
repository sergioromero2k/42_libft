/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 07:07:17 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/13 11:02:23 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void ft_lstadd_front(t_list **lst, t_list *new){
    new->next=*lst;    
}

int main(void){
    t_list *nodo1;
    int *num1;

    num1=malloc(sizeof(int));
    *num1=42;


    nodo1=ft_lstnew(num1)

    nodo1=
    
    
}