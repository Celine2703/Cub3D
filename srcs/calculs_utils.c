/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:38:10 by cmartin           #+#    #+#             */
/*   Updated: 2023/11/24 13:32:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "readFile.h"
#include <string.h>

double	calcule_y(t_player player, double x)
{
	double	adjacent;
	double	oppose;

	if (player.cosinus == 0)
		return (0);
	adjacent = fabs(x - player.posx);
	oppose = (adjacent / player.cosinus) * player.sinus;
	if (player.angle < M_PI / 2 || player.angle > 3 * M_PI / 2)
		return (oppose);
	else
		return (-oppose);
}

double	calcule_x(t_player player, double y)
{
	double	adjacent;
	double	oppose;

	if (player.sinus == 0)
		return (0);
	adjacent = fabs(y - player.posy);
	oppose = (adjacent / player.sinus) * player.cosinus;
	if (player.angle > 0 && player.angle < M_PI)
		return (oppose);
	else
		return (-oppose);
}

t_wallhit	calcule_horizontal(t_map map, t_player p, char c)
{
	t_wallhit	w;

	ft_bzero(&w, sizeof(t_wallhit));
	if (c == 'E')
		w.x = ceil(p.posx);
	else
		w.x = floor(p.posx) - 0.001;
	w.y = p.posy + calcule_y(p, w.x);
	while (!(w.x < 0 || w.y < 0 || w.x > map.map_width || w.y > map.map_height)
		&& map.tab[(int)w.y][(int)w.x] != '1')
	{
		if (c == 'E')
			w.x++;
		else
			w.x--;
		w.y = p.posy + calcule_y(p, w.x);
		if (w.x < 0 || w.y < 0 || w.x > map.map_width || w.y > map.map_height)
			return (w.dist = 999999999, w);
	}
	if (c == 'E')
		w.mur = 'O';
	else
		w.mur = 'E';
	w.dist = sqrt(pow(p.posx - w.x, 2) + pow(p.posy - w.y, 2));
	return (w);
}

t_wallhit	calcule_vertical(t_map map, t_player p, char c)
{
	t_wallhit	w;

	ft_bzero(&w, sizeof(t_wallhit));
	if (c == 'N')
		w.y = ceil(p.posy);
	else
		w.y = floor(p.posy) - 0.001;
	w.x = p.posx + calcule_x(p, w.y);
	while (!(w.x < 0 || w.y < 0 || w.x > map.map_width || w.y > map.map_height)
		&& map.tab[(int)w.y][(int)w.x] != '1')
	{
		if (c == 'N')
			w.y++;
		else
			w.y--;
		w.x = p.posx + calcule_x(p, w.y);
		if (w.x < 0 || w.y < 0 || w.x > map.map_width || w.y > map.map_height)
			return (w.dist = 999999999, w);
	}
	if (c == 'N')
		w.mur = 'S';
	else
		w.mur = 'N';
	w.dist = sqrt(pow(p.posx - w.x, 2) + pow(p.posy - w.y, 2));
	return (w);
}

t_wallhit	put_calcul(t_map map, t_player player, char *str)
{
	t_wallhit	dist_v;
	t_wallhit	dist_h;

	dist_v = calcule_vertical(map, player, str[0]);
	dist_h = calcule_horizontal(map, player, str[1]);
	if (dist_v.dist > 1000 && dist_h.dist > 1000)
	{
		printf("both dist > 1000\n");
		printf("dist_v.dist = %f, dist_h.dist = %f\n", dist_v.dist, dist_h.dist);
		printf("dist_v.x = %f, dist_v.y = %f\n", dist_v.x, dist_v.y);
		printf("dist_h.x = %f, dist_h.y = %f\n", dist_h.x, dist_h.y);
		printf("player.posx = %f, player.posy = %f\n, player.angle", player.posx, player.posy);
	}
	if (dist_v.dist < dist_h.dist)
		return (dist_v);
	else
		return (dist_h);
}
