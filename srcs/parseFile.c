/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseFile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:01:26 by ccravero          #+#    #+#             */
/*   Updated: 2023/09/08 14:41:23 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readFile.h"

int	whichline(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (1);
	if (line[0] == 'S' && line[1] == 'O')
		return (2);
	if (line[0] == 'W' && line[1] == 'E')
		return (3);
	if (line[0] == 'E' && line[1] == 'A')
		return (4);
	if (line[0] == 'C')
		return (5);
	if (line[0] == 'F')
		return (6);
	if (ft_strlen(line) == 0)
		return (7);
	return (-1);
}

int	getpath(char *line, char **path)
{
	if (*path != NULL)
	{
		printf("Error: %c%c path already set\n", line[0], line[1]);
		return (-1);
	}
	*path = ft_strdup(line + 2);
	if (*path == NULL)
		return (-1);
	return (0);
}

int	readpath(int type, char *line, t_data *data)
{
	if (type == 1 && getpath(line, &data->north) == -1)
		return (-1);
	if (type == 2 && getpath(line, &data->south) == -1)
		return (-1);
	if (type == 3 && getpath(line, &data->west) == -1)
		return (-1);
	if (type == 4 && getpath(line, &data->east) == -1)
		return (-1);
	return (0);
}

int	getcolor(char *line, t_color *color)
{
	int		i;
	char	**split;
	int		nb;

	if (color->red != -1)
		return (print_error_color(line[0]));
	i = 0;
	split = ft_split(line + 1, ',');
	if (!split || sizesplit(split) != 3)
		return (freesplit(split), -1);
	while (split[i] != NULL)
	{
		if (isallnb(split[i]) == -1)
			return (freesplit(split), -1);
		nb = ft_atoi(split[i]);
		if (nb < 0 || nb > 255)
			return (freesplit(split), -1);
		if (i == 0)
			color->red = nb;
		else if (i == 1)
			color->green = nb;
		color->blue = nb;
		i++;
	}
	return (freesplit(split), combinecolor(color));
}

int	combinecolor(t_color *color)
{
	color -> color = color -> red;
	color -> color = color -> color << 8;
	color -> color += color ->green;
	color -> color = color -> color << 8;
	color -> color += color -> blue;
	return (0);
}

int	parsefile(t_data *data)
{
	int		lineread;
	int		nb;
	int		type;
	char	*line;

	lineread = 0;
	nb = 0;
	while (nb < 7 && data->file[lineread] != NULL)
	{
		type = whichline(line);
		line = deletewhitespace(data->file[lineread]);
		if (type == -1 && nb != 6)
			return (free(line), lineread + 1);
		else if (type <= 4 && ++nb && readpath(type, line, data) == -1)
			return (free(line), lineread + 1);
		else if (type == 5 && ++nb && getcolor(line, &data->ceiling) == -1)
			return (free(line), lineread + 1);
		else if (type == 6 && ++nb && getcolor(line, &data->floor) == -1)
			return (free(line), lineread + 1);
		free(line);
		lineread++;
	}
	return (0);
}
