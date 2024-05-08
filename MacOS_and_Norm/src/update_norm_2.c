/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_norm_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:35:11 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:35:12 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	update_right_arrow_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.move.x += COORD_PIXEL_MOVE_RANGE;
}

void	update_up_arrow_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.move.y -= COORD_PIXEL_MOVE_RANGE;
}

void	update_down_arrow_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.move.y += COORD_PIXEL_MOVE_RANGE;
}

// Rotation X
void	update_x_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.x += COORD_ROTATE_ANGLE;
	rotation_flip(fdf_data->land_data);
}

// Rotation X opposite
void	update_s_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.x -= COORD_ROTATE_ANGLE;
	rotation_flip(fdf_data->land_data);
}
