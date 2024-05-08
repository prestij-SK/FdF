/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landscape.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:38:25 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/04 15:46:00 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LANDSCAPE_H
# define LANDSCAPE_H

# include "utils.h"
# include "file_control.h"
# include "for_math.h"

// COORDINATE DEFAULT OPTIONS
# define COORD_X_START 100
# define COORD_Y_START 50
# define COORD_X_GAP_LOW 5
# define COORD_Y_GAP_LOW 5
# define COORD_X_GAP_MID 20
# define COORD_Y_GAP_MID 20
# define COORD_X_GAP_BIG 40
# define COORD_Y_GAP_BIG 40
# define COORD_X_ANGLE 30
# define COORD_Y_ANGLE 0
# define COORD_Z_ANGLE 45
# define COORD_ROTATE_ANGLE 5
# define COORD_PIXEL_MOVE_RANGE 10
# define COORD_PIXEL_ZOOM_RANGE 0.1
# define COORD_PIXEL_ZOOM_LIMIT 0.2
# define COORD_Z_VALUE_MULTIPLIER 20

// STATUS CODES
# define STATUS_IS_ACTIVE 1
# define STATUS_IS_NOT_ACTIVE 0

typedef struct LandscapeStatus
{
	int	is_isometric;
	int	is_conic;
	int	is_fiesta;
	int	is_2d;
	int	is_3d;
}	t_LandStatus;

typedef struct LandscapeSetup
{
	t_Point2D	gap;
	t_Point2D	start;
	t_Point2D	end;
	t_Point2D	center;
	t_Point2D	move;
	t_Point3D	angles;
	double		zoom;
	// other stuff
}	t_LandSetup;

typedef struct LandscapeData
{
	int				**map;
	t_Point2D		size;
	t_LandSetup		setup;
	t_LandStatus	status;
	int				z_val_flip;
}	t_Landscape;

/*
	landscape.c functions

	* create_landscape_data -  creates new 't_Landscape'type and
	* 						   returns it, NULL if creation failed.
	* delete_landscape_data - deletes all 'land_data' fields.
	* landscape_init - memory allocation for all 'land_data' fields.
	* assign_file_to_landscape - assigns matrix of strings to ints
	* 							 from parsed file content.
*/
t_Landscape	*create_landscape_data(t_FileData *file_data);
void		delete_landscape_data(t_Landscape *land_data);
int			landscape_init(t_Landscape *land_data, t_FileData *file_data);
int			assign_file_to_landscape(t_Landscape *land_data,
				t_FileData *file_data);

/*
	landscape_utils.c functions

	* landscape_set_default - set/reset all 'land_data' fields to
	* 					      their initial default values
*/
void		landscape_set_default(t_Landscape *land_data,
				int table_x, int table_y);

/*
	coordinate_utils.c

	* coord_operation - does the operation of the 'coord' by
	* 					using 'land_data' setup values.
	* coord_set_z_value - sets 'coord' y axis value by z_val.
	* 					  (these are the pointy mountain things)
	* landscape_set_coord - adds/inflicts all 'land_data' setup
	* 						options to 'coord'.
*/
void		coord_zoom(t_Landscape *land_data, t_Point2D *coord);
void		coord_move(t_Landscape *land_data, t_Point2D *coord);
void		coord_start(t_Landscape *land_data, t_Point2D *coord);
void		coord_center(t_Landscape *land_data, t_Point2D *new_center);
void		coord_set_z_value_2d(t_Landscape *land_data,
				t_Point2D *coord, int z_val);
void		coord_gap(t_Landscape *land_data, t_Point2D *coord,
				int index_x, int index_y);
void		landscape_set_coord_2d(t_Landscape *land_data,
				t_Point2D *coord, int index_x, int index_y);
void		landscape_set_coord_3d(t_Landscape *land_data,
				t_Point3D_d *coord, int index_x, int index_y);

#endif
