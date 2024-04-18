#ifndef LANDSCAPE_H
# define LANDSCAPE_H

# include "utils.h"
# include "file_control.h"

// COORDINATE DEFAULT OPTIONS
# define COORD_X_START 500
# define COORD_Y_START 200
# define COORD_X_GAP 50
# define COORD_Y_GAP 50
# define COORD_ANGLE 10

// ROTATING OPTIONS
# define ROTATE_LEFT -1
# define ROTATE_RIGHT 1

// MATH
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

// this is for Norminette only
typedef struct LandscapeUtils
{
	t_Point2D	temp;
	int			angle;
	double		radian;
}	t_LandscapeUtils;

typedef struct LandscapeData
{
	t_Point3D	**map;
	t_Point2D	size;
	// other stuff
	int			color;
}	t_Landscape;

/*
	landscape.c functions

	* create_landscape_data -  creates new 't_Landscape" type and returns it, NULL if creation failed.
	* delete_landscape_data - deletes all 'land_data' fields.
	* landscape_init - memory allocation for all 'land_data' fields.
	* assign_file_to_landscape - assigns matrix of strings to ints from parsed file content.
*/
t_Landscape	*create_landscape_data(t_FileData *file_data);
void		delete_landscape_data(t_Landscape *land_data);
int			landscape_init(t_Landscape *land_data, t_FileData *file_data);
int			assign_file_to_landscape(t_Landscape *land_data, t_FileData *file_data);

/*
	landscape_utils.c functions

*/
void	rotate_landscape(t_Landscape *land_data, int angle);

#endif