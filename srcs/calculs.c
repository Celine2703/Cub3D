/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin <cmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:47:23 by cmartin           #+#    #+#             */
/*   Updated: 2023/11/23 08:47:23 by cmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "readFile.h"
#include <string.h>

t_wallhit	calcule_dist(t_map map, t_player player, double angle)
{
	t_wallhit	dist_h;

	ft_bzero(&dist_h, sizeof(t_wallhit));
	if (angle + player.angle >= 2 * M_PI)
		player.angle = fmod(player.angle + angle, 2 * M_PI);
	else if (angle + player.angle < 0)
		player.angle = 2 * M_PI + fmod(player.angle + angle, 2 * M_PI);
	else
		player.angle = fmod(player.angle + angle, 2 * M_PI);
	if (player.angle < 0 || player.angle > 2 * M_PI)
		scanf("%le", &player.angle);
	player.cosinus = cos(player.angle);
	player.sinus = sin(player.angle);
    //printf("player.angle = %f\n", player.angle);
	if (player.angle == M_PI / 2)
		return (calcule_vertical(map, player, 'N'));
	else if (player.angle == 3 * M_PI / 2)
		return (calcule_vertical(map, player, 'S'));
	else if (player.angle == 0 || player.angle == 2 * M_PI)
		return (calcule_horizontal(map, player, 'E'));
	else if (player.angle == M_PI)
		return (calcule_horizontal(map, player, 'O'));
	else
	{
		if (player.angle > 0 && player.angle < M_PI / 2)
			return (put_calcul(map, player, "NE"));
		else if (player.angle > M_PI / 2 && player.angle < M_PI)
			return (put_calcul(map, player, "NO"));
		else if (player.angle > M_PI && player.angle < 3 * M_PI / 2)
			return (put_calcul(map, player, "SO"));
		else if (player.angle > 3 * M_PI / 2 && player.angle < 2 * M_PI)
			return (put_calcul(map, player, "SE"));
		printf("NOOOOOOOOOOOOOOOOOOOO\n");
		printf("player.angle = %f\n", player.angle);
		return (dist_h);
	}
}

void	printmap(char **map)
{
	int	i;

	i = 4;
	while (i >= 0)
	{
		printf("%s\n", map[i]);
		i--;
	}
}

// int main() {
//     // Initialisation de la carte et du joueur
//     t_map map;
//     map.map_width = 5;
//     map.map_height = 5;
//     char tab[5][5]={"11111",
//                     "10001",
//                     "10011",
//                     "10001",
//                     "11111"};
//     map.tab = malloc(sizeof(char *) * map.map_height);
//     for (int i = 0; i < map.map_height; i++) {
//         map.tab[i] = malloc(sizeof(char) * map.map_width);
//         for (int j = 0; j < map.map_width; j++) {
//             map.tab[i][j] = tab[i][j];
//         }
//     }

//     t_player player;
//     player.posx = 2.5;
//     player.posy = 2.5;
//     player.angle = M_PI / 4.0;  // Angle de 45 degrés

//     // Tester les fonctions de calcul de distance
//     t_wallhit dist_h = calcule_dist(map, player, 0.0);  // Tester avec un angle de 0 degrés
//     t_wallhit dist_v = calcule_dist(map, player, M_PI / 4);  // Tester avec un angle de 90 degrés

//     // Afficher les résultats
//     printf("Distance horizontale : x=%.2f, y=%.2f, dist=%.2f, mur=%c\n", dist_h.x, dist_h.y, dist_h.dist, dist_h.mur);
//     printf("Distance verticale : x=%.2f, y=%.2f, dist=%.2f, mur=%c\n", dist_v.x, dist_v.y, dist_v.dist, dist_v.mur);

//     // Libérer la mémoire allouée pour la carte
//     for (int i = 0; i < map.map_height; i++) {
//         free(map.tab[i]);
//     }
//     free(map.tab);

//     return 0;
// }