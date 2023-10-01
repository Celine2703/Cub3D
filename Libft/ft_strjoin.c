/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:52:09 by cmartin-          #+#    #+#             */
/*   Updated: 2022/02/17 17:03:57 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*final;
	int		taille;

	if (!s1)
		return ((char *)s2);
	taille = ft_strlen(s1) + ft_strlen(s2);
	final = malloc(sizeof(char) * taille + 1);
	if (final == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		final[i++] = s2[j++];
	}
	final[i] = '\0';
	return (final);
}
