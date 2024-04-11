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

// DELETE
// void	display_buttons_coord(t_FdF *fdf_data)
// {
// 	int i = 0;
// 	while (i < BUTTONS_TOTAL)
// 	{
// 		printf("x: %d  y: %d\n", fdf_data->buttons[i]->pos.x, fdf_data->buttons[i]->pos.y);
// 		++i;
// 	}
// }

// void input()
// void update()

static void	draw_buttons(t_FdF *fdf_data)
{
	int	i;

	if (!fdf_data)
		return ;
	i = 0;
	while (i < BUTTONS_TOTAL)
	{
		draw_rectangle(fdf_data->buttons[i]);
		++i;
	}
}

static void	put_image_buttons(t_FdF *fdf_data)
{
	int	i;

	if (!fdf_data)
		return ;
	i = 0;
	while (i < BUTTONS_TOTAL)
	{
		mlx_put_image_to_window(fdf_data->mlx, fdf_data->mlx_window, fdf_data->buttons[i]->img,
								fdf_data->buttons[i]->pos.x, fdf_data->buttons[i]->pos.y);
		++i;
	}
}

void	render(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	draw_rectangle(fdf_data->land);
	draw_rectangle(fdf_data->table);
	draw_buttons(fdf_data);
	mlx_put_image_to_window(fdf_data->mlx, fdf_data->mlx_window, fdf_data->land->img,
							LAND_X_POSITION, LAND_Y_POSITION);
	mlx_put_image_to_window(fdf_data->mlx, fdf_data->mlx_window, fdf_data->table->img,
							TABLE_X_POSITION, TABLE_Y_POSITION);
	put_image_buttons(fdf_data);
}

void	input(t_FdF *fdf_data, t_Input *input_data)
{
	if (!fdf_data || !input_data)
		return ;
	mlx_key_hook(fdf_data->mlx_window, key_press, input_data);
}

int	fdf_draw(t_LandscapeData *land_data, t_FdF *fdf_data)
{
	t_Input	input_data;

	(void) land_data;
	(void) fdf_data;
	if (!land_data || !fdf_data)
		return (0);
	input_init(&input_data);
	input(fdf_data, &input_data);
	// update()
	printf("esc: %d\n", input_data.is_esc);
	if (input_data.is_esc)
	{
		exit(0);
	}
	render(fdf_data);
	mlx_loop(fdf_data->mlx);
	return (1);
}