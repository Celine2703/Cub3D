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

// void replace_spaceandplayer(t_data *data);

void	printrevsplit(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	while (i >= 0)
	{
		if (split[i] != NULL)
			printf("%d : %s\n", i, split[i]);
		else
			printf("%d : 0123456789\n", i);
		i--;
	}
}

int	parse_map(t_data *data)
{
	t_pair	lines;
	int		longest_line;

	if (ft_startmap(data->file, &lines))
	{
		printf("Error 42 : erreur dans l'importation de la map\n");
		return (-1);
	}
	printf("start %d  end %d\n", lines.first, lines.second);
	longest_line = find_longest(data->file, lines);
	printf("longest %d\n", longest_line);
	data->map.map_height = lines.second - lines.first + 1;
	data->map.map_width = longest_line;
	printf("height %d\n", data->map.map_height);
	printf("width %d\n", data->map.map_width);
	if (find_copy_map(data, lines) == -1)
	{
		printf("Error 54\n");
		return (-1);
	}
	reverse_map(data->map);
	// printf("error 58\n");
	printsplit(data->map.tab);
	printrevsplit(data->map.tab);
	replace_player(data);
	if (checkmap(data))
	{
		return (-1);
	}
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

int	ft_startmap(char **file, t_pair *lines)
{
	int		i;
	char	*line;
	int		emptyline;

	emptyline = 0;
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

int	checkmap(t_data *dt)
{
	int	i;
	int	j;

	i = 0;
	while (dt->map.tab[i])
	{
		j = 0;
		while (dt->map.tab[i][j])
		{
			if (dt->map.tab[i][j] != '0' && dt->map.tab[i][j] != '1'
				&& dt->map.tab[i][j] != '2' && dt->map.tab[i][j] != 'N'
				&& dt->map.tab[i][j] != 'S' && dt->map.tab[i][j] != 'E'
				&& dt->map.tab[i][j] != 'W' && dt->map.tab[i][j] != ' ')
				return (printf("Error 212 invalid char in map : %d\n", dt->map.tab[i][j]));
			if (dt->map.tab[i][j] == '0' )
			{
				if (i == 0 || i == dt->map.map_height - 1
					|| j == 0 || j == dt->map.map_width - 1)
					return (printf("Error 216 : '0' in the border of the map \n"));
				if ((dt->map.tab[i + 1][j] != '0' && dt->map.tab[i + 1][j] != '1')
					|| (dt->map.tab[i - 1][j] != '0' && dt->map.tab[i - 1][j] != '1')
					|| (dt->map.tab[i][j + 1] != '0' && dt->map.tab[i][j + 1] != '1')
					|| (dt->map.tab[i][j - 1] != '0' && dt->map.tab[i][j - 1] != '1'))
					return (printf("Error 221 : '0' not circled by '0' or '1'\n"));
			}
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
