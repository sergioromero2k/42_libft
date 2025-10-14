/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:18:34 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/14 18:42:32 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_ptr;

	if (!(*lst))
		return ;
	last_ptr = *lst;
	while (last_ptr->next != NULL)
		last_ptr = last_ptr->next;
	last_ptr->next = new;
	new->next = NULL;
}
