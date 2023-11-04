#include "cub3d.h"
#include "structs.h"
#include "../Libft/libft.h"

t_wallhit calcule_horizontal(t_map map, t_player player)
{
    t_wallhit wallhit;

    // printf("angle = %f\n", player.angle);
    ft_bzero(&wallhit, sizeof(t_wallhit)); // a mettre avec libft
    if (player.angle > 3 * M_PI / 2 || player.angle < M_PI/2)
        wallhit.x = ceil(player.posx);
    else
        wallhit.x = floor(player.posx);
    wallhit.y = player.posy + calcule_y(player, wallhit.x);
    // printf("x = %f\n", wallhit.x);
    // printf("y = %f\n", wallhit.y);
    // printf("angle calcule horizontal = %f\n", player.angle);
    if (wallhit.x < 0 || wallhit.y < 0 || wallhit.x > map.map_height || wallhit.y > map.map_width)
    {
            wallhit.dist = 999999999;
            return wallhit;
    }

    while (map.tab[(int)wallhit.y][(int)wallhit.x] != '1')
    {
        
        if (player.angle > 3*M_PI/2 || player.angle < M_PI/2)
            wallhit.x++;
        else
            wallhit.x--;
        wallhit.y = player.posy + calcule_y(player, wallhit.x);
        if (wallhit.x < 0 || wallhit.y < 0 || wallhit.x > map.map_height || wallhit.y > map.map_width)
        {
            wallhit.dist = 999999999;
            return wallhit;
        }
    }
    {
        if (player.angle > 3*M_PI/2 || player.angle < M_PI/2)
            wallhit.x++;
        else
            wallhit.x--;
        wallhit.y = player.posy + calcule_y(player, wallhit.x);
    }
    if (player.angle > M_PI/2 && player.angle < 3*M_PI/2)
    {
        wallhit.y = player.posy + calcule_y(player, ++wallhit.x);
        wallhit.mur = 'E';
    }
    else
        wallhit.mur = 'W';
    wallhit.dist = sqrt(pow(player.posx - wallhit.x, 2) + pow(player.posy - wallhit.y, 2));
    return (wallhit);
}

t_wallhit calcule_vertical(t_map  map, t_player player)
{
    t_wallhit wallhit;

    ft_bzero(&wallhit, sizeof(t_wallhit)); // a mettre avec libft
    if (player.angle > 0 && player.angle < M_PI)
        wallhit.y = ceil(player.posy);
    else
        wallhit.y = floor(player.posy);
    wallhit.x = player.posx + calcule_x(player, wallhit.y);

    if (wallhit.x < 0 || wallhit.y < 0 || wallhit.x > map.map_height || wallhit.y > map.map_width)
        {
            wallhit.dist = 999999999;
            return wallhit;
        }
    while (map.tab[(int)wallhit.y][(int)wallhit.x] != '1' && map.tab[(int)wallhit.y][(int)wallhit.x])
    {
        if (player.angle > 0 && player.angle < M_PI)
            wallhit.y++;
        else
            wallhit.y--;
        // printf("wallhit.y in calcul vert = %f\n", wallhit.y);
        wallhit.x = player.posx + calcule_x(player, wallhit.y);
        if (wallhit.x < 0 || wallhit.y < 0 || wallhit.x > map.map_height || wallhit.y > map.map_width)
        {
            wallhit.dist = 999999999;
            return wallhit;
        }
    }
    if (player.angle > M_PI)
    {
        wallhit.x = player.posx + calcule_x(player, ++wallhit.y);
        wallhit.mur = 'S';
    }
    else
        wallhit.mur = 'N';
    wallhit.dist = sqrt(pow(player.posx - wallhit.x, 2) + pow(player.posy - wallhit.y, 2));
    return (wallhit);
}

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

t_wallhit calcule_dist(t_map map, t_player player, double angle)
{
    t_wallhit dist_h;
    t_wallhit dist_v;
    player.angle = fmod(player.angle + angle, 2 * M_PI);
    player.cosinus = cos(player.angle);
    player.sinus = sin(player.angle);
    if (player.angle == M_PI/2 || player.angle == 3*M_PI/2)
        return(calcule_vertical(map, player));
    else if (player.angle == 0 || player.angle == M_PI)
        return(calcule_horizontal(map, player));
    else
    {
        dist_h = calcule_horizontal(map, player);
        dist_v = calcule_vertical(map, player);
        if (dist_h.dist >= 1000 && dist_v.dist >= 1000) // to delete
        {
            printf("BOTH dist invalide :");
            printf(" t_player.angle = %f\n", player.angle);
            printf(" horizontal wallhit.x = %f", dist_h.x);
            printf(" horizontal wallhit.y = %f\n", dist_h.y);
             printf("vertical wallhit.x = %f", dist_v.x);
            printf(" vertical wallhit.y = %f\n", dist_v.y);
        }
        // else if (dist_h.dist >= 1000) // to delete
        // {
        //     printf("horizontal dist invalide :");
        //     printf(" t_player.angle = %f\n", player.angle);
        //     printf(" wallhit.x = %f", dist_h.x);
        //     printf(" wallhit.y = %f\n", dist_h.y);
        // }
        // else if (dist_v.dist >= 1000)
        // {
        //     printf("vertical dist invalide :");
        //     printf("t_player.angle = %f\n", player.angle);
        //     printf(" wallhit.x = %f", dist_v.x);
        //     printf(" wallhit.y = %f\n", dist_v.y);

        // }

        if (dist_h.dist < dist_v.dist)
            return (dist_h);
        else
            return (dist_v);
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

// int main()
// {
//     char map[10][10]={  "11111",
//                         "10001",
//                         "10011",
//                         "10001",
//                         "11111"};
//     t_player player;
    
//     player.posx = 1.5;
//     player.posy = 1.5;
//     player.angle = M_PI/2;

    
//     printmap(map);
//     printf("dist = %f\n", calcule_dist(map, player).dist);
//     return (0);
// }