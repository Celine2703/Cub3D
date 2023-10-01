/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:58:18 by cmartin-          #+#    #+#             */
/*   Updated: 2022/02/13 20:13:47 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*new_str;
	int		i;

	if (!src)
		return (0);
	new_str = ft_calloc(sizeof(char), ft_strlen(src) + 1);
	if (new_str == 0)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		new_str[i] = src[i];
		i++;
	}
	return (new_str);
}
