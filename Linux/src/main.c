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

// #define ESC_KEY 53

// typedef struct s_vars {
//     void *mlx;
//     void *win;
// } t_vars;

// int key_hook(int keycode, t_vars *vars)
// {
// 	// printf("code: %d\n", keycode);
//     if (keycode == 65307)
//     {
//         mlx_destroy_window(vars->mlx, vars->win);
//         exit(0);
//     }
//     return (0);
// }

// int main(void)
// {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
//     mlx_key_hook(vars.win, key_hook, &vars);
//     mlx_loop(vars.mlx);
// }