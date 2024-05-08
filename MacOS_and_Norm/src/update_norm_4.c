/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_norm_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:37:41 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:38:05 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

// Show landscape in isometric projection
void	update_isometric(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->status.is_isometric = STATUS_IS_ACTIVE;
	fdf_data->land_data->status.is_conic = STATUS_IS_NOT_ACTIVE;
	fdf_data->land_data->setup.angles.x = COORD_X_ANGLE;
	fdf_data->land_data->setup.angles.y = COORD_Y_ANGLE;
	fdf_data->land_data->setup.angles.z = COORD_Z_ANGLE;
}

// Show landscape int conic projection
void	update_conic(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->status.is_conic = STATUS_IS_ACTIVE;
	fdf_data->land_data->status.is_isometric = STATUS_IS_NOT_ACTIVE;
	fdf_data->land_data->setup.angles.x = 0;
	fdf_data->land_data->setup.angles.y = 0;
	fdf_data->land_data->setup.angles.z = 0;
}

void	update_2d_plane(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->status.is_2d = STATUS_IS_ACTIVE;
	fdf_data->land_data->status.is_3d = STATUS_IS_NOT_ACTIVE;
}

void	update_3d_plane(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->status.is_3d = STATUS_IS_ACTIVE;
	fdf_data->land_data->status.is_2d = STATUS_IS_NOT_ACTIVE;
}
