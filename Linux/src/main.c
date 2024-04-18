#include "../header/fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv)
	{
		usage_arguments();
	}
	fdf_start(argv[1]);
	return (0);
}






















// #define WIDTH 800
// #define HEIGHT 600

// typedef struct s_vars {
//     void *mlx;
//     void *win;
//     int rect_width;
//     int rect_height;
//     int rect_x;
//     int rect_y;
//     float rotation_angle;
// } t_vars;

// void draw_rect(t_vars *vars)
// {
//     int i;
//     int j;
//     float angle = vars->rotation_angle;
//     int half_width = vars->rect_width / 2;
//     int half_height = vars->rect_height / 2;
//     int new_x, new_y;

//     for (i = vars->rect_x - half_width; i < vars->rect_x + half_width; i++)
//     {
//         for (j = vars->rect_y - half_height; j < vars->rect_y + half_height; j++)
//         {
//             new_x = (int)((i - vars->rect_x) * cos(angle) - (j - vars->rect_y) * sin(angle) + vars->rect_x);
//             new_y = (int)((i - vars->rect_x) * sin(angle) + (j - vars->rect_y) * cos(angle) + vars->rect_y);
//             mlx_pixel_put(vars->mlx, vars->win, new_x, new_y, 0xFFFFFF);
//         }
//     }
// }

// int key_hook(int keycode, t_vars *vars)
// {
//     if (keycode == 53) // ESC key
//     {
//         mlx_destroy_window(vars->mlx, vars->win);
//         exit(0);
//     }
//     return (0);
// }

// int update_frame(t_vars *vars)
// {
//     mlx_clear_window(vars->mlx, vars->win);
//     vars->rotation_angle += 0.01; // Increment rotation angle
//     draw_rect(vars);
//     return (0);
// }

// int main()
// {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Rotate Rectangle");
//     vars.rect_width = 200;
//     vars.rect_height = 100;
//     vars.rect_x = WIDTH / 2;
//     vars.rect_y = HEIGHT / 2;
//     vars.rotation_angle = 0;

//     mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
//     mlx_loop_hook(vars.mlx, update_frame, &vars);
//     mlx_loop(vars.mlx);

//     return (0);
// }