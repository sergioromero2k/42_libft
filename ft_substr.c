/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:37:42 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/02 21:16:48 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	size_t			len_s;
	char			*str;

	len_s = ft_strlen(s);
	str = (char *)malloc(len * (sizeof(char)) + 1);
	if (!str || (len > len_s))
		return (NULL);
	j = 0;
	while (j < len)
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}

/* int main(void){
	const char s[]="Hola mundo";
	char  *new_s=ft_substr(s,5,3);

	printf("%s",new_s);

	if (!new_s)
		return (1);

	free(new_s);    // Para que no haya fuga de memoria
	return (0);
} */
/*
* En C puro no existe una función estándar 
llamada `substr` como tal (esa es común en C++,Java, PHP, etc.).
* Pero a menudo uno mismo implementa un función con 
ese nombre para obtener una subcadena de una cadena más grande.
! ¿Cúal es la idea? Dada una cadena, una posición incial y una longitud,
devuelve una nueva cadena que contiene solo esa parte.
! Como esta cadena no existe en C debes hacerlo tu, con tus condiciones.
*/