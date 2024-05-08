/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_norm_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:34:42 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:35:03 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	update_end_program(t_FdF *fdf_data)
{
	delete_fdf_data(fdf_data);
	delete_landscape_data(fdf_data->land_data);
	program_end();
}

void	update_buttons_hover(t_FdF *fdf_data, int x, int y)
{
	int	temp_index;

	if (!fdf_data)
		return ;
	temp_index = mouse_on_button(fdf_data, x, y);
	if (temp_index == BUTTONS_NOT_ACTIVE)
	{
		if (fdf_data->active_button != BUTTONS_NOT_ACTIVE)
		{
			fdf_data->buttons[fdf_data->active_button]->color
				= BUTTONS_COLOR;
			render_button(fdf_data, fdf_data->active_button);
			fdf_data->active_button = BUTTONS_NOT_ACTIVE;
		}
	}
	else
	{
		fdf_data->buttons[temp_index]->color
			= BUTTONS_COLOR_HOVER;
		render_button(fdf_data, temp_index);
		fdf_data->active_button = temp_index;
	}
}

void	update_mouse_scroll_up(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.zoom += COORD_PIXEL_ZOOM_RANGE;
}

void	update_mouse_scroll_down(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	if (fdf_data->land_data->setup.zoom - COORD_PIXEL_ZOOM_RANGE
		<= COORD_PIXEL_ZOOM_LIMIT)
		return ;
	fdf_data->land_data->setup.zoom -= COORD_PIXEL_ZOOM_RANGE;
}

void	update_left_arrow_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.move.x -= COORD_PIXEL_MOVE_RANGE;
}
