/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:34:34 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:42:28 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/landscape.h"

void	coord_set_z_value_2d(t_Landscape *land_data,
		t_Point2D *coord, int z_val)
{
	if (!land_data || !coord)
		return ;
	if (z_val != 0)
	{
		if (land_data->z_val_flip)
			coord->y += (z_val * land_data->setup.zoom)
				* COORD_Z_VALUE_MULTIPLIER;
		else
			coord->y -= (z_val * land_data->setup.zoom)
				* COORD_Z_VALUE_MULTIPLIER;
	}
	coord->x *= land_data->setup.zoom;
	coord->y *= land_data->setup.zoom;
}

void	landscape_set_coord_2d(t_Landscape *land_data,
		t_Point2D *coord, int index_x, int index_y)
{
	t_Point2D	new_center;

	if (!land_data || !coord)
		return ;
	coord_start(land_data, coord);
	coord_gap(land_data, coord, index_x, index_y);
	coord_center(land_data, &new_center);
	rotate_x_2d(coord, land_data->setup.angles.x, new_center);
	rotate_y_2d(coord, land_data->setup.angles.y, new_center);
	rotate_z_2d(coord, land_data->setup.angles.z, new_center);
	coord_zoom(land_data, coord);
	coord_move(land_data, coord);
}

void	landscape_set_coord_3d(t_Landscape *land_data,
		t_Point3D_d *coord, int index_x, int index_y)
{
	t_Point2D	new_center;
	t_Point2D	temp;
	int			z_val;

	if (!land_data || !coord)
		return ;
	coord_start(land_data, &temp);
	coord_gap(land_data, &temp, index_x, index_y);
	coord_center(land_data, &new_center);
	coord->x = temp.x;
	coord->y = temp.y;
	coord->z = land_data->map[index_y][index_x] * COORD_Z_VALUE_MULTIPLIER;
	z_val = land_data->map[index_y][index_x] * COORD_Z_VALUE_MULTIPLIER;
	rotate_z_3d(coord, land_data->setup.angles.z, new_center, z_val);
	rotate_x_3d(coord, land_data->setup.angles.x, new_center, z_val);
	rotate_y_3d(coord, land_data->setup.angles.y, new_center, z_val);
	orthographic_projection(coord, z_val);
	temp.x = coord->x;
	temp.y = coord->y;
	coord_zoom(land_data, &temp);
	coord_move(land_data, &temp);
	coord->x = temp.x;
	coord->y = temp.y;
}
