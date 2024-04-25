#ifndef FOR_MATH_H
# define FOR_MATH_H

# include "utils.h"

// CONSTANTS
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define FIRST_QUADRANT 0
# define SECOND_QUADRANT 1
# define THIRD_QUADRANT 2
# define FOURTH_QUADRANT 3
# define QUARTER_ROTATION_DEGREE 90
// # define HALF_ROTATION_DEGREE 180 // not used
// # define FULL_ROTATION_DEGREE 360 // not used

/*
	for_math.c functions

	* get_radians - returns the angle in radians.
	* rotate_X - set given 'coord' x,y to it's X rotation around the center by given angle.
	* rotate_Y - set given 'coord' x,y to it's Y rotation around the center by given angle.
	* rotate_Z - set given 'coord' x,y to it's Z rotation around the center by given angle.
*/
double	get_radians(int angle);
void	rotate_X(t_Point2D *coord, int angle, t_Point2D center);
void	rotate_Y(t_Point2D *coord, int angle, t_Point2D center);
void	rotate_Z(t_Point2D *coord, int angle, t_Point2D center);

#endif