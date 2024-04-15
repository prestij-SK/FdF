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

void	render_error()
{
	print_message("Rendering Error!\n");
	print_message("Issue while trying to run rendering the landscape\n");
	exit(EXIT_FAILURE);
}

void	delete_fdf_data(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	mlx_destroy_image(fdf_data->mlx, fdf_data->land_table->img);
	free(fdf_data->land_table);
	mlx_destroy_image(fdf_data->mlx, fdf_data->option_table->img);
	free(fdf_data->option_table);
	delete_buttons_image(fdf_data, BUTTONS_TOTAL);
	mlx_destroy_window(fdf_data->mlx, fdf_data->mlx_window);
	mlx_destroy_display(fdf_data->mlx);
	free(fdf_data->mlx);
	fdf_data->mlx = NULL;
	fdf_data->mlx_window = NULL;
	fdf_data->land_table = NULL;
	fdf_data->option_table = NULL;
	fdf_data->buttons = NULL;
}

static int	land_table_image_init(t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	fdf_data->land_table = image_init(fdf_data->mlx, LAND_X_SIZE, LAND_Y_SIZE);
	if (!fdf_data->land_table)
		return (0);
	fdf_data->land_table->name = NULL;
	fdf_data->land_table->pos.x = LAND_X_POSITION;
	fdf_data->land_table->pos.y = LAND_Y_POSITION;
	fdf_data->land_table->size.x = LAND_X_SIZE;
	fdf_data->land_table->size.y = LAND_Y_SIZE;
	fdf_data->land_table->color = LAND_COLOR;
	return (1);
}

static int	option_table_image_init(t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	fdf_data->option_table = image_init(fdf_data->mlx, TABLE_X_SIZE, TABLE_Y_SIZE);
	if (!fdf_data->option_table)
		return (0);
	fdf_data->option_table->name = NULL;
	fdf_data->option_table->pos.x = TABLE_X_POSITION;
	fdf_data->option_table->pos.y = TABLE_Y_POSITION;
	fdf_data->option_table->size.x = TABLE_X_SIZE;
	fdf_data->option_table->size.y = TABLE_Y_SIZE;
	fdf_data->option_table->color = TABLE_COLOR;
	return (1);
}

int	fdf_data_init(t_FdF *fdf_data, t_LandscapeData *land_data)
{
	if (!fdf_data || !land_data)
		return (0);
	fdf_data->land_data = land_data;
	fdf_data->mlx = mlx_init();
	if (!fdf_data->mlx)
		return (0);
	fdf_data->mlx_window = mlx_new_window(fdf_data->mlx, WINDOW_HORIZONTAL_RESOLUTION, WINDOW_VERTICAL_RESOLUTION, "dasist ABUBA");
	if (!fdf_data->mlx_window)
		return (0);
	if (!land_table_image_init(fdf_data))
		return (0);
	if (!option_table_image_init(fdf_data))
		return (0);
	if (!buttons_image_init(fdf_data))
		return (0);
	fdf_data->button_index = -1;
	return (1);
}

int	start_program(t_LandscapeData *land_data)
{
	t_FdF	fdf_data;

	if (!land_data)
		return (0);
	if (!fdf_data_init(&fdf_data, land_data))
	{
		delete_fdf_data(&fdf_data);
		return (0);
	}
	if (!fdf_draw(&fdf_data))
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
	if (!start_program(&land_data))
	{
		delete_land_data(&land_data);
		render_error();
	}
	delete_land_data(&land_data);
}