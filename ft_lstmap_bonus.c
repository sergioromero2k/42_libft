/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:44:27 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/15 20:32:21 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*tmp;

	lst_new = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		ft_lstadd_back(&lst_new, tmp);
		if (!tmp)
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (lst_new);
}
/* void *add(void *ptr){
	char *str;

	str=(char *)ptr;

} */