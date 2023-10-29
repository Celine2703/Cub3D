/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:14:59 by cmartin           #+#    #+#             */
/*   Updated: 2023/10/29 20:28:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "readFile.h"

void    ft_putmov(t_player *player, double angle){
    if (calcule_dist(map.tab, *player, angle).dist < 0.2)
    {
        player->posx = calcule_dist(map.tab, *player, 0).x;
        player->posy = calcule_dist(map.tab, *player, 0).y;
    }
    else if (player->angle >= 0 && player->angle <= M_PI/2)
    {
        player->posx += cos(angle)*0.2;
        player->posy += sin(angle)*0.2;
    }
    else if (player->angle >= M_PI/2 && player->angle < M_PI)
    {
        player->posx -= cos(angle)*0.2;
        player->posy += sin(angle)*0.2;
    }
    else if (player->angle >= M_PI && player->angle < 3*M_PI/2)
    {
        player->posx -= cos(angle)*0.2;
        player->posy -= sin(angle)*0.2;
    }
    else if (player->angle >= 3*M_PI/2 && player->angle <= 2*M_PI)
    {
        player->posx += cos(angle)*0.2;
        player->posy -= sin(angle)*0.2;
    }
}

void    ft_rotation(t_player *player, char c)
{
    double rotation;

    rotation = M_PI/30;
    if (player->angle == 2 * M_PI)
        player->angle = 0;
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
    if(key == 'w')
        ft_putmov(player, player->angle);
    else if(key == 'a')
        ft_putmov(player, player->angle + M_PI/2);
    else if(key == 's')
        ft_putmov(player, player->angle + M_PI);
    else if(key == 'd')
        ft_putmov(player, player->angle + 3*M_PI/2);
    else if(key == 65361)
        ft_rotation(player, 'g');
    else if(key == 65363)
        ft_rotation(player, 'd');
    (void)map; // il faut vérifier si le joueur est dans un mur
    return (0);
}

int ft_key(int key, t_data *data)
{
    if (key == 65307)
        ft_destroy_data(data);
    ft_mov(data->map, &(data->player), key);
    printf("posx = %f\n", data->player.posx);
    printf("posy = %f\n", data->player.posy);
    printf("angle = %f\n", data->player.angle);
    //ft_display_bis(data->map, data->mlx, &pos);
    return (0);
}
