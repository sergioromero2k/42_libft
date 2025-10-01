/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:24:23 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/01 16:39:10 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *ptr)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while ((ptr[i] == ' ') || ((ptr[i] >= 9) && (ptr[i] <= 13)))
		i++;
	if ((ptr[i] == '+') || (ptr[i] == '-'))
	{
		if (ptr[i] == '-')
			sign = -sign;
		i++;
	}
	while ((ptr[i] >= '0') && (ptr[i] <= '9'))
	{
		res = res * 10 + ptr[i] - '0';
		i++;
	}
	return (res * sign);
}
