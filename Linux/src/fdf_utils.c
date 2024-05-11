#include "../header/fdf.h"

// -1 return will mean that no button was under mouse pointer
int	mouse_on_button(t_FdF *fdf_data, int x, int y)
{
	int	i;
	int	temp_width;
	int	temp_height;

	if (!fdf_data)
		return (BUTTONS_NOT_ACTIVE);
	i = 0;
	while (i < BUTTONS_TOTAL)
	{
		temp_width = fdf_data->buttons[i]->pos.x + fdf_data->buttons[i]->size.x;
		temp_height = fdf_data->buttons[i]->pos.y + fdf_data->buttons[i]->size.y;
		if ((x >= fdf_data->buttons[i]->pos.x) && (x <= temp_width) &&
			(y >= fdf_data->buttons[i]->pos.y) && (y <= temp_height))
		{
			return (i);
		}
		++i;
	}
	return (BUTTONS_NOT_ACTIVE);
}

void	fdf_mlx_delete(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	if (!fdf_data->buttons || !fdf_data->land_table || !fdf_data->option_table || !fdf_data->mlx || !fdf_data->mlx_window)
		return ; // in case that NULL is not handled in this minilibx library...
	delete_buttons_image(fdf_data->buttons, fdf_data->mlx);
	free(fdf_data->buttons);
	delete_image(fdf_data->land_table, fdf_data->mlx);
	free(fdf_data->land_table);
	delete_image(fdf_data->option_table, fdf_data->mlx);
	free(fdf_data->option_table);
	mlx_destroy_window(fdf_data->mlx, fdf_data->mlx_window);
	// free(fdf_data->mlx_window); // this will double free actually
	mlx_destroy_display(fdf_data->mlx);
	free(fdf_data->mlx);
}
void	fdf_null_fields(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->mlx = NULL;
	fdf_data->mlx_window = NULL;
	fdf_data->land_table = NULL;
	fdf_data->option_table = NULL;
	fdf_data->buttons = NULL;
	fdf_data->land_data = NULL;
	fdf_data->active_button = ERROR_VALUE;
}
