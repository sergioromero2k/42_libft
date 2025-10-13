/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:05:50 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/13 20:29:16 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst->next != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/* int	main(void)
{
	t_list *node;
	t_list *node1;
	t_list *node2;
	t_list *node3;
	int *num1;
	int *num2;
	int *num3;

	num1 = malloc(sizeof(int));
	num2 = malloc(sizeof(int));
	num3 = malloc(sizeof(int));
	*num1 = 5;
	*num2 = 6;
	*num3 = 7;

	node = NULL;
	node1 = ft_lstnew(num1);
	node2 = ft_lstnew(num2);
	node3 = ft_lstnew(num3);

	ft_lstadd_front(&node, node1);
	ft_lstadd_front(&node, node2);
	ft_lstadd_front(&node, node3);

	printf("%d", ft_lstsize(node));
	free(node1);
	free(node2);
	free(node3);
	free(num1);
	free(num2);
	free(num3);
} */
int	main(void)
{
	t_list *node = NULL;
	printf("%d", ft_lstsize(node));
}