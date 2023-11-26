/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseFile_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:35:12 by cmartin           #+#    #+#             */
/*   Updated: 2023/11/26 17:26:27 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readFile.h"

int	whichline(char *line)
{
	if (!line)
		return (-1);
	if (ft_strlen(line) == 0)
		return (7);
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
			return (freesplit(split), printf("Error : color not a number\n"));
		nb = ft_atoi(split[i]);
		if (nb < 0 || nb > 255)
			return (freesplit(split), printf("Error: color out of range\n"));
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
