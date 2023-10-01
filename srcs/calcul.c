#include "cub3d.h"

t_wallhit calcule_horizontal(char  map[][10], t_player player)
{
    t_wallhit wallhit;

    bzero(&wallhit, sizeof(t_wallhit)); // a mettre avec libft
    if (player.angle > 3*M_PI/2 || player.angle < M_PI/2)
        wallhit.x = ceil(player.posx);
    else
        wallhit.x = floor(player.posx);
    wallhit.y = player.posy + calcule_y(player, wallhit.x);
    while (map[(int)wallhit.y][(int)wallhit.x] != '1')
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

t_wallhit calcule_vertical (char  map[][10], t_player player)
{
    t_wallhit wallhit;

    bzero(&wallhit, sizeof(t_wallhit)); // a mettre avec libft
    if (player.angle > 0 && player.angle < M_PI)
        wallhit.y = ceil(player.posy);
    else
        wallhit.y = floor(player.posy);
    wallhit.x = player.posx + calcule_x(player, wallhit.y);
    while (map[(int)wallhit.y][(int)wallhit.x] != '1')
    {
        if (player.angle > 0 && player.angle < M_PI)
            wallhit.y++;
        else
            wallhit.y--;
        wallhit.x = player.posx + calcule_x(player, wallhit.y);
    }
    if (player.angle < M_PI)
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
    if (player.angle < M_PI/2 || player.angle > 3*M_PI/2)
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

t_wallhit calcule_dist(char  map[][10], t_player player)
{
    t_wallhit dist_h;
    t_wallhit dist_v;

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
        if (dist_h.dist < dist_v.dist)
            return (dist_h);
        else
            return (dist_v);
    }
}

void printmap(char map[][10])
{
    int i;

    i = 4;
    while(i >= 0)
    {
        printf("%s\n", map[i]);
        i--;
    }
}

int main()
{
    char map[10][10]={  "11111",
                        "10001",
                        "10011",
                        "10001",
                        "11111"};
    t_player player;
    
    player.posx = 1.5;
    player.posy = 1.5;
    player.angle = M_PI/2;

    
    printmap(map);
    printf("dist = %f\n", calcule_dist(map, player).dist);
    return (0);
}