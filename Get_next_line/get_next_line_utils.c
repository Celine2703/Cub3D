/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:52:01 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/12 14:52:02 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strstr(char *str)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strncpy(char *str, int n)
{
	char	*s;
	int		i;

	if (!str)
		return (0);
	s = ft_calloc(sizeof(char), n + 1);
	if (!s)
		return (0);
	i = 0;
	while (str[i] && (i < n))
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	if (start > ft_strlen(s) || len == 0)
		return (0);
	if (ft_strlen(s + start) <= len)
		len = ft_strlen(s + start);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (0);
	i = 0;
	while (s[start] && len > 0)
	{
		str[i++] = s[start++];
		len--;
	}
	return (str);
}

char	*ft_strjoinb(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final;
	int		taille;

	taille = ft_strlen(s1) + ft_strlen(s2);
	final = ft_calloc(sizeof(char), taille + 1);
	if (final == 0)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		final[i++] = s2[j++];
	return (final);
}
