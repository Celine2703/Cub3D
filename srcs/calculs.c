/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin <cmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:47:23 by cmartin           #+#    #+#             */
/*   Updated: 2023/11/23 08:47:23 by cmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "readFile.h"
#include <string.h>

t_wallhit	calcule_dist_exception(t_map map, t_player player)
{
	if (player.angle == M_PI / 2)
		return (calcule_vertical(map, player, 'N'));
	else if (player.angle == 3 * M_PI / 2)
		return (calcule_vertical(map, player, 'S'));
	else if (player.angle == 0 || player.angle == 2 * M_PI)
		return (calcule_horizontal(map, player, 'E'));
	else
		return (calcule_horizontal(map, player, 'O'));
}

t_wallhit	calcule_dist(t_map map, t_player player, long double angle)
{
	t_wallhit	dist_h;

	ft_bzero(&dist_h, sizeof(t_wallhit));
	if (angle + player.angle < 0)
		player.angle = 2 * M_PI + fmod(player.angle + angle, 2 * M_PI);
	else
		player.angle = fmod(player.angle + angle, 2 * M_PI);
	player.cosinus = cosl(player.angle);
	player.sinus = sinl(player.angle);
	if (player.angle == M_PI / 2 || player.angle == 0 || player.angle == M_PI
		|| player.angle == 3 * M_PI / 2 || player.angle == 2 * M_PI)
		return (calcule_dist_exception(map, player));
	else
	{
		if (player.angle > 0 && player.angle < M_PI / 2)
			return (put_calcul(map, player, "NE"));
		else if (player.angle > M_PI / 2 && player.angle < M_PI)
			return (put_calcul(map, player, "NO"));
		else if (player.angle > M_PI && player.angle < 3 * M_PI / 2)
			return (put_calcul(map, player, "SO"));
		else if (player.angle > 3 * M_PI / 2 && player.angle < 2 * M_PI)
			return (put_calcul(map, player, "SE"));
		return (dist_h);
	}
}

void	printmap(char **map)
{
	int	i;

	i = 4;
	while (i >= 0)
	{
		printf("%s\n", map[i]);
		i--;
	}
}
