# include "../header/for_math.h"

double	get_radians(int angle)
{
	return (angle * M_PI / 180.0);
}

void	rotate_Z(t_Point2D *coord, int angle, t_Point2D center)
{
	double	new_x;
	double	new_y;
	double	radian;

	if (!coord)
		return ;
	radian = get_radians(angle);
	new_x = center.x + ((coord->x - center.x) * cos(radian)) - ((coord->y - center.y) * sin(radian));
	new_y = center.y + ((coord->x - center.x) * sin(radian)) + ((coord->y - center.y) * cos(radian));
	coord->x = new_x;
	coord->y = new_y;
}

void	rotate_Y(t_Point2D *coord, int angle, t_Point2D center)
{
	double	new_x;
	double	new_y;
	double	radian;

	if (!coord)
		return ;
	radian = get_radians(angle);
	new_x = center.x + ((coord->x - center.x) * cos(radian));
	coord->x = new_x;
}

void	rotate_X(t_Point2D *coord, int angle, t_Point2D center)
{
	double	new_x;
	double	new_y;
	double	radian;

	if (!coord)
		return ;
	radian = get_radians(angle);
	new_y = center.y + ((coord->y - center.y) * cos(radian));
	coord->y = new_y;
}