/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:24:23 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 21:18:36 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int	i;
	int	sign;
	int	res;

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
/* int main(void) {
	char cadena_numero[] = "-2147483648"; // La cadena que queremos convertir
	int numero_entero;

	// Usamos atoi para convertir la cadena a entero
	numero_entero = ft_atoi(cadena_numero);

	printf("La cadena es: \"%s\"\n", cadena_numero);
	printf("El número entero es: %d\n", numero_entero);
	return (0);
} */
/*
Convert a string a to an integer
* Es una función de programación que convierte una 
cadena de caracteres que contiene un número a su representación entera.
* Es decir, toma un texto "123" y lo transforma en el número entero 123,
que luego se puede usar en operaciones matemáticas.
* Devuelve un número entero correspondiente.
 */
