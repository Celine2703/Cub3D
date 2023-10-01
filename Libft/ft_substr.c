/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:44 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/03 14:31:47 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	if (start > ft_strlen(s) || len == 0)
		return (ft_calloc(1, 1));
	if (ft_strlen(s + start) <= len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	i = 0;
	while (s[start] && len > 0)
	{
		str[i++] = s[start++];
		len--;
	}
	str[i] = '\0';
	return (str);
}
