#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct s_wallhit
{
    double dist;
    double x;
    double y;
    int wall;
} t_wallhit;

typedef struct s_player
{
    double posx;
    double posy;
    double angle;
    double cosinus;
    double sinus;
} t_player;

t_wallhit calcule_horizontal(char  map[][10], t_player player);
t_wallhit calcule_vertical(char  map[][10], t_player player);
double calcule_y(t_player player, double x);
double calcule_x(t_player player, double y);
void printmap(char map[][10]);

#endif