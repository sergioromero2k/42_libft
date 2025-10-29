/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_examples.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:29:57 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/18 21:46:58 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (42);
	return (0);
}
#include <stdio.h>

int	main(void)
{
	// NULL Caracter nulo
	printf("%d\n", ft_isdigit(00));
	// SOH Inicio encabezado
	printf("%d\n", ft_isdigit(01));
	// STX Inicio texto
	printf("%d\n", ft_isdigit(02));
	// Espacio
	printf("%d\n", ft_isdigit(32));
	// <
	printf("%d\n", ft_isdigit(32));
	// Inicio de ASCII extendido
	printf("%d\n", ft_isdigit(0));
	// Final de ASCII extendido
	printf("%d\n", ft_isdigit(9));
	// 0 numero
	printf("%d\n", ft_isdigit(48));
	// 9 numero
	printf("%d\n", ft_isdigit(57));
}
// cc -Wall -Werror -Wextra ft_isdigit_examples.c
// ./a.out 