/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:03:21 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/09 10:05:20 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_init(int i, const char *str, char s)
{
	int	cpt;
	int	c;

	c = i;
	cpt = 0;
	while (str[c] && (str[c++] != s))
			cpt++;
	return (cpt);
}

static int	ft_count(const char *str, char s, int i)
{
	int	nbmot;
	int	c;

	nbmot = 0;
	c = 0;
	while (str[i])
	{
		if ((str[i] == s) && c)
		{
			nbmot++;
			c = 0;
		}
		else if (str[i] != s)
			c = 1;
		i++;
	}
	if (c == 1)
		nbmot++;
	return (nbmot);
}

static void	ft_clear(char **str, int j)
{
	int	i;

	i = 0;
	while (j > 0)
	{
		free(str[i++]);
		j--;
	}
	free(str);
	str = 0;
}

static void	ft_put_inside(char **final, const char *str, char s, int i)
{
	int	j;
	int	cpt;
	int	c;

	j = 0;
	while (str[i])
	{
		cpt = ft_init(i, str, s);
		if (cpt)
		{
			c = 0;
			final[j] = malloc(sizeof(char) * (cpt + 1));
			if (!final[j])
			{
				ft_clear(final, j);
				return ;
			}
			while (str[i] && (str[i] != s))
				final[j][c++] = str[i++];
			final[j++][c] = '\0';
		}
		if (str[i])
			i++;
	}
}

char	**ft_split(char const *str, char const c)
{
	char	**final;
	int		nbmot;

	if (!str)
		return (0);
	nbmot = ft_count(str, c, 0);
	final = malloc(sizeof(char *) * (nbmot + 1));
	if (!final)
		return (0);
	ft_put_inside(final, str, c, 0);
	if (!final)
		return (0);
	final[nbmot] = 0;
	return (final);
}
