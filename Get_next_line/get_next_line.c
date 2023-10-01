/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:51:43 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/12 14:51:44 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **str, char *new)
{
	free(*str);
	*str = new;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t size, size_t espace)
{
	void		*tab;
	size_t		cpt;
	size_t		taille;

	taille = espace * size;
	if (size == 0 || espace == 0)
		return (0);
	if (taille / size != espace)
		return (0);
	cpt = 0;
	tab = malloc(sizeof(char) * taille);
	if (tab == 0)
		return (0);
	while (cpt < taille)
	{
		((char *)tab)[cpt] = 0;
		cpt ++;
	}
	return (tab);
}

char	*ft_read(char **str, int fd)
{
	char	*ligne;
	char	*temp;
	int		verif;

	ligne = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!ligne)
	{
		ft_free(str, 0);
		return (0);
	}
	verif = read(fd, ligne, BUFFER_SIZE);
	if (verif <= 0)
	{
		free(ligne);
		temp = 0;
		if (*str && (*str)[0])
			temp = ft_strdup(*str);
		ft_free(str, 0);
		return (temp);
	}
	temp = ft_strdup(*str);
	ft_free(str, ft_strjoinb(temp, ligne));
	free(ligne);
	free(temp);
	return (get_next_line(fd));
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ligne;
	char		*temp;

	if (str && ft_strstr(str) != -1)
	{
		temp = ft_substr(str, ft_strstr(str) + 1,
				ft_strlen(str) - ft_strstr(str) - 1);
		ligne = ft_strncpy(str, ft_strstr(str) + 1);
		free(str);
		str = temp;
		return (ligne);
	}
	return (ft_read(&str, fd));
}
