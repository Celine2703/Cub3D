/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:14:59 by cmartin           #+#    #+#             */
/*   Updated: 2023/11/24 14:40:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "readFile.h"

void	ft_putdist_wall(t_wallhit distance, t_player *player)
{
	if (distance.x == floor(distance.x))
	{
		if (distance.x > player->posx)
			player->posx = distance.x - 0.01;
		else if (distance.x < player->posx)
			player->posx = distance.x + 0.01;
	}
	else
		player->posx = distance.x;
	if (distance.y == floor(distance.y))
	{
		if (distance.y > player->posy)
			player->posy = distance.y - 0.01;
		else if (distance.y < player->posy)
			player->posy = distance.y + 0.01;
	}
	else
		player->posy = distance.y;
}

void	ft_putmov(t_map map, t_player *player, double angle)
{
	t_wallhit	distance;

	player->angle = angle;
	distance = calcule_dist(map, *player, 0);
	if (distance.dist <= 0.21)
		ft_putdist_wall(distance, player);
	else
	{
		player->posx += 0.2 * cos(angle);
		player->posy += 0.2 * sin(angle);
	}
}

void	ft_rotation(t_player *player, char c)
{
	double	rotation;

	rotation = M_PI / 30;
	if (player->angle >= 2 * M_PI)
		player->angle = 0;
	if (c == 'd')
	{
		if (player->angle - rotation < 0)
			player->angle = 2 * M_PI - (rotation - player->angle);
		else
			player->angle -= rotation;
	}
	else if (c == 'g')
		player->angle += rotation;
}

int	ft_mov(t_map map, t_player *player, int key)
{
	double	prevangle;

	prevangle = player->angle;
	if (key == 'w')
		ft_putmov(map, player, player->angle);
	else if (key == 'a')
		ft_putmov(map, player, fmod(player->angle + M_PI / 2, 2 * M_PI));
	else if (key == 's')
		ft_putmov(map, player, fmod(player->angle + M_PI, 2 * M_PI));
	else if (key == 'd')
		ft_putmov(map, player, fmod(player->angle + 3 * M_PI / 2, 2 * M_PI));
	else if (key == 65361 || key == 65363)
	{
		player->angle = prevangle;
		if (key == 65361)
			ft_rotation(player, 'g');
		else if (key == 65363)
			ft_rotation(player, 'd');
		prevangle = player->angle;
	}
	else
		return (0);
	player->angle = prevangle;
	return (1);
}

int	ft_key(int key, t_data *data)
{
	if (key == 65307)
		ft_destroy_data(data);
	if (data -> player.angle == 2 * M_PI)
		data -> player.angle = 0;
	if (ft_mov(data->map, &(data->player), key))
		change_image(data);
	printf("angle = %f\n", data->player.angle);
	printf("posx = %f\n", data->player.posx);
	printf("posy = %f\n", data->player.posy);
	return (0);
}
