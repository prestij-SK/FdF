/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:07:50 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:08:27 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	input_mouse_move(int x, int y, t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	update_buttons_hover(fdf_data, x, y);
	return (1);
}

int	input_key_press(int key, t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	if (key == KEY_ESC)
		update_end_program(fdf_data);
	else if (key == KEY_LEFT_ARROW)
		update_left_arrow_key(fdf_data);
	else if (key == KEY_RIGHT_ARROW)
		update_right_arrow_key(fdf_data);
	else if (key == KEY_UP_ARROW)
		update_up_arrow_key(fdf_data);
	else if (key == KEY_DOWN_ARROW)
		update_down_arrow_key(fdf_data);
	else if (key == KEY_X)
		update_x_key(fdf_data);
	else if (key == KEY_C)
		update_c_key(fdf_data);
	else if (key == KEY_Z)
		update_z_key(fdf_data);
	else if (key == KEY_A)
		update_a_key(fdf_data);
	else if (key == KEY_S)
		update_s_key(fdf_data);
	else if (key == KEY_D)
		update_d_key(fdf_data);
	return (1);
}

int	input_close_window(t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	update_end_program(fdf_data);
	return (1);
}

int	input_mouse_button(int button, int x, int y, t_FdF *fdf_data)
{
	(void) x;
	(void) y;
	if (!fdf_data)
		return (0);
	if (button == LEFT_CLICK)
		update_mouse_left_click(fdf_data);
	else if (button == SCROLL_UP)
		update_mouse_scroll_up(fdf_data);
	else if (button == SCROLL_DOWN)
		update_mouse_scroll_down(fdf_data);
	return (1);
}
