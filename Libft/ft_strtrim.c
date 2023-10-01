/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:03:00 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/03 15:03:02 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		cpt_debut;
	int		cpt_fin;
	char	*str;
	int		i;

	if (!s1 || !set)
		return (0);
	cpt_debut = 0;
	while (ft_chr(set, s1[cpt_debut]))
		cpt_debut++;
	i = cpt_debut;
	while (s1[i])
		i++;
	cpt_fin = i - 1;
	while (ft_chr(set, s1[cpt_fin]) && cpt_fin >= cpt_debut)
		cpt_fin--;
	str = malloc(sizeof(char) * (cpt_fin - cpt_debut + 2));
	if (!str)
		return (0);
	i = 0;
	while (s1[cpt_debut] && cpt_fin - cpt_debut >= 0)
		str[i++] = s1[cpt_debut++];
	str[i] = '\0';
	return (str);
}
