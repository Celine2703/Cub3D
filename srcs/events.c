/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin <cmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:14:59 by cmartin           #+#    #+#             */
/*   Updated: 2023/10/26 22:18:05 by cmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//envoyer t_data, si touche z -> avance : changer data->player->pos(x ou y)
int	ft_key(int key, t_game *game)
{
	// if (key == 65307)
	// 	ft_destroy(game);
	ft_mov(game, &pos, key);
	ft_display_bis(game ->map, game ->mlx, &pos);
	return (0);
}