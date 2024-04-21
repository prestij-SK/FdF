# include "../header/for_math.h"

double	get_radians(int angle)
{
	return (angle * M_PI / 180.0);
}

void	rotate_Z(t_Point2D *coord, double angle, t_Point2D center, int z_val)
{
	double	new_x;
	double	new_y;

	if (!coord)
		return ;
	new_x = center.x + ((coord->x - center.x) * cos(angle)) - ((coord->y - center.y) * sin(angle));
	new_y = center.y + ((coord->x - center.x) * sin(angle)) + ((coord->y - center.y) * cos(angle));
	coord->x = new_x;
	coord->y = new_y;
}

void	rotate_Y(t_Point2D *coord, double angle, t_Point2D center, int z_val)
{
	double	new_x;
	double	new_y;

	if (!coord)
		return ;
	// new_x = center.x + ((coord->x - center.x) * cos(angle)) - ((coord->y - center.y) * sin(angle));
	// new_y = center.y + ((coord->x - center.x) * sin(angle)) + ((coord->y - center.y) * cos(angle));
	new_x = center.x + ((coord->x - center.x) * cos(angle));
	coord->x = new_x;
	// coord->y = new_y;
}

void	rotate_X(t_Point2D *coord, double angle, t_Point2D center, int z_val)
{
	double	new_x;
	double	new_y;

	if (!coord)
		return ;
	// new_x = center.x + ((coord->x - center.x) * cos(angle)) - ((coord->y - center.y) * sin(angle));
	// new_y = center.y + ((coord->x - center.x) * sin(angle)) + ((coord->y - center.y) * cos(angle));
	new_y = center.y + ((coord->y - center.y) * cos(angle));
	coord->y = new_y;
	// coord->y = new_y;
}