#include "cub3d.h"
#include "../minilibx-linux/mlx.h"


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
// }
int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Create Image");

    void *image = mlx_new_image(mlx, 640, 360);
    
    // The following code goes here.
    int pixel_bits;
    int line_bytes;
    int endian;
    char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

    int color = 0xABCDEF;

    if (pixel_bits != 32)
        color = mlx_get_color_value(mlx, color);

    for(int y = 0; y < 360; ++y)
    for(int x = 0; x < 640; ++x)
    {
        int pixel = (y * line_bytes) + (x * 4);

        if (endian == 1)        // Most significant (Alpha) byte first
        {
            buffer[pixel + 0] = (color >> 24);
            buffer[pixel + 1] = (color >> 16) & 0xFF;
            buffer[pixel + 2] = (color >> 8) & 0xFF;
            buffer[pixel + 3] = (color) & 0xFF;
        }
        else if (endian == 0)   // Least significant (Blue) byte first
        {
            buffer[pixel + 0] = (color) & 0xFF;
            buffer[pixel + 1] = (color >> 8) & 0xFF;
            buffer[pixel + 2] = (color >> 16) & 0xFF;
            buffer[pixel + 3] = (color >> 24);
        }
    }
    mlx_put_image_to_window(mlx, win, image, 0, 0);

    mlx_loop(mlx);
}