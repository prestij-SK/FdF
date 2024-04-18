#include "../header/landscape.h"

double	get_radians(int angle)
{
	return (angle * M_PI / 180.0);
}

void	rotate_landscape(t_Landscape *land_data, int angle)
{
	t_LandscapeUtils	util;
	int					i;
	int					j;

	if (!land_data)
		return ;
	util.radian = get_radians(angle);
	i = 0;
	while (i < land_data->size.y)
	{
		j = 0;
		while (j < land_data->size.x)
		{
			// util.temp.x = (land_data->map[i][j].x * cos(util.radian)) -
			// 			  (land_data->map[i][j].y * sin(util.radian));

			// util.temp.y = (land_data->map[i][j].x * sin(util.radian)) +
			// 			  (land_data->map[i][j].y * cos(util.radian));

			// land_data->map[i][j].x = util.temp.x;
			// land_data->map[i][j].y = util.temp.y;
			util.temp.x = (land_data->map[i][j].x - land_data->map[i][j].y) * cos(0.5);
			util.temp.y = (land_data->map[i][j].x + land_data->map[i][j].y) * sin(0.5);
			land_data->map[i][j].x = util.temp.x;
			land_data->map[i][j].y = util.temp.y;
			++j;
		}
		++i;
	}
}