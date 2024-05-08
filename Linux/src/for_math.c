#include "../header/for_math.h"

double	get_radians(int angle)
{
	return (angle * M_PI / 180.0);
}

void	rotate_X_2D(t_Point2D *coord, int angle, t_Point2D center)
{
	double	new_y;
	double	radian;

	if (!coord)
		return ;
	radian = get_radians(angle);
	new_y = center.y + ((coord->y - center.y) * cos(radian));
	coord->y = new_y;
}

void	rotate_Y_2D(t_Point2D *coord, int angle, t_Point2D center)
{
	double	new_x;
	double	radian;

	if (!coord)
		return ;
	radian = get_radians(angle);
	new_x = center.x + ((coord->x - center.x) * cos(radian));
	coord->x = new_x;
}

void	rotate_Z_2D(t_Point2D *coord, int angle, t_Point2D center)
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

void	rotate_X_3D(t_Point3D_d *coord, int angle, t_Point2D center, int z_val)
{
	t_Point3D_d	temp;
	double		radian = get_radians(angle);
	double		rotate[3][3] = {{1, 0, 0},
                       			{0, cos(radian), -sin(radian)},
                       			{0, sin(radian), cos(radian)}};

    temp.x = center.x + (rotate[0][0] * (coord->x - center.x)) + (rotate[0][1] * (coord->y - center.y)) + rotate[0][2] * z_val;
    temp.y = center.y + (rotate[1][0] * (coord->x - center.x)) + (rotate[1][1] * (coord->y - center.y)) + rotate[1][2] * z_val;
    temp.z = rotate[1][0] * coord->x + rotate[1][1] * coord->y + rotate[1][2] * z_val;

    coord->x = temp.x;
    coord->y = temp.y;
    coord->z = temp.z;
}

void	rotate_Y_3D(t_Point3D_d *coord, int angle, t_Point2D center, int z_val)
{
	t_Point3D_d	temp;
	double		radian = get_radians(angle);
	double		rotate[3][3] = {{cos(radian), 0, sin(radian)},
                       			{0, 1, 0},
                       			{-sin(radian), 0, cos(radian)}};

    temp.x = center.x + (rotate[0][0] * (coord->x - center.x)) + (rotate[0][1] * (coord->y - center.y)) + rotate[0][2] * z_val;
    temp.y = center.y + (rotate[1][0] * (coord->x - center.x)) + (rotate[1][1] * (coord->y - center.y)) + rotate[1][2] * z_val;
    temp.z = rotate[1][0] * coord->x  + rotate[1][1] * coord->y + rotate[1][2] * z_val;

    coord->x = temp.x;
    coord->y = temp.y;
    coord->z = temp.z;
}

void	rotate_Z_3D(t_Point3D_d *coord, int angle, t_Point2D center, int z_val)
{
	t_Point3D_d	temp;
	double		radian = get_radians(angle);
	double		rotate[3][3] = {{cos(radian), -sin(radian), 0},
                       			{sin(radian), cos(radian), 0},
                       			{0, 0, 1}};

    temp.x = center.x + (rotate[0][0] * (coord->x - center.x)) + (rotate[0][1] * (coord->y - center.y)) + rotate[0][2] * z_val;
    temp.y = center.y + (rotate[1][0] * (coord->x - center.x)) + (rotate[1][1] * (coord->y - center.y)) + rotate[1][2] * z_val;
    temp.z = rotate[1][0] * coord->x  + rotate[1][1] * coord->y + rotate[1][2] * z_val;

    coord->x = temp.x;
    coord->y = temp.y;
    coord->z = temp.z;
}

void    orthographic_projection(t_Point3D_d *coord, int z_val)
{
    double	pr[2][3] = {{1, 0, 0},
                        {0, 1, 0}};

    double new_x = pr[0][0] * coord->x + pr[0][1] * coord->y + pr[0][2] * z_val;
    double new_y = pr[1][0] * coord->x + pr[1][1] * coord->y + pr[1][2] * z_val;
    double new_z = pr[1][0] * coord->x + pr[1][1] * coord->y + pr[1][2] * z_val;

    coord->x = new_x;
    coord->y = new_y;
    coord->z = new_z;
}