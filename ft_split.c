/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:31:26 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 23:14:16 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;

	// b=*a
	char *(*arr);

	i = 0;
	j = 0;

    arr=(char **)malloc(n*sizeof(char *));
	while (s[j])
	{
		if (ft_strchr(s, (unsigned char)c))
		{
			arr[i][j] = '\0';
			i++;
		}
		else
		{
			arr[i][j] = s[j];
		}
		j++;
	}
	return (arr);
}

void	main(void)
{
	char	texto[] = "uno,dos,tres";
	char	**arr;

	arr = ft_split(texto, ',');
	while (*arr)
	{
		printf("String completo: %s\n", *arr);
		printf("Primer caracter: %c\n", **arr);
	}
}

/*
En C nativo, no existe una función split() integrada
como en otros lenguajes; sin embargo, se puede lograr un efecto
similiar utilizando la funcion `strtok()` o escribiendo tu propia
función.

Divide una cadena en subcadenas(tokens) usando un delimitador
especificado, devolviendo cada subcadena encontrada hasta que se agota
la cadena original.
*/