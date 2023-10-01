/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:00:44 by cmartin-          #+#    #+#             */
/*   Updated: 2022/02/09 10:42:27 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
		j++;
	if (size <= j)
		return (size + ft_strlen(src));
	while ((src[i] != '\0') && (size - j - 1))
	{
		dest[j + i] = src[i];
		i++;
		size--;
	}
	dest[j + i] = '\0';
	return (j + ft_strlen(src));
}
