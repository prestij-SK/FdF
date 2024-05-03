#include "../header/landscape.h"

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
	land_data->setup.zoom = 1;
	land_data->z_val_flip = 0;
}

static void	landscape_status_default(t_Landscape *land_data)
{
	if (!land_data)
		return ;
	land_data->status.is_conic = STATUS_IS_NOT_ACTIVE;
	land_data->status.is_isometric = STATUS_IS_ACTIVE;
	land_data->status.is_fiesta = STATUS_IS_NOT_ACTIVE;
	land_data->status.is_2D = STATUS_IS_NOT_ACTIVE;
	land_data->status.is_3D = STATUS_IS_ACTIVE;
}

void	landscape_set_default(t_Landscape *land_data, int table_x, int table_y)
{
	if (!land_data)
		return ;
	landscape_gap_default(land_data, table_x, table_y);
	landscape_coords_default(land_data);
	landscape_angles_default(land_data);
	landscape_other_setups(land_data);
	landscape_status_default(land_data);
}