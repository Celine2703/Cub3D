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

#include "readFile.h"

void	destroy_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->file[i] != NULL)
	{
		free(data->file[i]);
		i++;
	}
	free(data->east);
	free(data->west);
	free(data->north);
	free(data->south);
	free(data->file);
}

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
	ret = ft_calloc(ft_strlen(line) + 1, sizeof(char));
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
		if (missinfo(*data) == 0)
			printf("Error : line %d", error);
		destroy_data(data);
		return (1);
	}
	if (missinfo(*data))
	{
		destroy_data(data);
		return (1);
	}
	return (0);
}