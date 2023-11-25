/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:47:02 by ccravero          #+#    #+#             */
/*   Updated: 2023/09/08 15:42:10 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../Libft/libft.h"
#include "readFile.h"
#include "structs.h"
#include "cub3d.h"

void	printinfo(t_data data)
{
	printf("filename = %s\n", data.filename);
	printf("nb_lines = %d\n", data.nb_lines);
	printf("north = %s\n", data.north);
	printf("south = %s\n", data.south);
	printf("west = %s\n", data.west);
	printf("east = %s\n", data.east);
	printf("ceiling = %d %d %d\n", data.ceiling.red,
		data.ceiling.green, data.ceiling.blue);
	printf("floor = %d %d %d\n", data.floor.red, data.floor.green,
		data.floor.blue);
	printf("map_width = %d\n", data.map.map_width);
	printf("map_height = %d\n", data.map.map_height);
	printf("map = \n");
	printsplit(data.map.tab);
	printf("player.posx = %Lf\n", data.player.posx);
	printf("player.posy = %Lf\n", data.player.posy);
	printf("player.angle = %Lf\n", data.player.angle);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)data;
	(void)argc;
	(void)argv;
	if (init_data(&data, argc, argv))
		return (1);
	if (parse_error(&data))
		return (1);
	// printinfo(data);
	if (parse_map(&data))
		ft_destroy_data(&data);
	printinfo(data);
	initmlx (&data);
	ft_destroy_data(&data);
	return (0);
}
