/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:38:39 by cmartin-          #+#    #+#             */
/*   Updated: 2023/11/26 14:38:39 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../minilibx-linux/mlx.h"
#include "readFile.h"

void	change_image(t_data *data)
{
	t_wallhit	distance[640];
	long double	height;
	int			x;
	long double	pi;

	x = 0;
	pi = M_PI / 6.1;
	while (x < 640)
	{
		distance[x] = calcule_dist(data->map, data->player, pi);
		distance[x].dist = distance[x].dist * cosl(pi);
		x++;
		pi -= (M_PI / 3) / 640.0;
	}
	x = 0;
	while (x < 640)
	{
		height = 320 / distance[x].dist;
		rewriteline(data, x, height, distance[x]);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->base.image, 0, 0);
}

void	rewriteline(t_data *data, int x, long double height, t_wallhit wall)
{
	int		y;
	char	*pixel;
	int		test;

	test = height;
	y = 0;
	while (test > 320.0)
	{
		create_texture_coord (data, wall, 64.0 / (height * 2));
		test = test - 64.0 / (height * 2);
	}
	while (y < 640)
	{
		pixel = data->base.addr + y * data->base.sizeline
			+ x * data->base.bpp / 8;
		if (y > (640.0 / 2.0 + height))
			*(int *) pixel = data->floor.color;
		else if (y < (640.0 / 2.0 - height))
			*(int *) pixel = data->ceiling.color;
		else
			*(int *)pixel = selectcolor(data, wall, 64.0 / (height * 2));
		y++;
	}
	create_texture_coord(0, wall, 0);
}

t_wallhit	create_texture_coord(t_data *data, t_wallhit wall, long double step)
{
	t_wallhit			texture_coordinate;
	static long double	y;

	if (!data)
	{
		y = step;
		return (wall);
	}
	if (wall.mur == 'O' || wall.mur == 'E')
	{
		texture_coordinate.y = (wall.y - (int)wall.y) * 64;
	}
	else
	{
		texture_coordinate.y = (wall.x - (int)wall.x) * 64;
	}
	texture_coordinate.x = floor(y);
	y += step;
	return (texture_coordinate);
}

int	selectcolor(t_data *data, t_wallhit wall, long double step)
{
	int			color;
	char		*pixel;
	t_wallhit	texture_coordinate;

	texture_coordinate = create_texture_coord(data, wall, step);
	if (wall.mur == 'E')
		wall.mur = 0;
	else if (wall.mur == 'O')
		wall.mur = 1;
	else if (wall.mur == 'N')
		wall.mur = 2;
	else if (wall.mur == 'S')
		wall.mur = 3;
	pixel = data->textures[wall.mur].addr
		+ (int)texture_coordinate.x * data->textures[wall.mur].sizeline
		+ (int)texture_coordinate.y * data->textures[wall.mur].bpp / 8;
	color = *(int *)pixel;
	return (color);
}

int	create_base_image(t_color floor, t_color ceiling, void *mlx, t_data *data)
{
	int		x;
	int		y;
	char	*pixel;

	data->base.image = mlx_new_image(mlx, 640, 640);
	if (data->base.image == NULL)
		return (1);
	data->base.addr = mlx_get_data_addr(data->base.image,
			&data->base.bpp, &data->base.sizeline, &data->base.endian);
	y = 0;
	while (y < 640)
	{
		x = 0;
		while (x < 640)
		{
			pixel = data->base.addr + y * data->base.sizeline
				+ x * data->base.bpp / 8;
			*(int *) pixel = floor.color;
			if (y > (640 / 2))
				*(int *) pixel = ceiling.color;
			x++;
		}
		y++;
	}
	return (0);
}
