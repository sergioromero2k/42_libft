/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:37:25 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/10/08 21:25:07 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	result;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	result = 0;
	if (size == 0)
		return (src_len);
	if (size > dst_len)
		result = dst_len + src_len;
	else
		result = src_len + size;
	i = 0;
	while (src[i] && dst_len <= size)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (result);
}

/* int main(void){
	char dst[8] = "Hola";   // tamaño total 8
	char src[] = "Mundo";

	size_t len = strlcat(dst, src, sizeof(dst));

	printf("dst: %s\n", dst); // "HolaMun" -> truncado MALLL
	printf("len: %zu\n", len); // 9
		-> longitud que habría tenido si hubiera espacio suficientes,
		zu el es tipo de para printf
} */
/*
	* Concatena una cadena de origen (`src`)
	al final de una cadena de destino (`dst`),
	de forma segura al incluir el tamaño del búfer
	de destino para evitar desbordamientos de memoria.

	* Devuelve la longitud que la cadena resultante
	habría tenido con espacios ilimitado,
	lo que permite determinar si el destino era
	demasiado pequeño para contener toda la cadena.

	* Tener en cuenta que esto no necesariamente
	es la longitud que realmente cabe en dst,
	ya que si no cumple si o si te devolvera la cadena.
 */