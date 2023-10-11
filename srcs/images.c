#include "cub3d.h"
#include "../minilibx-linux/mlx.h"

int main(){
    void *mlx;
    void *win;
    int x;
    int y;
    int i;
    int j;
    int color;
    int map[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };
    (void)map;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 500, 500, "mlx 42");
    x = 0;
    y = 0;
    i = 0;
    j = 0;

    while (i < 250) // La moitié supérieure
    {
        while (j < 500)
        {
            color = 0x000000FF; // Bleu
            mlx_pixel_put(mlx, win, x, y, color);
            x++;
            j++;
        }
        x = 0;
        y++;
        i++;
        j = 0;
    }

    while (i < 500) // La moitié inférieure
    {
        while (j < 500)
        {
            color = 0x0000FF00; // Vert
            mlx_pixel_put(mlx, win, x, y, color);
            x++;
            j++;
        }
        x = 0;
        y++;
        i++;
        j = 0;
    }

    mlx_loop(mlx);
    return (0);
}
