#include "../header/fdf.h"

// DELETE
// static void display_land_data(t_LandscapeData *land_data)
// {
// 	printf("x: %ld\n", land_data->x_size);
// 	printf("y: %ld\n", land_data->y_size);
// 	size_t	i = 0;
// 	size_t	j = 0;
// 	while (i < land_data->x_size)
// 	{
// 		j = 0;
// 		while (j < land_data->y_size)
// 		{
// 			printf("%d ", land_data->map[i][j]);
// 			++j;
// 		}
// 		printf("\n");
// 		++i;
// 	}
// }

static void	input_update_render(t_FdF *fdf_data)
{
	mlx_hook(fdf_data->mlx_window, EVENT_MOUSEMOVE, 1L<<6, input_mouse_move, fdf_data);
	mlx_hook(fdf_data->mlx_window, EVENT_KEYDOWN, 1L<<0, input_key_press, fdf_data);
	mlx_hook(fdf_data->mlx_window, EVENT_DESTROY, 0, input_close_window, fdf_data);
}

int	fdf_draw(t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	render_all(fdf_data);
	input_update_render(fdf_data);
	mlx_loop(fdf_data->mlx);
	return (1);
}