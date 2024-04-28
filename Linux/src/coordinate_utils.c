#include "../header/landscape.h"

void	coord_start(t_Landscape *land_data, t_Point2D *coord)
{
	if (!land_data || !coord)
		return ;
	coord->x = land_data->setup.start.x;
	coord->y = land_data->setup.start.y;
}

void	coord_gap(t_Landscape *land_data, t_Point2D *coord, int index_x, int index_y)
{
	if (!land_data || !coord)
		return ;
	coord->x += land_data->setup.gap.x * index_x;
	coord->y += land_data->setup.gap.y * index_y;
}

void	coord_zoom(t_Landscape *land_data, t_Point2D *coord)
{
	if (!land_data || !coord)
		return ;
	coord->x *= land_data->setup.zoom;
	coord->y *= land_data->setup.zoom;
}

void	coord_move(t_Landscape *land_data, t_Point2D *coord)
{
	if (!land_data || !coord)
		return ;
	coord->x += land_data->setup.move.x;
	coord->y += land_data->setup.move.y;
}

void	coord_center(t_Landscape *land_data, t_Point2D *coord)
{
	if (!land_data || !coord)
		return ;
	coord->x = land_data->setup.center.x + ((land_data->size.x / 2) * land_data->setup.zoom);
	coord->y = land_data->setup.center.y + ((land_data->size.y / 2) * land_data->setup.zoom);
}

void	coord_set_z_value(t_Landscape *land_data, t_Point2D *coord, int z_val)
{
	if (!land_data || !coord)
		return ;
	if (z_val != 0)
	{
		if (land_data->z_val_flip)
			coord->y += (z_val * land_data->setup.zoom) * COORD_Z_VALUE_MULTIPLIER;
		else
			coord->y -= (z_val * land_data->setup.zoom) * COORD_Z_VALUE_MULTIPLIER;
	}
	coord->x *= land_data->setup.zoom;
	coord->y *= land_data->setup.zoom;
}

void	landscape_set_coord(t_Landscape *land_data, t_Point2D *coord, int index_x, int index_y)
{
	t_Point2D	new_center;

	if (!land_data || !coord)
		return ;
	coord_start(land_data, coord);
	coord_gap(land_data, coord, index_x, index_y);
	coord_center(land_data, &new_center);
	rotate_Z(coord, land_data->setup.angles.z, new_center);
	rotate_Y(coord, land_data->setup.angles.y, new_center);
	rotate_X(coord, land_data->setup.angles.x, new_center);
	coord_zoom(land_data, coord);
	coord_move(land_data, coord);
}