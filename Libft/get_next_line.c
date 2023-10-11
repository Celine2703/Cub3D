/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:51:43 by cmartin-          #+#    #+#             */
/*   Updated: 2023/06/28 13:13:21 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **str, char *new)
{
	free(*str);
	*str = new;
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
	ft_free(str, ft_strjoingnl(temp, ligne));
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
