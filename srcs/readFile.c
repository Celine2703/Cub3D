/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:48:27 by ccravero          #+#    #+#             */
/*   Updated: 2023/09/08 14:58:08 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "readFile.h"

char	**getfile(t_data *data)
{
	if (checkfilename(data->filename) == 0)
		return (NULL);
	data->nb_lines = getnumberoflines(data);
	if (data->nb_lines == -1)
		return (NULL);
	data->file = ft_calloc(data->nb_lines + 1, sizeof(char *));
	if (data->file == NULL)
		return (NULL);
	if (getallline(data) == -1)
		return (NULL);
	return (data->file);
}

int	getallline(t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(data->filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	(void)i;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line[ft_strlen(line) - 2] = 0;
		// line[ft_strlen(line) - 2] = 0;
		data->file[i] = line;
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	getnumberoflines(t_data *data)
{
	int		nb_lines;
	int		fd;
	char	*line;

	fd = open(data->filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	nb_lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		nb_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nb_lines);
}

int	checkfilename(char *filename)
{
	int	len;

	if (filename == NULL)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	init_data(t_data *data, int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Wrong number of args\n");
		return (1);
	}
	ft_bzero(data, sizeof(t_data));
	data->ceiling.red = -1;
	data->floor.red = -1;
	data->filename = argv[1];
	if (getfile(data) == NULL)
	{
		printf("Error in reading the file\n");
		return (1);
	}
	return (0);
}
