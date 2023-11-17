#include "cub3dbis.h"
#include "readFile.h"
#include <string.h>

double calcule_y(t_player player, double x)
{
    double A;
    double O;

    if (player.cosinus == 0)
        return (0);
    A = fabs(x - player.posx);
    O = (A / player.cosinus) * player.sinus;
    if (player.angle < M_PI / 2 || player.angle > 3 * M_PI / 2)
        return (O);
    else
        return (-O);
}

double calcule_x(t_player player, double y)
{
    double A;
    double O;

    if (player.sinus == 0)
        return (0);
    A = fabs(y - player.posy);
    O = (A / player.sinus) * player.cosinus;
    if (player.angle > 0 && player.angle < M_PI)
        return (O);
    else
        return (-O);
}

t_wallhit calcule_horizontal(t_map map, t_player player, char c)
{
    t_wallhit wallhit;

    bzero(&wallhit, sizeof(t_wallhit));
    if (c == 'E')
        wallhit.x = ceil(player.posx);
    else
        wallhit.x = floor(player.posx) - 0.001;

    wallhit.y = player.posy + calcule_y(player, wallhit.x);

    printf("x = %f, y = %f\n", wallhit.x, wallhit.y);
    printf("map.tab[%d][%d] = %c\n", (int)wallhit.y, (int)wallhit.x, map.tab[(int)wallhit.y][(int)wallhit.x]);
    printf("map.map_height = %d, map.map_width = %d\n", map.map_height, map.map_width);
    while (!(wallhit.x < 0 || wallhit.y < 0 || wallhit.x > map.map_width || wallhit.y > map.map_height) && map.tab[(int)wallhit.y][(int)wallhit.x] != '1')
    {
        if (c == 'E')
            wallhit.x++;
        else
            wallhit.x--;
        wallhit.y = player.posy + calcule_y(player, wallhit.x);
        if (wallhit.x < 0 || wallhit.y < 0 || wallhit.x > map.map_width || wallhit.y > map.map_height)
        {
            wallhit.dist = 999999999;
            return wallhit;
        }
        printf("x = %f, y = %f\n", wallhit.x, wallhit.y);
    }
    if (c == 'E')
        wallhit.mur = 'O';
    else
        wallhit.mur = 'E';
    wallhit.dist = sqrt(pow(player.posx - wallhit.x, 2) + pow(player.posy - wallhit.y, 2));
    return (wallhit);
}

t_wallhit calcule_vertical(t_map map, t_player player, char c)
{
    t_wallhit wallhit;

    bzero(&wallhit, sizeof(t_wallhit));
    if (c == 'N')
        wallhit.y = ceil(player.posy);
    else
        wallhit.y = floor(player.posy) - 0.001;

    wallhit.x = player.posx + calcule_x(player, wallhit.y);

    while (!(wallhit.x < 0 || wallhit.y < 0 || wallhit.x > map.map_width || wallhit.y > map.map_height) && map.tab[(int)wallhit.y][(int)wallhit.x] != '1')
    {
        if (c == 'N')
            wallhit.y++;
        else
            wallhit.y--;
        wallhit.x = player.posx + calcule_x(player, wallhit.y);
        if (wallhit.x < 0 || wallhit.y < 0 || wallhit.x > map.map_width || wallhit.y > map.map_height)
        {
            wallhit.dist = 999999999;
            return wallhit;
        }
    }
    if (c == 'N')
        wallhit.mur = 'S';
    else
        wallhit.mur = 'N';
    wallhit.dist = sqrt(pow(player.posx - wallhit.x, 2) + pow(player.posy - wallhit.y, 2));
    return (wallhit);
}

t_wallhit put_calcul(t_map map, t_player player, char *str)
{
    t_wallhit dist;

    if (strcmp(str, "NE") == 0)
        if (calcule_horizontal(map, player, 'E').dist < calcule_vertical(map, player, 'N').dist)
            dist = calcule_horizontal(map, player, 'E');
        else
            dist = calcule_vertical(map, player, 'N');
    else if (strcmp(str, "NO") == 0)
        if (calcule_horizontal(map, player, 'O').dist < calcule_vertical(map, player, 'N').dist)
            dist = calcule_horizontal(map, player, 'O');
        else
            dist = calcule_vertical(map, player, 'N');
    else if (strcmp(str, "SO") == 0)
        if (calcule_horizontal(map, player, 'O').dist < calcule_vertical(map, player, 'S').dist)
            dist = calcule_horizontal(map, player, 'O');
        else
            dist = calcule_vertical(map, player, 'S');
    else if (strcmp(str, "SE") == 0)
        if (calcule_horizontal(map, player, 'E').dist < calcule_vertical(map, player, 'S').dist)
            dist = calcule_horizontal(map, player, 'E');
        else
            dist = calcule_vertical(map, player, 'S');
    return (dist);
}

t_wallhit calcule_dist(t_map map, t_player player, double angle)
{
    t_wallhit dist_h;
    t_wallhit dist_v;
    if (angle + player.angle > 2 * M_PI)
        player.angle = fmod(player.angle + angle, 2 * M_PI) - 2 * M_PI;
    else if (angle + player.angle < 0)
        player.angle = 2 * M_PI + fmod(player.angle + angle, 2 * M_PI);
    else
        player.angle = fmod(player.angle + angle, 2 * M_PI);
    player.cosinus = cos(player.angle);
    player.sinus = sin(player.angle);

    printf("player.angle = %f\n", player.angle);
    if (player.angle == M_PI/2 || player.angle == 3*M_PI/2)
        return(calcule_vertical(map, player, 'N'));
    else if (player.angle == 0 || player.angle == M_PI)
        return(calcule_horizontal(map, player, 'E'));
    else
    {
        if (player.angle > 0 && player.angle < M_PI/2)
            dist_h = put_calcul(map, player, "NE");
        else if (player.angle > M_PI/2 && player.angle < M_PI)
            dist_h = put_calcul(map, player, "NO");
        else if (player.angle > M_PI && player.angle < 3*M_PI/2)
            dist_h = put_calcul(map, player, "SO");
        else if (player.angle > 3*M_PI/2 && player.angle < 2*M_PI)
            dist_h = put_calcul(map, player, "SE");
        return (dist_h);
    }
}

void printmap(char **map)
{
    int i;

    i = 4;
    while(i >= 0)
    {
        printf("%s\n", map[i]);
        i--;
    }
}

int main() {
    // Initialisation de la carte et du joueur
    t_map map;
    map.map_width = 5;
    map.map_height = 5;
    char tab[5][5]={"11111",
                    "10001",
                    "10011",
                    "10001",
                    "11111"};
    map.tab = malloc(sizeof(char *) * map.map_height);
    for (int i = 0; i < map.map_height; i++) {
        map.tab[i] = malloc(sizeof(char) * map.map_width);
        for (int j = 0; j < map.map_width; j++) {
            map.tab[i][j] = tab[i][j];
        }
    }

    t_player player;
    player.posx = 2.5;
    player.posy = 2.5;
    player.angle = M_PI / 4.0;  // Angle de 45 degrés

    // Tester les fonctions de calcul de distance
    t_wallhit dist_h = calcule_dist(map, player, 0.0);  // Tester avec un angle de 0 degrés
    t_wallhit dist_v = calcule_dist(map, player, M_PI / 4);  // Tester avec un angle de 90 degrés

    // Afficher les résultats
    printf("Distance horizontale : x=%.2f, y=%.2f, dist=%.2f, mur=%c\n", dist_h.x, dist_h.y, dist_h.dist, dist_h.mur);
    printf("Distance verticale : x=%.2f, y=%.2f, dist=%.2f, mur=%c\n", dist_v.x, dist_v.y, dist_v.dist, dist_v.mur);

    // Libérer la mémoire allouée pour la carte
    for (int i = 0; i < map.map_height; i++) {
        free(map.tab[i]);
    }
    free(map.tab);

    return 0;
}