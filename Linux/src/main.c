#include "../header/fdf.h"

// int	main(int argc, char **argv)
// {
// 	if (argc != 2 || !argv)
// 	{
// 		usage_arguments();
// 	}
// 	fdf_start(argv[1]);
// 	return (0);
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