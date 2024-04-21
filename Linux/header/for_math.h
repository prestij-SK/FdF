#ifndef FOR_MATH_H
# define FOR_MATH_H

# include "utils.h"

/*
	for_math.c functions

	* get_radians - returns the angle in radians.
	* rotate_Z - set given 'coord' x,y to its Z rotation by given angle.
*/
double	get_radians(int angle);
void	rotate_X(t_Point2D *coord, double angle, t_Point2D center, int z_val);
void	rotate_Y(t_Point2D *coord, double angle, t_Point2D center, int z_val);
void	rotate_Z(t_Point2D *coord, double angle, t_Point2D center, int z_val);

#endif