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

// int close_window(void *param) {
// 	(void) param;
//     printf("Window closed.\n");
//     exit(0);
// }

// int main() {
//     void *mlx_ptr;
//     void *win_ptr;

//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Close Window Example");

//     mlx_hook(win_ptr, 17, 0, close_window, NULL); // Hook for window close event
//     mlx_loop(mlx_ptr);

//     return 0;
// }