/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:06:59 by cmartin-          #+#    #+#             */
/*   Updated: 2023/11/26 16:31:39 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../minilibx-linux/mlx.h"
#include "readFile.h"

int	textures_to_mlx(t_data *data)
{
	int	t;
	int	i;

	i = 0;
	data->textures[0].image = mlx_xpm_file_to_image(data->mlx,
			data->east, &t, &t);
	data->textures[1].image = mlx_xpm_file_to_image(data->mlx,
			data->west, &t, &t);
	data->textures[2].image = mlx_xpm_file_to_image(data->mlx,
			data->north, &t, &t);
	data->textures[3].image = mlx_xpm_file_to_image(data->mlx,
			data->south, &t, &t);
	while (i < 4)
	{
		if (data->textures[i].image == NULL)
			return (printf("error texture\n"));
		data->textures[i].addr = mlx_get_data_addr(data->textures[i].image,
				&data->textures[i].bpp, &data->textures[i].sizeline,
				&data->textures[i].endian);
		i++;
	}
	return (0);
}

int	initmlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	if (create_base_image (data->floor, data->ceiling, data->mlx, data))
		return (1);
	if (textures_to_mlx(data))
		return (1);
	data->win = mlx_new_window(data->mlx, 640, 640, "CUB3D");
	if (data->win == NULL)
		return (1);
	mlx_hook(data->win, 02, 1L << 0, ft_key, data);
	mlx_hook(data->win, 17, 0, ft_destroy_data, data);
	change_image(data);
	mlx_loop(data->mlx);
	return (0);
}
