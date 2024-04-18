#include "../header/landscape.h"

double	get_radians(int angle)
{
	return (angle * M_PI / 180.0);
}

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

// 			// util.temp.y = (land_data->map[i][j].x - cen.x) * sin(util.radian) +
// 			// 			  (land_data->map[i][j].y - cen.y) * cos(util.radian) + cen.y;

// 			land_data->map[i][j].x = util.temp.x;
// 			// land_data->map[i][j].y = util.temp.y;
// 			// printf("%d:%d  ", land_data->map[i][j].x, land_data->map[i][j].y);
// 			++j;
// 		}
// 		// printf("\n");
// 		++i;
// 	}
// 	// printf("cen: %d:%d\n", cen.x, cen.y);
// }

void	rotate_landscape(t_Landscape *land_data, int angle)
{
	
}