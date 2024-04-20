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


// # include "../mlx_linux/mlx.h"
// #include <stdlib.h>

// #define WIN_WIDTH 800
// #define WIN_HEIGHT 600
// #define RECT_WIDTH 200
// #define RECT_HEIGHT 150

// typedef struct s_vars {
//     void *mlx;
//     void *win;
//     int rect_width;
//     int rect_height;
//     int win_width;
//     int win_height;
//     int rect_x; // x coordinate of the top-left corner of the rectangle
//     int rect_y; // y coordinate of the top-left corner of the rectangle
// } t_vars;

// void draw_rectangle(t_vars *vars) {
//     mlx_clear_window(vars->mlx, vars->win); // Clear the window first

//     mlx_string_put(vars->mlx, vars->win, 10, 10, 0xFFFFFF, "Press Z to zoom in, X to zoom out");
//     mlx_string_put(vars->mlx, vars->win, 10, 30, 0xFFFFFF, "Press ESC to exit");

//     for (int i = vars->rect_x; i < vars->rect_x + vars->rect_width; i++) {
//         for (int j = vars->rect_y; j < vars->rect_y + vars->rect_height; j++) {
//             mlx_pixel_put(vars->mlx, vars->win, i, j, 0xFF0000);
//         }
//     }
// }

// int key_hook(int keycode, t_vars *vars) {
//     if (keycode == 53) // ESC key
//         exit(0);
//     else if (keycode == 100) { // Z key
//         vars->rect_width *= 2;
//         vars->rect_height *= 2;
//     } else if (keycode == 97) { // X key
//         vars->rect_width /= 2;
//         vars->rect_height /= 2;
//     }
//     draw_rectangle(vars);
//     return (0);
// }

// int main(void) {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Zoom Rectangle");
//     vars.win_width = WIN_WIDTH;
//     vars.win_height = WIN_HEIGHT;
//     vars.rect_width = RECT_WIDTH;
//     vars.rect_height = RECT_HEIGHT;
//     vars.rect_x = (WIN_WIDTH - RECT_WIDTH) / 4; // Example: 1/4 of the window width
//     vars.rect_y = (WIN_HEIGHT - RECT_HEIGHT) / 4; // Example: 1/4 of the window height

//     mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars); // key press events
//     draw_rectangle(&vars);
//     mlx_loop(vars.mlx);
//     return (0);
// }










































// #define WIDTH 800
// #define HEIGHT 600
// #define MATRIX_WIDTH 5
// #define MATRIX_HEIGHT 7

// typedef struct s_vars {
//     void *mlx;
//     void *win;
//     float rotation_angle;
//     int matrix[MATRIX_HEIGHT][MATRIX_WIDTH][2]; // 2 integers (x, y) for each coordinate
// } t_vars;

// void initialize_matrix(t_vars *vars)
// {
//     int i, j;

//     // Populate the matrix with coordinates
//     for (i = 0; i < MATRIX_HEIGHT; i++)
//     {
//         for (j = 0; j < MATRIX_WIDTH; j++)
//         {
//             vars->matrix[i][j][0] = WIDTH / 2 + (j - MATRIX_WIDTH / 2) * 20; // x-coordinate
//             vars->matrix[i][j][1] = HEIGHT / 2 + (i - MATRIX_HEIGHT / 2) * 20; // y-coordinate
//         }
//     }
// }

// void draw_matrix(t_vars *vars)
// {
//     int i, j;
//     float angle = vars->rotation_angle;
//     int new_x, new_y;

//     for (i = 0; i < MATRIX_HEIGHT; i++)
//     {
//         for (j = 0; j < MATRIX_WIDTH; j++)
//         {
//             int x = vars->matrix[i][j][0];
//             int y = vars->matrix[i][j][1];

//             new_x = (int)((x - WIDTH / 2) * cos(angle) - (y - HEIGHT / 2) * sin(angle) + WIDTH / 2);
//             new_y = (int)((x - WIDTH / 2) * sin(angle) + (y - HEIGHT / 2) * cos(angle) + HEIGHT / 2);
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
//     else if (keycode == 100) // 'D' key
//     {
//         vars->rotation_angle += 0.1;
//     }
//     else if (keycode == 97) // 'A' key
//     {
//         vars->rotation_angle -= 0.1;
//     }
//     return (0);
// }

// int update_frame(t_vars *vars)
// {
//     mlx_clear_window(vars->mlx, vars->win);
//     draw_matrix(vars);
//     return (0);
// }

// int main()
// {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Rotate Matrix");
//     vars.rotation_angle = 0;

//     initialize_matrix(&vars);

//     mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
//     mlx_loop_hook(vars.mlx, update_frame, &vars);
//     mlx_loop(vars.mlx);

//     return (0);
// }









































// #include <time.h>

// #define WIDTH 800
// #define HEIGHT 600
// #define MATRIX_WIDTH 5
// #define MATRIX_HEIGHT 7

// typedef struct s_vars {
//     void *mlx;
//     void *win;
//     float rotation_angle;
//     int matrix[MATRIX_HEIGHT][MATRIX_WIDTH][2]; // 2 integers (x, y) for each coordinate
// } t_vars;

// void initialize_matrix(t_vars *vars)
// {
//     int i, j;

//     // Seed random number generator
//     srand(time(NULL));

//     // Populate the matrix with random coordinates within the window boundaries
//     for (i = 0; i < MATRIX_HEIGHT; i++)
//     {
//         for (j = 0; j < MATRIX_WIDTH; j++)
//         {
//             vars->matrix[i][j][0] = rand() % WIDTH; // Random x-coordinate
//             vars->matrix[i][j][1] = rand() % HEIGHT; // Random y-coordinate
//         }
//     }
// }

// void draw_matrix(t_vars *vars)
// {
//     int i, j;
//     float angle = vars->rotation_angle;
//     int new_x, new_y;

//     for (i = 0; i < MATRIX_HEIGHT; i++)
//     {
//         for (j = 0; j < MATRIX_WIDTH; j++)
//         {
//             int x = vars->matrix[i][j][0];
//             int y = vars->matrix[i][j][1];

//             new_x = (int)((x - WIDTH / 2) * cos(angle) - (y - HEIGHT / 2) * sin(angle) + WIDTH / 2);
//             new_y = (int)((x - WIDTH / 2) * sin(angle) + (y - HEIGHT / 2) * cos(angle) + HEIGHT / 2);
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
//     else if (keycode == 100) // 'D' key
//     {
//         vars->rotation_angle += 0.1;
//     }
//     else if (keycode == 97) // 'A' key
//     {
//         vars->rotation_angle -= 0.1;
//     }
//     return (0);
// }

// int update_frame(t_vars *vars)
// {
//     mlx_clear_window(vars->mlx, vars->win);
//     draw_matrix(vars);
//     return (0);
// }

// int main()
// {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Rotate Matrix");
//     vars.rotation_angle = 0;

//     initialize_matrix(&vars);

//     mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
//     mlx_loop_hook(vars.mlx, update_frame, &vars);
//     mlx_loop(vars.mlx);

//     return (0);
// }