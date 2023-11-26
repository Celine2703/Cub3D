/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:30:38 by cmartin           #+#    #+#             */
/*   Updated: 2023/10/29 19:02:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "readFile.h"

void	ft_mapclear(t_map *map)
{
	int	i;

	map ->map_width = 0;
	map ->map_height = 0;
	if (!map ->tab)
		return ;
	i = 0;
	while (map ->tab[i])
	{
		free(map ->tab[i]);
		i++;
	}
	free(map ->tab);
}

void	checkfree(void *ptr)
{
	if (ptr)
		free(ptr);
}

int	ft_destroy_data(t_data *data)
{
	int	i;

	if (data->file)
		freesplit(data->file);
	if (data->map.tab)
		ft_mapclear(&data->map);
	checkfree(data->north);
	checkfree(data->south);
	checkfree(data->east);
	checkfree(data->west);
	if (data->base.image)
		mlx_destroy_image(data->mlx, data->base.image);
	i = 0;
	while (i < 4)
		if (data->textures[i++].image)
			mlx_destroy_image(data->mlx, data->textures[i - 1].image);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	checkfree(data->mlx);
	ft_bzero(data, sizeof(t_data));
	exit(0);
}
