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
	if (parse_map(&data))
		ft_destroy_data(&data);
	initmlx (&data);
	ft_destroy_data(&data);
	return (0);
}
