/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseUtils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:03:31 by ccravero          #+#    #+#             */
/*   Updated: 2023/09/08 14:59:47 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "readFile.h"

int	iswhitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	*deletewhitespace(char *line)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_calloc(ft_strlen(line) + 2, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (*line != '\0')
	{
		if (!iswhitespace(*line))
		{
			ret[i] = *line;
			i++;
		}
		line++;
	}
	return (ret);
}

int	isallnb(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] < '0' || line[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	parse_error(t_data *data)
{
	int	error;

	error = parsefile(data);
	if (error != 0)
	{
		if (error == -1)
			printf("Error 68 : file too small, not enough line");
		// else if (missinfo(*data) == 0)
		// 	printf("Error : line %d", error);
		ft_destroy_data(data);
		return (1);
	}
	if (missinfo(*data))
	{
		ft_destroy_data(data);
		return (1);
	}
	return (0);
}
