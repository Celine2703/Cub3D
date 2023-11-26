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
# include "../minilibx-linux/mlx.h"

//calculs_utils.c
long double	calcule_y(t_player player, long double x);
long double	calcule_x(t_player player, long double y);
t_wallhit	calcule_horizontal(t_map map, t_player	player, char c);
t_wallhit	calcule_vertical(t_map map, t_player	player, char c);
t_wallhit	put_calcul(t_map map, t_player player, char *str);
//calculs.c
t_wallhit	calcule_dist_exception(t_map map, t_player player);
t_wallhit	calcule_dist(t_map map, t_player player, long double angle);
void		printmap(char **map);

//initmlx.c
int			textures_to_mlx(t_data *data);
int			initmlx(t_data *data);
//images.c
int			create_base_image(t_color f, t_color ceil, void *mlx, t_data *d);
int			selectcolor(t_data *data, t_wallhit wall, long double step);
t_wallhit	create_texture_coord(t_data *d, t_wallhit wall, long double step);

//events.c
int			ft_key(int key, t_data *data);
int			ft_mov(t_map map, t_player *player, int key);
void		ft_putdist_wall(t_wallhit distance, t_player *player);
void		ft_putmov(t_map map, t_player *player, long double angle);
void		ft_rotation(t_player *player, char c);

//clear.c
void		ft_mapclear(t_map *map);
void		ft_playerclear(t_player *player);
void		ft_dataclear(t_data *data);
int			ft_destroy_data(t_data *data);

// void		printrevsplit(char **split);
void		change_image(t_data *data);
void		rewriteline(t_data *data, int x, long double h, t_wallhit wall);
#endif