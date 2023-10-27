/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:30:38 by cmartin           #+#    #+#             */
/*   Updated: 2023/10/27 13:32:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mapclear(t_map *map)
{
	int	i;

	map ->map_width = 0;
	map ->map_height = 0;
	if (!map ->map)
		return ;
	i = 0;
	while (map ->tab[i])
	{
		free(map ->tab[i]);
		i++;
	}
	free(map ->tab);
}

void	ft_stop(t_map *map, void *mlx)
{
	ft_mapclear(map);
	mlx_destroy_display(mlx);
	free(mlx);
}

void	ft_destroy(t_data *data)
{
	ft_mapclear(data.map);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}
