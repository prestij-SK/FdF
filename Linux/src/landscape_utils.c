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
	land_data->setup.center.y = (COORD_Y_START + max_x) / 2;
}

static void	landscape_angles_default(t_Landscape *land_data)
{
	if (!land_data)
		return ;
	land_data->setup.angles.x = get_radians(COORD_X_ANGLE);
	land_data->setup.angles.y = get_radians(COORD_Y_ANGLE);
	land_data->setup.angles.z = get_radians(COORD_Z_ANGLE);
	land_data->setup.rotate_angle = 0.0;
}

static void landscape_other_setups(t_Landscape *land_data)
{
	if (!land_data)
		return ;
	land_data->setup.move.x = 0;
	land_data->setup.move.y = 0;
	land_data->setup.zoom = 0;
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

static void	coord_zoom(t_Landscape *land_data, t_Point2D *coord)
{
	if (!land_data || !coord)
		return ;
	coord->x = land_data->setup.gap.x + land_data->setup.zoom;
	coord->y = land_data->setup.gap.y + land_data->setup.zoom;
}

static void	coord_move(t_Landscape *land_data, t_Point2D *coord)
{
	if (!land_data || !coord)
		return ;
	coord->x += land_data->setup.move.x;
	coord->y += land_data->setup.move.y;
}

void	landscape_set_coord(t_Landscape *land_data, t_Point2D *coord, int index_x, int index_y)
{
	t_Point2D	new_gap;

	if (!land_data || !coord)
		return ;
	coord_zoom(land_data, &new_gap);
	coord->x = (index_x * new_gap.x) + land_data->setup.start.x;
	coord->y = (index_y * new_gap.y) + land_data->setup.start.y;
	coord_move(land_data, coord);
	// if (land_data->input.is_moved)
	// {
	// 	coord->x += land_data->setup.move;
	// 	coord->y +=
	// }
	// x rotate
	// y rotate
	// z rotate
}

// double	get_radians(int angle)
// {
// 	return (angle * M_PI / 180.0);
// }

// static t_Point2D_d	center(t_Point3D **map)
// {
// 	double x1 = map[0][0].x;
// 	double x2 = map[0][5].x;
// 	double x3 = map[7][0].x;
// 	double x4 = map[7][5].x;

// 	double y1 = map[0][0].y;
// 	double y2 = map[0][5].y;
// 	double y3 = map[7][0].y;
// 	double y4 = map[7][5].y;

// 	t_Point2D_d new;
// 	new.x = (x1 + x2 + x3 + x4) / 4;
// 	new.y = (y1 + y2 + y3 + y4) / 4;
// 	return (new);
// }

// void	rotate_landscape(t_Landscape *land_data, int angle)
// {
// 	t_LandscapeUtils	util;
// 	int					i;
// 	int					j;

// 	if (!land_data)
// 		return ;
// 	util.radian = get_radians(angle);
// 	t_Point2D_d cen = center(land_data->map);
// 	i = 0;
// 	while (i < land_data->size.y)
// 	{
// 		j = 0;
// 		while (j < land_data->size.x)
// 		{
// 			util.temp.x = (land_data->map[i][j].x - cen.x) * cos(util.radian) -
// 						  (land_data->map[i][j].y - cen.y) * sin(util.radian) + cen.x;

// 			util.temp.y = (land_data->map[i][j].x - cen.x) * sin(util.radian) +
// 						  (land_data->map[i][j].y - cen.y) * cos(util.radian) + cen.y;

// 			land_data->map[i][j].x = util.temp.x;
// 			land_data->map[i][j].y = util.temp.y;
// 			// printf("%d:%d  ", land_data->map[i][j].x, land_data->map[i][j].y);
// 			++j;
// 		}
// 		// printf("\n");
// 		++i;
// 	}
// 	// printf("cen: %d:%d\n", cen.x, cen.y);
// }

// void	rotate_landscape(t_Landscape *land_data, int angle)
// {

// }