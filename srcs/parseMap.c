/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:54:30 by ccravero          #+#    #+#             */
/*   Updated: 2023/09/08 16:36:32 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readFile.h"
#include "cub3d.h"

int	parse_map(t_data *data)
{
	t_pair	lines;
	int		longest_line;

	if (ft_startmap(data->file, &lines, 0))
	{
		printf("Error : erreur dans l'importation de la map\n");
		return (-1);
	}
	longest_line = find_longest(data->file, lines);
	data->map.map_height = lines.second - lines.first + 1;
	data->map.map_width = longest_line;
	if (find_copy_map(data, lines) == -1)
	{
		printf("Error : malloc error\n");
		return (-1);
	}
	reverse_map(data->map);
	replace_player(data);
	if (checkmap(data))
		return (-1);
	replacespace(data);
	return (0);
}

int	replace_player(t_data *data)
{
	int	i;
	int	j;
	int	err;

	err = 0;
	i = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (data->map.tab[i][j])
		{
			if (data->map.tab[i][j] == 'N' || data->map.tab[i][j] == 'S'
				|| data->map.tab[i][j] == 'E' || data->map.tab[i][j] == 'W')
			{
				data->player.angle = select_direction(data->map.tab[i][j]);
				data->map.tab[i][j] = '0';
				data->player.posx = j + 0.5;
				data->player.posy = i + 0.5;
				err += 1;
			}
			j++;
		}
		i++;
	}
	return (err);
}

long double	select_direction(char dir)
{
	if (dir == 'N')
		return (M_PI / 2);
	if (dir == 'S')
		return (3 * M_PI / 2);
	if (dir == 'E')
		return (0);
	if (dir == 'W')
		return (M_PI);
	return (0);
}

int	find_copy_map(t_data *data, t_pair lines)
{
	int	i;

	data->map.tab = ft_calloc(data->map.map_height + 1, sizeof(char *));
	if (data->map.tab == NULL)
		return (-1);
	i = 0;
	while (i < data->map.map_height)
	{
		data->map.tab[i] = ft_calloc(data->map.map_width + 1, sizeof(char));
		if (data->map.tab[i] == NULL)
			return (-1);
		ft_strlcpy(data->map.tab[i], data->file[lines.first + i],
			data->map.map_width + 1);
		i++;
	}
	return (0);
}

int	find_longest(char **file, t_pair lines)
{
	int	i;
	int	longest_line;

	i = lines.first;
	longest_line = 0;
	while (i <= lines.second)
	{
		if (ft_strlen(file[i]) > (unsigned)longest_line)
			longest_line = ft_strlen(file[i]);
		i++;
	}
	return (longest_line);
}
