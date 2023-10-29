/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:14:59 by cmartin           #+#    #+#             */
/*   Updated: 2023/10/29 22:07:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "readFile.h"

void    ft_putmov(t_map map, t_player *player, double angle){
    player->angle = angle;
    t_wallhit distance = calcule_dist(map.tab, *player, 0);
    printf ("distance = %f\n", distance.dist);
    printf("distance.x = %f\n", distance.x);
    printf("distance.y = %f\n", distance.y);
    if (distance.dist <= 0.21)
    {
        if (distance.x == floor(distance.x))
            player->posx = distance.x - 0.01;
        else
            player->posx = distance.x;
        if ( distance.y == floor(distance.y))
            player->posy = distance.y - 0.01;
        else
            player->posy = distance.y;
    }
    else
    {
        player->posx += 0.2 * cos(angle);
        player->posy += 0.2 * sin(angle);
    }
}

void    ft_rotation(t_player *player, char c)
{
    double rotation;

    rotation = M_PI/30;
    if (c == 'd')
    {
        if (player->angle - rotation < 0)
            player->angle = 2*M_PI - rotation;
        else
            player->angle -= rotation;
    }
    else if (c == 'g')
        player->angle += rotation;
}

int ft_mov(t_map map, t_player *player, int key){
    double prevangle;

    prevangle = player->angle;
    if(key == 'w')
        ft_putmov(map, player, player->angle);
    else if(key == 'a')
        ft_putmov(map, player, fmod(player->angle + M_PI/2, 2 * M_PI));
    else if(key == 's')
        ft_putmov(map, player, fmod(player->angle + M_PI, 2 * M_PI));
    else if(key == 'd')
        ft_putmov(map, player, fmod(player->angle + 3*M_PI/2, 2 * M_PI));
    player->angle = prevangle;
    if(key == 65361)
        ft_rotation(player, 'g');
    else if(key == 65363)
        ft_rotation(player, 'd');
    return (0);
}

int ft_key(int key, t_data *data)
{
    if (key == 65307)
        ft_destroy_data(data);
    if (data -> player.angle == 2 * M_PI)
        data -> player.angle = 0;
    ft_mov(data->map, &(data->player), key);
    printf("posx = %f\n", data->player.posx);
    printf("posy = %f\n", data->player.posy);
    printf("angle ft key = %f\n", data->player.angle);
    //ft_display_bis(data->map, data->mlx, &pos);
    return (0);
}
