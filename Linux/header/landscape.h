#ifndef LANDSCAPE_H
# define LANDSCAPE_H

# include "utils.h"
# include "file_control.h"

// COORDINATE DEFAULT OPTIONS
# define COORD_X_START 100
# define COORD_Y_START 50
# define COORD_X_GAP_LOW 5
# define COORD_Y_GAP_LOW 5
# define COORD_X_GAP_MID 20
# define COORD_Y_GAP_MID 20
# define COORD_X_GAP_BIG 40
# define COORD_Y_GAP_BIG 40
# define COORD_X_ANGLE 45
# define COORD_Y_ANGLE 45
# define COORD_Z_ANGLE 45
# define COORD_ROTATE_ANGLE 5
# define COORD_PIXEL_MOVE_RANGE 5
# define COORD_PIXEL_ZOOM_RANGE 3
# define COORD_LINE_COLOR 0x00FF00
# define COORD_VERTEX_COLOR 0xFF0000

typedef struct LandscapeSetup
{
	t_Point2D	gap;
	t_Point2D	start;
	t_Point2D	end;
	t_Point2D	center;
	t_Point3D_d	angles; // x, y, z current angles in radians
	t_Point2D	move;
	double		rotate_angle; // in radians
	int			zoom;
	int			color; // line colors
	int			vertex_color; // line colors for z != 0
	// other stuff
}	t_LandSetup;

typedef struct LandscapeData
{
	int			**map; // z values
	t_Point2D	size; // matrix width(x) and height(y)
	t_LandSetup	setup; // valus of moving/zooming/rotating
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

	* landscape_set_default - set/reset all 'land_data' fields to their initial default values
	* landscape_set_coord - changes the 'coord', does all coordinate translate operations
*/
// void	rotate_landscape(t_Landscape *land_data, int angle);
void	landscape_set_default(t_Landscape *land_data, int table_x, int table_y);
void	landscape_set_coord(t_Landscape *land_data, t_Point2D *coord, int index_x, int index_y);

#endif