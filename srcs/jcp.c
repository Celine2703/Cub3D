#include "cub3d.h"

double calcdist(char  map[][10], double posx, double posy, double angle)
{
    double dist;
    double A;
    double x;
    double O;
    double y;
    A = posx;
    x = posx;
    printf("%f\n", A);
    O = posy;
    y = posy;
    printf("%f\n", y);
    printf("map = %c\n", map[(int)x][(int)y]);
    while (map[(int)x][(int)y] != '1')
    {
        //verifier si on est dans un mur pour les valeurs entières de x teste M_PI pour la valeur de M_PI
        if (angle <= M_PI/2 || angle >= 3*M_PI/2)
        {
            if (ceil(x) == x)
                x += 1;
            A = (ceil(x) - posx);
            x = posx + A;
        }
        else if (angle > M_PI/2 && angle < 3*M_PI/2)
        {
            if (floor(x) == x)
                x -= 1;
            A = (posx - floor(x));
            x = posx - A;
        }
        printf("x %f\n", x);
        if (angle == M_PI/2 || angle == 3*M_PI/2)
            O = 1;
        else
            O = (A / cos(angle)) * sin(angle);
        if (O < 0)
            O = -O;
        if (angle <= M_PI)
            y = posy + O;
        else if (angle > M_PI)
            y = posy - O;
        printf("O %f\n", O);
        printf("y %f\n", y);
        printf("map = %c\n", map[(int)x][(int)y]);
    }
    dist = sqrt(pow(posx - x, 2) + pow(posy - y, 2));
    // printf("pos x - x => %f -%f \n", posx, x);
    // printf("pos y - y => %f -%f \n", posy, y);
    return (dist);
}

double calcdistbis(char  map[][10], double posx, double posy, double angle)
{
    double dist;
    double A;
    double x;
    double O;
    double y;
    double newangle;

    if (angle <= M_PI/2)
        newangle = M_PI/2 - angle;
    else if (angle > M_PI/2 && angle <= M_PI)
        newangle = angle - M_PI/2;
    else if (angle > M_PI && angle <= 3*M_PI/2)
        newangle = 3*M_PI/2 - angle;
    else if (angle > 3*M_PI/2)
        newangle = angle - 3*M_PI/2;

    printf("newangle = %f\n", newangle);
    A = posx;
    x = posx;
    printf("%f\n", A);
    O = posy;
    y = posy;
    printf("%f\n", y);
    printf("map = %c\n", map[(int)x][(int)y]);
    while (map[(int)x][(int)y] != '1')
    {
        //verifier si on est dans un mur pour les valeurs entières de x teste M_PI pour la valeur de pi
        if (angle <= M_PI/2 || angle > 3*M_PI/2)
        {
            if (ceil(y) == y)
            y += 1;
            A = (ceil(y) - posy);
            y = posy + A;
        }
        else if (angle > M_PI/2 && angle <= 3*M_PI/2)
        {
            if (floor(y) == y)
                y -= 1;
            A = (posy - floor(y));
            y = posy - A;
        }
        printf("y %f\n", y);
        if (angle == M_PI/2 || angle == 3*M_PI/2)
            O = 0;
        else
            O = (A / cos(angle)) * sin(angle);
        printf("O %f\n", O);
        if (O < 0)
            O = -O;
        if (angle <= M_PI)
            x = posx + O;
        else if (angle > M_PI)
            x = posx - O;
        x = posx + O;
        printf("x %f\n", x);
        printf("map = %c\n", map[(int)x][(int)y]);
    }
    dist = sqrt(pow(posx - x, 2) + pow(posy - y, 2));
    // printf("pos x - x => %f -%f \n", posx, x);
    // printf("pos y - y => %f -%f \n", posy, y);
    return (dist);
}


void printmap(char map[][10], double posx, double posy)
{
    int i;
	int j;

    i = 4;
	while(i >= 0)
    {
		j = 0;
		while (map[i][j])
		{
			if (i == (int)posx && j == (int)posy)
        		printf("P");
			printf("%c", map[i][j]);

			j++;
		}
		printf("\n");
		i--;
    }
}

// int main()
// {
//     char map[10][10]={  "11111",
//                         "10001",
//                         "10001",
//                         "10001",
//                         "11111"};
//     double posx;
//     double posy;
//     double angle;
    
//     posx = 1.5;
//     posy = 1.5;
//     angle = M_PI; // (1,2) -> 0,7071067811865475
    
//     printmap(map, posx, posy);
//     printf("%c\n", map[(int)posx][(int)posy]);
//     printf(" RES 1   %f\n", calcdist(map, posx, posy, angle));
//     printf(" RES 2   %f\n", calcdistbis(map, posx, posy, angle));
//     return (0);
// }
