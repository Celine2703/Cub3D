/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:14:59 by cmartin           #+#    #+#             */
/*   Updated: 2023/10/29 17:53:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "readFile.h"

void    ft_putmov(t_player *player, double angle){
    if (player->angle >= 0 && player->angle <= M_PI/2)
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

// void    ft_movbis(t_map map, t_player *player, int key){
//     if(key == 'w')
//         ft_putmov(player, player->angle);
//     else if(key == 'a')
//         player->angle += M_PI/20;
//     else if(key == 's')
//         ft_putmov(player, player->angle + M_PI);
//     else if(key == 'd')
//         player->angle -= M_PI/20;
// }

int ft_mov(t_map map, t_player *player, int key){
    if(key == 'w')
        ft_putmov(player, player->angle);
    else if(key == 'a')
        ft_putmov(player, player->angle + M_PI/2);
    else if(key == 's')
        ft_putmov(player, player->angle + M_PI);
    else if(key == 'd')
        ft_putmov(player, player->angle + 3*M_PI/2);
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
