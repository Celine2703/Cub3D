/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin <cmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:14:59 by cmartin           #+#    #+#             */
/*   Updated: 2023/10/27 09:47:07 by cmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_putmov(t_player player, double angle){
    if (player->angle >= 0 && player->angle <= M_PI/2)
        player->posx += cos(player->angle)*0.2;
        player->posy += sin(player->angle)*0.2;
    else if (player->angle >= M_PI/2 && player->angle < M_PI)
        player->posx -= cos(player->angle)*0.2;
        player->posy += sin(player->angle)*0.2;
    else if (player->angle >= M_PI && player->angle < 3*M_PI/2)
        player->posx -= cos(player->angle)*0.2;
        player->posy -= sin(player->angle)*0.2;
    else if (player->angle >= 3*M_PI/2 && player->angle <= 2*M_PI)
        player->posx += cos(player->angle)*0.2;
        player->posy -= sin(player->angle)*0.2;
}

int ft_mov(t_map map, t_player player, int key){
    if(key == 'w')
        ft_putmov(player, player->angle);
    else if(key == 'a')
        ft_putmov(player, player->angle + M_PI/2);
    else if(key == 's')
        ft_putmov(player, player->angle + M_PI);
    else if(key == 'd')
        ft_putmov(player, player->angle + 3*M_PI/2);
    return (0);
}

int ft_key(int key, t_data *data)
{
    if (key == 65307)
        ft_destroy(data);
    ft_mov(data.map, data.player, key);
    ft_display_bis(data.map, data->mlx, &pos);
    return (0);
}
