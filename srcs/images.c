#include "cub3d.h"
#include "../minilibx-linux/mlx.h"
#include "readFile.h"


int selectcolor(t_data *data, t_wallhit wall, double step);
t_wallhit create_texture_coord(t_data * data, t_wallhit wall, double step);

void printwallhit(t_wallhit wh)
{
    printf("wallhit.x = %f\n", wh.x);
    printf("wallhit.y = %f\n", wh.y);
    printf("wallhit.dist = %f\n", wh.dist);
    printf("wallhit.mur = %c\n", wh.mur);
}

void printmappos(t_data data)
{
    int i = data.map.map_height - 1;
    int j = 0;
    while (i >= 0)
    {
        j = 0;
        while (j < data.map.map_width)
        {
            if (i == (int)data.player.posy && j == (int)data.player.posx)
                printf("P");
            else
                printf("%c", data.map.tab[i][j]);
            j++;
        }
        printf("\n");
        i--;
    }
}

int initmlx(t_data *data)
{
     int taille;

     taille = 64;
    data->mlx = mlx_init();
    if (data->mlx == NULL)
        return 1;
    data->win = mlx_new_window(data->mlx, 640, 640, "CUB3D");
    if (data->win == NULL)
        return 1;
    create_base_image (data->floor, data->ceiling, data->mlx, data);
    // // change_image(data)
    // // calcule_dist(data->map.tab, data->player, 0);
    data->textures[0].image = mlx_xpm_file_to_image(data->mlx, data->east, &taille, &taille);
    if (data->textures[0].image == NULL)
    {
        printf("error texture\n");
        return 1;
    }
    data->textures[0].addr = mlx_get_data_addr(data->textures[0].image, &data->textures[0].bpp, &data->textures[0].sizeline, &data->textures[0].endian);
    data->textures[1].image = mlx_xpm_file_to_image(data->mlx, data->west, &taille, &taille);
    if (data->textures[1].image == NULL)
    {
        printf("error texture\n");
        return 1;
    }
    data->textures[1].addr = mlx_get_data_addr(data->textures[1].image, &data->textures[1].bpp, &data->textures[1].sizeline, &data->textures[1].endian);
    data->textures[2].image = mlx_xpm_file_to_image(data->mlx, data->north, &taille, &taille);
    if (data->textures[2].image == NULL)
    {
        printf("error texture\n");
        return 1;
    }
    data->textures[2].addr = mlx_get_data_addr(data->textures[2].image, &data->textures[2].bpp, &data->textures[2].sizeline, &data->textures[2].endian);
    data->textures[3].image = mlx_xpm_file_to_image(data->mlx, data->south, &taille, &taille);
    if (data->textures[3].image == NULL)
    {
        printf("error texture\n");
        return 1;
    }
    data->textures[3].addr = mlx_get_data_addr(data->textures[3].image, &data->textures[3].bpp, &data->textures[3].sizeline, &data->textures[3].endian);
    
    if (data->textures[0].image == NULL || data->textures[1].image == NULL || data->textures[2].image == NULL || data->textures[3].image == NULL)
    {
        printf("error texture\n");
        return 1;
    }
    // printf("angle in image = %f\n", data->player.angle);
    // printf("dist.x : %f\n", calcule_dist(data->map.tab, data->player,0).x);
    // printf("dist.y : %f\n", calcule_dist(data->map.tab, data->player,0).y);
    // change_image(data);
    mlx_hook(data->win, 02, 1L << 0, ft_key, data);
    mlx_hook(data->win, 17, 0, ft_destroy_data, data);
    
   

    
    // mlx_put_image_to_window(data->mlx, data->win, data->textures[0].image, 0, 0);
    // mlx_put_image_to_window(data->mlx, data->win, data->textures[1].image, 0, 64);
    // mlx_put_image_to_window(data->mlx, data->win, data->textures[2].image, 0, 128);
    // // mlx_put_image_to_window(data->mlx, data->win, data->textures[3].image, 0, 192);
    // t_player player;
    // t_wallhit distance;
    // distance.x = 2;
    // distance.y = 6.941;
    // distance.dist = 5.941;
    // distance.mur = 'O';

    // (void)distance;
    // selectcolor(data, distance, 0.5441461);
    // data->player.angle =  1.63;
    // data->player.posx = 38.5;
    // data->player.posy = 13.5;

    // data->player.angle =  4.712389;
    // data->player.posx = 26.5;
    // data->player.posy = 1.9;
    // t_wallhit distance;
    // distance = calcule_dist(data->map, data->player, 0);
    // distance.dist = 320/distance.dist ;
    // rewriteline(data, 320, distance.dist, distance);
    // player.angle = 0.00000;
    // data->player= player;
    // calcule_vertical(data->map, data->player);
    // // t_wallhit distance = calcule_dist(data->map, player, M_PI/30);
    // printf ("calculdist = %f\n", distance.dist);
    // printmappos(*data);
    // printrevsplit(data->map.tab);
    // t_wallhit distanceeast = calcule_dist(data->map, data->player,0);
    // printwallhit(distanceeast);
    change_image(data);
    mlx_loop(data->mlx);
    return 0;
}

void change_image(t_data *data)
{
    t_wallhit distance[640];
    double height;
    int x = 0;
    double PI = M_PI / 6.1;

	while (x < 640)
	{
		distance[x] = calcule_dist(data->map, data->player, PI);
		distance[x].dist = distance[x].dist * cos(PI);
		x++;
		PI -= (M_PI / 3) / 640.0;
	}
	x = 0;
    while (x < 640)
    {
        if (x != 0 && x != 639 && distance[x-1].mur != distance[x].mur && distance[x - 1].mur == distance[x + 1].mur)
		{
			printf("coucou\n");
			distance[x].mur = distance[x - 1].mur;
		}
        height = 320/distance[x].dist;
        rewriteline(data, x, height,distance[x]);
        x++;
        
	}
    mlx_put_image_to_window(data->mlx, data->win, data->base.image, 0, 0);
}

void	rewriteline(t_data *data, int x, double height,t_wallhit wall)
{
    int		y;
    char	*pixel;
    int 	test; 
	
	test = height;
    y = 0;
    while (test > 320.0)
	{
		create_texture_coord (data , wall, 64.0/(height * 2));
		test = test - 64.0/(height * 2);
	}
    while (y < 640)
	{
 		pixel = data->base.addr + y * data->base.sizeline + x * data->base.bpp / 8;
		if (y > (640.0 / 2.0 + height))
			*(int *) pixel = data->ceiling.color;
		else if (y < (640.0 / 2.0 - height))
			*(int *) pixel = data->floor.color;
		else
            *(int *) pixel = selectcolor(data, wall, 64.0/(height * 2));
		y++;
	}
    create_texture_coord(0, wall, 0);
}


t_wallhit create_texture_coord(t_data * data, t_wallhit wall, double step)
{
    t_wallhit texture_coordinate;
    static double	y;
    
    if (!data)
	{
		y = step;
		return (wall);
	}
   
    if (wall.mur == 'O' || wall.mur == 'E')
	{
		texture_coordinate.y = (wall.y - (int)wall.y) * 64;
	}
	else
	{
		texture_coordinate.y = (wall.x - (int)wall.x) * 64;
	}
	texture_coordinate.x = floor(y);
    y+= step;
    return (texture_coordinate);
}

int selectcolor(t_data *data, t_wallhit wall, double step)
{
    int color;
    char *pixel;
    t_wallhit texture_coordinate;
    (void)pixel;
    texture_coordinate = create_texture_coord(data, wall, step);
    if (wall.mur == 'E')
        wall.mur = 0;
    else if (wall.mur == 'O')
        wall.mur = 1;
    else if (wall.mur == 'N')
        wall.mur = 2;
    else if (wall.mur == 'S')
        wall.mur = 3;
    pixel = data->textures[wall.mur].addr
		+ (int)texture_coordinate.x * data->textures[wall.mur].sizeline
		+ (int)texture_coordinate.y * data->textures[wall.mur].bpp / 8;
    
	color = *(int*)pixel;
	return (color);
    
}

int create_base_image (t_color floor, t_color ceiling, void *mlx, t_data *data) 
{
    int x;
    int y;
    char *pixel;

    data->base.image = mlx_new_image(mlx, 640, 640);
    if (data->base.image == NULL)
        return 1;
    data->base.addr = mlx_get_data_addr(data->base.image, &data->base.bpp, &data->base.sizeline, &data->base.endian);
    printf("bpp: %d, sizeline: %d, endian: %d\n", data->base.bpp, data->base.sizeline/4, data->base.endian);
    y = 0;
    while (y < 640)
    {
        x = 0;
        while (x < 640)
        {
            pixel = data->base.addr + y * data->base.sizeline + x * data->base.bpp / 8;
            *(int *) pixel = floor.color;
			if (y > (640 / 2))
				*(int *) pixel = ceiling.color;
			x++;
        }
        y++;
    }
    return 0;
}

int changepixel(int x, int y, t_color color, t_data *data)
{
    char * pixel;
    pixel = data->base.addr + y * data->base.sizeline + x * data->base.bpp / 8;
    *(int *)pixel = color.color;
    return 0;
}
