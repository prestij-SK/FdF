#include "../header/fdf.h"

// // DELETE
// static void	display_file_data(t_FileData *file_data)
// {
// 	printf("row: %ld\n", file_data->row);
// 	printf("column: %ld\n", file_data->column);
// 	size_t	i = 0;
// 	size_t	j = 0;
// 	while (i < file_data->row)
// 	{
// 		j = 0;
// 		while (j < file_data->column)
// 		{
// 			printf("%s ", file_data->file_content[i][j]);
// 			++j;
// 		}
// 		printf("\n");
// 		++i;
// 	}
// }

void	delete_buttons_image(t_FdF *fdf_data, int size)
{
	int i = 0;

	if (!fdf_data)
		return ;
	while (i < size)
	{
		mlx_destroy_image(fdf_data->mlx, fdf_data->buttons[i]);
		free(fdf_data->buttons[i]);
		++i;
	}
	free(fdf_data->buttons);
	fdf_data->buttons = NULL;
}

void	delete_fdf_data(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	mlx_destroy_image(fdf_data->mlx, fdf_data->land);
	free(fdf_data->land);
	mlx_destroy_image(fdf_data->mlx, fdf_data->table);
	free(fdf_data->table);
	delete_buttons_image(fdf_data, BUTTONS_TOTAL);
	mlx_destroy_window(fdf_data->mlx, fdf_data->mlx_window);
	mlx_destroy_display(fdf_data->mlx);
	free(fdf_data->mlx);
	fdf_data->mlx = NULL;
	fdf_data->mlx_window = NULL;
	fdf_data->land = NULL;
	fdf_data->table = NULL;
	fdf_data->buttons = NULL;
}

t_Image	*image_init(void *mlx, int x_size, int y_size)
{
	t_Image	*new_img;

	if (!mlx)
		return (NULL);
	new_img = (t_Image *)malloc(sizeof(t_Image));
	if (!new_img)
		return (NULL);
	new_img->img = mlx_new_image(mlx, x_size, y_size);
	if (!new_img->img)
	{
		free(new_img);
		return (NULL);
	}
	new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bits_per_pixel,
										&new_img->line_length, &new_img->endian);
	if (!new_img->addr)
	{
		free(new_img);
		return (NULL);
	}
	return (new_img);
}

static int	land_image_init(t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	fdf_data->land = image_init(fdf_data->mlx, LAND_X_SIZE, LAND_Y_SIZE);
	if (!fdf_data->land)
		return (0);
	fdf_data->land->name = NULL;
	fdf_data->land->pos.x = LAND_X_POSITION;
	fdf_data->land->pos.y = LAND_Y_POSITION;
	fdf_data->land->size.x = LAND_X_SIZE;
	fdf_data->land->size.y = LAND_Y_SIZE;
	fdf_data->land->color = LAND_COLOR;
	fdf_data->land->on_image = 0;
	return (1);
}

static int	table_image_init(t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	fdf_data->table = image_init(fdf_data->mlx, TABLE_X_SIZE, TABLE_Y_SIZE);
	if (!fdf_data->table)
		return (0);
	fdf_data->table->name = NULL;
	fdf_data->table->pos.x = TABLE_X_POSITION;
	fdf_data->table->pos.y = TABLE_Y_POSITION;
	fdf_data->table->size.x = TABLE_X_SIZE;
	fdf_data->table->size.y = TABLE_Y_SIZE;
	fdf_data->table->color = TABLE_COLOR;
	fdf_data->table->on_image = 0;
	return (1);
}

static void	set_buttons_name(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->buttons[0]->name = "name_1";
	fdf_data->buttons[1]->name = "name_2";
	fdf_data->buttons[2]->name = "name_3";
	fdf_data->buttons[3]->name = "name_4";
	fdf_data->buttons[4]->name = "name_5";
	fdf_data->buttons[5]->name = "name_6";
	fdf_data->buttons[6]->name = "name_7";
	fdf_data->buttons[7]->name = "name_8";
	fdf_data->buttons[8]->name = "name_9";
	fdf_data->buttons[9]->name = "name_10";
}

static int	buttons_image_init(t_FdF *fdf_data)
{
	int	i;
	int	x_new;
	int	y_new;

	if (!fdf_data)
		return (0);
	fdf_data->buttons = (t_Image **)malloc(sizeof(t_Image *) * (BUTTONS_TOTAL + 1));
	if (!fdf_data->buttons)
		return (0);
	x_new = BUTTONS_X_POSITION;
	y_new = BUTTONS_Y_POSITION;
	i = 0;
	while (i < BUTTONS_TOTAL)
	{
		fdf_data->buttons[i] = image_init(fdf_data->mlx, BUTTONS_X_SIZE, BUTTONS_Y_SIZE);
		if (!fdf_data->buttons[i])
		{
			delete_buttons_image(fdf_data, i);
			return (0);
		}
		fdf_data->buttons[i]->pos.x = x_new;
		fdf_data->buttons[i]->pos.y = y_new;
		fdf_data->buttons[i]->size.x = BUTTONS_X_SIZE;
		fdf_data->buttons[i]->size.y = BUTTONS_Y_SIZE;
		fdf_data->buttons[i]->color = BUTTONS_COLOR;
		fdf_data->buttons[i]->on_image = 0;
		x_new += BUTTONS_X_SIZE + BUTTONS_GAP;
		if (i == (BUTTONS_TOTAL / 2) - 1)
		{
			x_new = BUTTONS_X_POSITION;
			y_new += BUTTONS_Y_SIZE + BUTTONS_GAP;
		}
		++i;
	}
	fdf_data->buttons[i] = NULL;
	set_buttons_name(fdf_data);
	return (1);
}

int	fdf_init(t_FdF *fdf_data)
{
	fdf_data->mlx = mlx_init();
	if (!fdf_data->mlx)
		return (0);
	fdf_data->mlx_window = mlx_new_window(fdf_data->mlx, WINDOW_HORIZONTAL_RESOLUTION, WINDOW_VERTICAL_RESOLUTION, "dasist ABUBA");
	if (!fdf_data->mlx_window)
		return (0);
	if (!land_image_init(fdf_data))
		return (0);
	if (!table_image_init(fdf_data))
		return (0);
	if (!buttons_image_init(fdf_data))
		return (0);
	return (1);
}

int	render_landscape(t_LandscapeData *land_data)
{
	t_FdF	fdf_data;

	if (!fdf_init(&fdf_data))
	{
		delete_fdf_data(&fdf_data);
		return (0);
	}
	if (!fdf_draw(land_data, &fdf_data))
	{
		delete_fdf_data(&fdf_data);
		return (0);
	}
	delete_fdf_data(&fdf_data);
	return (1);
}

void	fdf_start(char *file_name)
{
	t_FileData		file_data;
	t_LandscapeData	land_data;

	if (!file_name)
		usage_arguments();
	if (!check_file_name(file_name))
		usage_arguments();
	if (!file_data_init(&file_data, file_name))
		usage_file_content();
	if (!land_data_init(&land_data, &file_data))
	{
		delete_file_data(&file_data);
		usage_file_values();
	}
	delete_file_data(&file_data);
	// display_file_data(&file_data);
	// display_land_data(&land_data);
	if (!render_landscape(&land_data))
	{
		delete_land_data(&land_data);
		render_error();
	}
	delete_land_data(&land_data);
}