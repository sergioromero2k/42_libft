/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:35:38 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/03 19:40:59 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	long	nb;
	int		len;

	nb = (long)n;
	len = 1;
	if (nb < 0)
	{
		nb = nb * (-1);
		len++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*arr;
	long	nb;
	int		len;

	len = ft_intlen(n);
	nb = (long)n;
	arr = (char *)ft_calloc(sizeof(char), ft_intlen(n) + 1);
	if (!arr)
		return (NULL);
	arr[len + 1] = 0;
	if (nb < 0)
	{
		arr[0] = '-';
		nb = nb * (-1);
	}
	while (len-- && arr[len] != '-')
	{
		arr[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (arr);
}

/* int	main(void)
{
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(0));
} */
/*
	while (len && arr[len-1] != '-')
	{
		arr[len-1] = nb % 10 + '0';
		nb = nb / 10;
	}
*/