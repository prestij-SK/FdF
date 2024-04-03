#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../header/landscape_init.h"

/*
	fdf_start.c functions

	* fdf_start - makes all preparations and start the program.
	* render_landscape - starting the program after perparations, which renders the landscape on the window.
*/
void	fdf_start(char *file_name);
int		render_landscape(t_LandscapeData *land_data);

#endif