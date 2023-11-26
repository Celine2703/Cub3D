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
		line = deletewhitespace(data->file[lineread]);
		type = whichline(line);
		if (type == -1 && nb != 6)
			return (free(line), printf("Error 42 : ligne %d\n", lineread + 1));
		else if (type <= 4 && ++nb && readpath(type, line, data) == -1)
			return (free(line), lineread + 1);
		else if (type == 5 && ++nb && getcolor(line, &data->ceiling))
			return (free(line), lineread + 1);
		else if (type == 6 && ++nb && getcolor(line, &data->floor))
			return (free(line), lineread + 1);
		free(line);
		lineread++;
	}
	if (lineread < 8)
		return (-1);
	return (0);
}
