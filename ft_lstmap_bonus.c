/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:44:27 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/14 18:12:10 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;

	lst_new = lst;
	if (!lst || !f || !del)
		return NULL;
	while (lst_new)
	{
		if (!f(lst_new->content))
		{
			del(lst_new->content);
		}
		else
		{
			f(lst_new->content);
		}
		lst_new = lst_new->next;
	}
	return (lst_new);
}
/* void *add(void *ptr){
	char *str;

	str=(char *)ptr;

} */