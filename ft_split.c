/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:31:26 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/03 18:35:08 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_remstart(const char *s, int c){
	while(*s == (unsigned char)c){
		s++;
		return 1;
	}
	return 0;
}

static int ft_strcount(const char *s, int c){
	size_t i;
	size_t count;

	i=0;	
	count=0;
	while(s[count]){
		if (ft_remstart(*s,c))
			i++;
		count++;
	}
	return i;
}
// ,,,aidadia,da,,,,ad,adaddd,dadd,,,,,,,,

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;

	// b=*a
	char *(*arr);

	i = 0;
	j = 0;

    arr=(char **)malloc(i*sizeof(char *));
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