/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:16:34 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:17:09 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	render_image(t_FdF *fdf_data, t_Image *img)
{
	if (!fdf_data || !img)
		return ;
	mlx_put_image_to_window(fdf_data->mlx, fdf_data->mlx_window,
		img->img, img->pos.x, img->pos.y);
}

void	render_button(t_FdF *fdf_data, int index)
{
	int	center_x;
	int	center_y;

	if (!fdf_data)
		return ;
	draw_rectangle_filled(fdf_data->buttons[index]);
	render_image(fdf_data, fdf_data->buttons[index]);
	center_x = fdf_data->buttons[index]->pos.x + 10;
	center_y = fdf_data->buttons[index]->pos.y + 10;
	mlx_string_put(fdf_data->mlx, fdf_data->mlx_window,
		center_x, center_y, STRING_COLOR,
		fdf_data->buttons[index]->name);
}

void	render_option_table(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	draw_rectangle_filled(fdf_data->option_table);
	render_image(fdf_data, fdf_data->option_table);
}

void	render_land_table(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	draw_rectangle_filled(fdf_data->land_table);
	draw_landscape(fdf_data->land_data, fdf_data->land_table);
	render_image(fdf_data, fdf_data->land_table);
}

void	render_all(t_FdF *fdf_data)
{
	int	i;

	if (!fdf_data)
		return ;
	render_land_table(fdf_data);
	render_option_table(fdf_data);
	i = 0;
	while (i < BUTTONS_TOTAL)
	{
		render_button(fdf_data, i);
		++i;
	}
}
