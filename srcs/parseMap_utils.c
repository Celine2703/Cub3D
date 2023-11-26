/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseMap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:32:20 by cmartin-          #+#    #+#             */
/*   Updated: 2023/11/26 16:20:31 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readFile.h"
#include "cub3d.h"

int	ft_startmap(char **file, t_pair *lines, int emptyline)
{
	int		i;
	char	*line;

	lines->first = -1;
	i = 0;
	while (file[i] != NULL)
	{
		line = deletewhitespace(file[i]);
		if (whichline(file[i]) == -1)
		{
			if (emptyline == 1)
				return (free (line), -2);
			if (lines->first == -1)
				lines->first = i;
			lines->second = i;
		}
		if (whichline(file[i]) == 7 && lines->first >= 0)
			emptyline = 1;
		free(line);
		i++;
	}
	if (lines->first == -1)
		return (-1);
	return (0);
}

void	reverse_map(t_map map)
{
	int		start;
	int		end;
	char	*tmp;

	start = 0;
	end = map.map_height - 1;
	while (start <= end)
	{
		tmp = map.tab[start];
		map.tab[start] = map.tab[end];
		map.tab[end] = tmp;
		start++;
		end--;
	}
}

int	test_checkmap(t_data *d, int i, int j)
{
	if (i == 0 || i == d->map.map_height - 1
		|| j == 0 || j == d->map.map_width - 1)
		return (printf("Error 216\n"));
	if ((d->map.tab[i + 1][j] != '0' && d->map.tab[i + 1][j] != '1')
		|| (d->map.tab[i - 1][j] != '0' && d->map.tab[i - 1][j] != '1')
		|| (d->map.tab[i][j + 1] != '0' && d->map.tab[i][j + 1] != '1')
		|| (d->map.tab[i][j - 1] != '0' && d->map.tab[i][j - 1] != '1'))
		return (printf("Error 221 : empty zone near a space\n"));
	return (0);
}

int	checkmap(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map.tab[i])
	{
		j = 0;
		while (d->map.tab[i][j])
		{
			if (d->map.tab[i][j] != '0' && d->map.tab[i][j] != '1'
				&& d->map.tab[i][j] != '2' && d->map.tab[i][j] != 'N'
				&& d->map.tab[i][j] != 'S' && d->map.tab[i][j] != 'E'
				&& d->map.tab[i][j] != 'W' && d->map.tab[i][j] != ' ')
				return (printf("Error 212 invalid char in map : %d\n",
						d->map.tab[i][j]));
			if (d->map.tab[i][j] == '0' )
				if (test_checkmap(d, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	replacespace(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (j < data->map.map_width)
		{
			if (data->map.tab[i][j] == ' ' || data->map.tab[i][j] == 0)
				data->map.tab[i][j] = '1';
			j++;
		}
		i++;
	}
}
