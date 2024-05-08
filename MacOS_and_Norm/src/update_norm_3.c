/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_norm_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:35:21 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:35:23 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

// Rotation Y
void	update_c_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.y += COORD_ROTATE_ANGLE;
	rotation_flip(fdf_data->land_data);
}

// Rotation Y opposite
void	update_d_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.y -= COORD_ROTATE_ANGLE;
}

// Rotation Z
void	update_z_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.z += COORD_ROTATE_ANGLE;
}

// Rotation Z opposite
void	update_a_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.z -= COORD_ROTATE_ANGLE;
	rotation_flip(fdf_data->land_data);
}

// Random coloring diagonal lines
void	update_party_time(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	if (!fdf_data->land_data->status.is_fiesta)
	{
		fdf_data->land_data->status.is_fiesta = STATUS_IS_ACTIVE;
		return ;
	}
	fdf_data->land_data->status.is_fiesta = STATUS_IS_NOT_ACTIVE;
}
