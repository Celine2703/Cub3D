/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:08:27 by marvin            #+#    #+#             */
/*   Updated: 2023/10/27 13:08:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_player
{
	double	posx;
	double	posy;
	double	angle;
	double	cosinus;
	double	sinus;
}	t_player;

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
	int			color;
}	t_color;

typedef struct s_map
{
	char		**tab;
	int			map_width;
	int			map_height;
}	t_map;

typedef struct s_pair
{
	int			first;
	int			second;
}	t_pair;

typedef struct s_wallhit
{
	double	dist;
	double	x;
	double	y;
	int			mur;
}	t_wallhit;

typedef struct s_image
{
	void		*image;
	char		*addr;
	int			bpp;
	int			sizeline;
	int			endian;
}	t_image;

typedef struct s_data
{
	char		**file;
	char		*filename;
	t_map		map;
	t_player	player;
	int			nb_lines;
	t_color		ceiling;
	t_color		floor;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	t_image		base;
	void		*mlx;
	void		*win;
	t_image		textures[4];
}	t_data;

#endif