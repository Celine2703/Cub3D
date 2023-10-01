/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:27:30 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/02 13:27:32 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	if (n == 0)
		return (dest);
	else if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			*((char *)dest + i - 1) = *((char *)src + i - 1);
			i--;
		}
	}
	return (dest);
}
