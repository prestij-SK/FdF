/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:17:23 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:18:33 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	update_normy(t_FdF *fdf_data, char *temp_str)
{
	if (!ft_strncmp(temp_str, "Zoom In", 7))
		update_mouse_scroll_up(fdf_data);
	else if (!ft_strncmp(temp_str, "Zoom Out", 8))
		update_mouse_scroll_down(fdf_data);
	else if (!ft_strncmp(temp_str, "Move Left", 9))
		update_left_arrow_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Move Right", 10))
		update_right_arrow_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Move Up", 7))
		update_up_arrow_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Move Down", 9))
		update_down_arrow_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Fiesta", 6))
		update_party_time(fdf_data);
	else if (!ft_strncmp(temp_str, "Reset", 5))
		landscape_set_default(fdf_data->land_data,
			fdf_data->land_table->size.x, fdf_data->land_table->size.y);
	else if (!ft_strncmp(temp_str, "2D Plane", 8))
		update_2d_plane(fdf_data);
	else if (!ft_strncmp(temp_str, "3D Plane", 8))
		update_3d_plane(fdf_data);
	else if (!ft_strncmp(temp_str, "Exit", 4))
		update_end_program(fdf_data);
}

void	update_mouse_left_click(t_FdF *fdf_data)
{
	char	*temp_str;

	if (!fdf_data)
		return ;
	if (fdf_data->active_button == BUTTONS_NOT_ACTIVE)
		return ;
	temp_str = fdf_data->buttons[fdf_data->active_button]->name;
	if (!ft_strncmp(temp_str, "Isometric", 9))
		update_isometric(fdf_data);
	else if (!ft_strncmp(temp_str, "Conic", 5))
		update_conic(fdf_data);
	else if (!ft_strncmp(temp_str, "X Rotate*", 9))
		update_s_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Y Rotate*", 9))
		update_d_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Z Rotate*", 9))
		update_a_key(fdf_data);
	else if (!ft_strncmp(temp_str, "X Rotate", 8))
		update_x_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Y Rotate", 8))
		update_c_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Z Rotate", 8))
		update_z_key(fdf_data);
	update_normy(fdf_data, temp_str);
}

int	update_frame(t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	render_land_table(fdf_data);
	return (1);
}
