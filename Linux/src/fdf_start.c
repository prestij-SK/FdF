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

// DELETE
static void display_land_data(t_LandscapeData *land_data)
{
	printf("x: %ld\n", land_data->x_size);
	printf("y: %ld\n", land_data->y_size);
	size_t	i = 0;
	size_t	j = 0;
	while (i < land_data->x_size)
	{
		j = 0;
		while (j < land_data->y_size)
		{
			printf("%d ", land_data->map[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
}

void	delete_fdf_data(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	mlx_destroy_window(fdf_data->mlx, fdf_data->mlx_window);
	mlx_destroy_display(fdf_data->mlx); // ??????
	free(fdf_data->mlx);
}

int	fdf_init(t_FdF *fdf_data)
{
	fdf_data->mlx = mlx_init();
	if (!fdf_data->mlx)
		return (0);
	fdf_data->mlx_window = mlx_new_window(fdf_data->mlx, HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION, "dasist ABUBA");
	if (!fdf_data->mlx_window)
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
	if (!draw_landscape(land_data, &fdf_data))
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
	display_land_data(&land_data);
	if (!render_landscape(&land_data))
	{
		delete_land_data(&land_data);
		render_error();
	}
	delete_land_data(&land_data);
}