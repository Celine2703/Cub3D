#include "cub3d.h"
#include "../minilibx-linux/mlx.h"
#include "readFile.h"


int selectcolor(t_data *data, t_wallhit wall, long double step);
t_wallhit create_texture_coord(t_data * data, t_wallhit wall, long double step);

void printwallhit(t_wallhit wh)
{
    printf("wallhit.x = %Lf\n", wh.x);
    printf("wallhit.y = %Lf\n", wh.y);
    printf("wallhit.dist = %Lf\n", wh.dist);
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
    long double height;
    int x = 0;
    long double PI = (2.0 * M_PI)/9.0;

    // printf("map : %c\n" ,data->map.tab[0][0]);
	while (x < 640)
	{
		distance[x] = calcule_dist(data->map, data->player, PI);
		distance[x].dist = distance[x].dist * cosl(PI);
		x++;
		PI -= (4.0*M_PI)/(9.0 * 640.0);
	}
	x = 0;
    while (x < 640)
    {
        // printf ("PI = %f", PI);
        if (x != 0 && x != 639 && distance[x-1].mur != distance[x].mur && distance[x - 1].mur == distance[x + 1].mur)
		{
			printf("coucou\n");
			distance[x].mur = distance[x - 1].mur;
		}
        // distance[x].dist = distance[x].dist * cosl(PI);
        height = 160/distance[x].dist;
        rewriteline(data, x, height,distance[x]);
        // printf("distance[%d] = %f\n", x, distance->dist);
        // printf("height = %f\n", height);
        // printf("angle : %f\n", PI);
        x++;
        
	}
    mlx_put_image_to_window(data->mlx, data->win, data->base.image, 0, 0);
    
    // on commence par calculer la distance du mur pour chaque colonne
    // ensuite double boucle ou on parcours toute l'image pour mettre le pixel correspondant
}

void	rewriteline(t_data *data, int x, long double height,t_wallhit wall)
{
    int		y;
    char	*pixel;
    long double test = height;
    y = 0;
    // printf ("pointer = %p\n", data->base.addr);
    // if (test > 320)
    // {
    //    test = (test - 320) /2.0;
    //    create_texture_coord(0, wall, (test*320)/320);
    // }
    while (test > 320)
	{
		create_texture_coord(data, wall, 64.0 / (height * 64.0));
		test -= 64.0 / (height * 2.0);
        // printf("test = %f\n", test);
	}

    while (y < 640)
	{
 		pixel = data->base.addr + y * data->base.sizeline + x * data->base.bpp / 8;
		if (y > (640 / 2.0 + height))
			*(int *) pixel = data->ceiling.color;
		else if (y < (640 / 2.0 - height))
			*(int *) pixel = data->floor.color;
		else
		{
            
            *(int *) pixel = selectcolor(data, wall, 64.0/(height * 2));
			// *(int *) pixel = selectcolor(data, wall, 64.0/(height * 2.0));
            // *(int *) pixel = 0x00FF0000;
		}
		y++;
	}
    create_texture_coord(0, wall, 0);
}


t_wallhit create_texture_coord(t_data * data, t_wallhit wall, long double step)
{
    t_wallhit texture_coordinate;
    static long double	y;
    
    if (!data)
	{
		y = step;
        if (y != 0)
            printf("y = %Lf\n", y);
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
    // if (texture_coordinate.x > 63 || texture_coordinate.x < 0 || texture_coordinate.y > 63 || texture_coordinate.y < 0)
    // {

    //     printf("texture_coordinate.x = %f\n", texture_coordinate.x);
    //     printf("texture_coordinate.y = %f\n", texture_coordinate.y);
    //     printf("y = %f\n", y);
    //     printf("step = %f\n", step);
    //     printf("complete : %f\n", step*640.0);
    // }
    y+= step;
    return (texture_coordinate);
}

int selectcolor(t_data *data, t_wallhit wall, long double step)
{
    int color;
    char *pixel;
    t_wallhit texture_coordinate;
    (void)pixel;
    // printf ("wall.x = %f\n", wall.x);
    // printf ("wall.y = %f\n", wall.y);
    // printf ("wall.dist = %f\n", wall.dist);
    // printf ("wall.mur = %c\n", wall.mur);
    // printf("data = %p\n", data);
    texture_coordinate = create_texture_coord(data, wall, step);
    // printf ("step = %f\n", step);
    if (wall.mur == 'E')
        wall.mur = 0;
    else if (wall.mur == 'O')
        wall.mur = 1;
    else if (wall.mur == 'N')
        wall.mur = 2;
    else if (wall.mur == 'S')
        wall.mur = 3;
    // printf("data->textures[%d].addr = %p\n",wall.mur, data->textures[wall.mur].addr);
    pixel = data->textures[wall.mur].addr
		+ (int)texture_coordinate.x * data->textures[wall.mur].sizeline
		+ (int)texture_coordinate.y * data->textures[wall.mur].bpp / 8;
    // printf("pixel = %p\n", pixel);
    
	color = *(int*)pixel;
	return (color);
    
}
// int main(){
//     void *mlx;
//     void *win;
//     int x;
//     int y;
//     int i;
//     int j;
//     int color;
//     int map[10][10] = {
//         {1,1,1,1,1,1,1,1,1,1},
//         {1,0,0,0,1,0,0,0,0,1},
//         {1,0,0,0,1,0,0,0,0,1},
//         {1,0,0,0,1,0,0,0,0,1},
//         {1,1,1,1,1,1,1,1,1,1},
//         {1,0,0,0,1,0,0,0,0,1},
//         {1,0,0,0,1,0,0,0,0,1},
//         {1,0,0,0,1,0,0,0,0,1},
//         {1,0,0,0,1,0,0,0,0,1},
//         {1,1,1,1,1,1,1,1,1,1}
//     };
//     (void)map;
//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 500, 500, "mlx 42");
//     x = 0;
//     y = 0;
//     i = 0;
//     j = 0;

//     while (i < 250) // La moitié supérieure
//     {
//         while (j < 500)
//         {
//             color = 0x000000FF; // Bleu
//             mlx_pixel_put(mlx, win, x, y, color);
//             x++;
//             j++;
//         }
//         x = 0;
//         y++;
//         i++;
//         j = 0;
//     }

//     while (i < 500) // La moitié inférieure
//     {
//         while (j < 500)
//         {
//             color = 0x0000FF00; // Vert
//             mlx_pixel_put(mlx, win, x, y, color);
//             x++;
//             j++;
//         }
//         x = 0;
//         y++;
//         i++;
//         j = 0;
//     }

//     mlx_loop(mlx);
//     return (0);
// // }
// int main()
// {
    
//     t_data	data;

// 	if (init_data(&data, argc, argv))
// 		return (0);
// 	if (parse_error(&data))
// 		return (0);
	
// 	// printinfo(data);
// 	parse_map(&data);
// 	destroy_data(&data);
//     // void *mlx = mlx_init();
//     // void *win = mlx_new_window(mlx, 640, 640, "CUB1D");

//     // t_data data; 

//     // ft_bzero(&data, sizeof(t_data));
//     // t_color ceil, floor;

//     // ceil.color = 0x00FF00;
//     // floor.color = 0x0000FF;
//     // create_base_image (ceil, floor, mlx, &data);

//     // void *image = mlx_new_image(mlx, 640, 360);
    

//     // // The following code goes here.
//     // int pixel_bits;
//     // int line_bytes;
//     // int endian;
//     // char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
//     // // printf("pixel_bits: %d\n", pixel_bits);
//     // // printf("line_bytes: %d\n", line_bytes);
//     // // printf("endian: %d\n", endian);
//     // int color = 0xFFFFFF;
//     // int color2 = 0x000000;

//     // if (pixel_bits != 32)
//     //     color = mlx_get_color_value(mlx, color);

//     // for(int y = 0; y < 360; ++y)
//     // {
//     //     for(int x = 0; x < 640; ++x)
//     //     {
//     //         int pixel = (y * line_bytes) + (x * 4);

//     //         if (endian == 1)        // Most significant (Alpha) byte first
//     //         {
//     //             buffer[pixel + 0] = (color >> 24);
//     //             buffer[pixel + 1] = (color >> 16) & 0xFF;
//     //             buffer[pixel + 2] = (color >> 8) & 0xFF;
//     //             buffer[pixel + 3] = (color) & 0xFF;
//     //         }
//     //         else if (endian == 0)   // Least significant (Blue) byte first
//     //         {
//     //             buffer[pixel + 0] = (color) & 0xFF;
//     //             buffer[pixel + 1] = (color >> 8) & 0xFF;
//     //             buffer[pixel + 2] = (color >> 16) & 0xFF;
//     //             buffer[pixel + 3] = (color >> 24);
//     //         }
//     //         if (endian == 1 && y > 300)        // Most significant (Alpha) byte first
//     //         {
                
//     //             buffer[pixel + 0] = (color2 >> 24);
//     //             buffer[pixel + 1] = (color2 >> 16) & 0xFF;
//     //             buffer[pixel + 2] = (color2 >> 8) & 0xFF;
//     //             buffer[pixel + 3] = (color2) & 0xFF;
//     //         }
//     //         else if (endian == 0 && y > 300)   // Least significant (Blue) byte first
//     //         {
//     //             buffer[pixel + 0] = (color2) & 0xFF;
//     //             buffer[pixel + 1] = (color2 >> 8) & 0xFF;
//     //             buffer[pixel + 2] = (color2 >> 16) & 0xFF;
//     //             buffer[pixel + 3] = (color2 >> 24);
//     //         }

//     //     }
//     // }
//     // mlx_put_image_to_window(mlx, win, data.base.image, 0, 0);

//     // mlx_loop(mlx);
// }

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
