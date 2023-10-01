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

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 1000, "mlx 42");
    x = 0;
    y = 0;
    i = 0;
    j = 0;
    while (i < 10)
    {
        while (j < 10)
        {
            if (map[i][j] == 1)
                color = 0x00FF0000;
            else
                color = 0x0000FF00;
            mlx_pixel_put(mlx, win, x, y, color);
            x += 100;
            j++;
        }
        x = 0;
        y += 100;
        i++;
        j = 0;
    }
    mlx_loop(mlx);
    return (0);
}