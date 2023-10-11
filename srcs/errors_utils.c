/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:27:48 by ccravero          #+#    #+#             */
/*   Updated: 2023/09/08 14:56:05 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readFile.h"

int	print_error_color(char c)
{
	printf("Error : color %c is already set\n", c);
	return (-1);
}

int	missinfo(t_data data)
{
	if (data.north == NULL)
		printf("north is missing\n");
	else if (data.east == NULL)
		printf("east is missing\n");
	else if (data.west == NULL)
		printf("west is missing\n");
	else if (data.south == NULL)
		printf("south is missing\n");
	else if (data.ceiling.red == -1)
		printf("ceiling is missing\n");
	else if (data.floor.red == -1)
		printf("floor is missing\n");
	else
		return (0);
	return (-1);
}
