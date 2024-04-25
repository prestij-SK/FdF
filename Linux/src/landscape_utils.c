#include "../header/landscape.h"
#include "../header/for_math.h"

static void	landscape_gap_default(t_Landscape *land_data, int table_x, int table_y)
{
	if (!land_data)
		return ;
	if (land_data->size.x > table_x / 5 || land_data->size.y > table_y / 2)
	{
		land_data->setup.gap.x = COORD_X_GAP_LOW;
		land_data->setup.gap.y = COORD_Y_GAP_LOW;
		return ;
	}
	else if (land_data->size.x > (table_x / 10) || land_data->size.y > (table_y / 4))
	{
		land_data->setup.gap.x = COORD_X_GAP_MID;
		land_data->setup.gap.y = COORD_Y_GAP_MID;
		return ;
	}
	land_data->setup.gap.x = COORD_X_GAP_BIG;
	land_data->setup.gap.y = COORD_Y_GAP_BIG;
}

static void	landscape_coords_default(t_Landscape *land_data)
{
	int	max_x;
	int	max_y;

	if (!land_data)
		return ;
	land_data->setup.start.x = COORD_X_START;
	land_data->setup.start.y = COORD_Y_START;
	max_x = (land_data->size.x - 1) * land_data->setup.gap.x + COORD_X_START;
	max_y = (land_data->size.y - 1) * land_data->setup.gap.y + COORD_Y_START;
	land_data->setup.end.x = max_x;
	land_data->setup.end.y = max_y;
	land_data->setup.center.x = (COORD_X_START + max_x) / 2;
	land_data->setup.center.y = (COORD_Y_START + max_y) / 2;
}

static void	landscape_angles_default(t_Landscape *land_data)
{
	if (!land_data)
		return ;
	land_data->setup.angles.x = COORD_X_ANGLE;
	land_data->setup.angles.y = COORD_Y_ANGLE;
	land_data->setup.angles.z = COORD_Z_ANGLE;
}

static void landscape_other_setups(t_Landscape *land_data)
{
	if (!land_data)
		return ;
	land_data->setup.move.x = 0;
	land_data->setup.move.y = 0;
	land_data->setup.zoom = 0;
	land_data->z_val_flip = 0;
}

void	landscape_set_default(t_Landscape *land_data, int table_x, int table_y)
{
	if (!land_data)
		return ;
	landscape_gap_default(land_data, table_x, table_y);
	landscape_coords_default(land_data);
	landscape_angles_default(land_data);
	landscape_other_setups(land_data);
	land_data->setup.color = COORD_LINE_COLOR;
	land_data->setup.vertex_color = COORD_VERTEX_COLOR;
}

static void	coord_zoom(t_Landscape *land_data, t_Point2D *new_gap)
{
	if (!land_data || !new_gap)
		return ;
	new_gap->x = land_data->setup.gap.x + land_data->setup.zoom;
	new_gap->y = land_data->setup.gap.y + land_data->setup.zoom;
}

static void	coord_move(t_Landscape *land_data, t_Point2D *coord)
{
	if (!land_data || !coord)
		return ;
	coord->x += land_data->setup.move.x;
	coord->y += land_data->setup.move.y;
}

static void	coord_center(t_Landscape *land_data, t_Point2D *new_center)
{
	if (!land_data || !new_center)
		return ;
	new_center->x = land_data->setup.center.x + ((land_data->size.x / 2) * land_data->setup.zoom);
	new_center->y = land_data->setup.center.y + ((land_data->size.y / 2) * land_data->setup.zoom);
}

void	landscape_set_coord(t_Landscape *land_data, t_Point2D *coord, int index_x, int index_y)
{
	t_Point2D	new_gap;
	t_Point2D	new_center;

	if (!land_data || !coord)
		return ;
	coord_zoom(land_data, &new_gap);
	coord->x = (index_x * new_gap.x) + land_data->setup.start.x;
	coord->y = (index_y * new_gap.y) + land_data->setup.start.y;
	coord_center(land_data, &new_center);
	rotate_Z(coord, land_data->setup.angles.z, new_center);
	rotate_Y(coord, land_data->setup.angles.y, new_center);
	rotate_X(coord, land_data->setup.angles.x, new_center);
	coord_move(land_data, coord);
}