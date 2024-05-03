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
	* orthographic_projection - sets coordinate values to ortographic projection.
	* rotate_XYZ_2D - set given 'coord' x,y to it's X,Y,Z rotation around the center by given angle in 2D plane.
	* rotate_XYZ_3D - set given 'coord' x,y to it's X,Y,Z rotation around the center by given angle in 3D plane.
*/
double	get_radians(int angle);
void    orthographic_projection(t_Point3D_d *coord, int z_val);
void	rotate_X_2D(t_Point2D *coord, int angle, t_Point2D center);
void	rotate_Y_2D(t_Point2D *coord, int angle, t_Point2D center);
void	rotate_Z_2D(t_Point2D *coord, int angle, t_Point2D center);
void	rotate_X_3D(t_Point3D_d *coord, int angle, t_Point2D center, int z_val);
void	rotate_Y_3D(t_Point3D_d *coord, int angle, t_Point2D center, int z_val);
void	rotate_Z_3D(t_Point3D_d *coord, int angle, t_Point2D center, int z_val);

#endif