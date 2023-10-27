/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:59:21 by marvin            #+#    #+#             */
/*   Updated: 2023/10/27 12:59:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "structs.h"

t_wallhit	calcule_horizontal(char	**map, t_player	player);
t_wallhit	calcule_vertical(char	**map, t_player	player);
double		calcule_y(t_player player, double x);
double		calcule_x(t_player player, double y);
t_wallhit	calcule_dist(char **map, t_player player, double angle);
void		printmap(char **map);

int			initmlx(t_data *data);
int			create_base_image(t_color f, t_color ceil, void *mlx, t_data *d);

#endif