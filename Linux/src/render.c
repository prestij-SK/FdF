#include "../header/fdf.h"

void	put_image(t_FdF *fdf_data, t_Image *img)
{
	if (!fdf_data || !img)
		return ;
	mlx_put_image_to_window(fdf_data->mlx, fdf_data->mlx_window,
							img->img, img->pos.x, img->pos.y);
}

void	draw_button(t_FdF *fdf_data, int index)
{
	if (!fdf_data)
		return ;
	draw_rectangle_filled(fdf_data->buttons[index]);
	put_image(fdf_data, fdf_data->buttons[index]);
}

void	draw_option_table(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	draw_rectangle_filled(fdf_data->option_table);
	put_image(fdf_data, fdf_data->option_table);
}

void	draw_land_table(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	draw_rectangle_filled(fdf_data->land_table);
	put_image(fdf_data, fdf_data->land_table);
}

void	render_all(t_FdF *fdf_data)
{
	int	i;

	if (!fdf_data)
		return ;
	draw_land_table(fdf_data);
	draw_option_table(fdf_data);
	i = 0;
	while (i < BUTTONS_TOTAL)
	{
		draw_button(fdf_data, i);
		++i;
	}
}