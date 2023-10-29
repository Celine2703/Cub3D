#include "cub3d.h"
#include "../minilibx-linux/mlx.h"
#include "readfile.h"

void change_image(t_data *data);

int initmlx(t_data *data)
{
    data->mlx = mlx_init();
    if (data->mlx == NULL)
        return 1;
    data->win = mlx_new_window(data->mlx, 640, 640, "CUB1D");
    if (data->win == NULL)
        return 1;
    // create_base_image (data->floor, data->ceiling, data->mlx, data);
    // // change_image(data)
    // // calcule_dist(data->map.tab, data->player, 0);
    data->player.posx = 3;
    data ->player.posy = 3;
    data ->player.angle = 0;
    mlx_loop_hook(data->mlx, ft_key, data);
    // change_image(data);
    // mlx_put_image_to_window(data->mlx, data->win, data->base.image, 0, 0);
    mlx_loop(data->mlx);
    return 0;
}



void change_image(t_data *data)
{
    t_wallhit distance[640];
    int x = 0;
    double PI = -(2.0*M_PI)/9.0;

    // printf("map : %c\n" ,data->map.tab[0][0]);
    while (x < 640)
    {
        // printf ("PI = %f", PI);
        distance[x] = calcule_dist(data->map.tab, data->player, PI);
        printf("distance[%d] = %f\n", x, distance->dist);
        x++;
        PI += (4.0*M_PI)/(9.0 * 640.0);
    }
    (void )distance;
    
    // on commence par calculer la distance du mur pour chaque colonne
    // ensuite double boucle ou on parcours toute l'image pour mettre le pixel correspondant
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
// 	parseMap(&data);
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
