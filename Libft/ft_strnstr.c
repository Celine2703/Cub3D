/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:39:45 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/02 17:39:47 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	j = 0;
	while ((str[i] != '\0') && (i + j < n))
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j < n))
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (0);
}
