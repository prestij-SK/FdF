#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../header/landscape_init.h"

# define HORIZONTAL_RESOLUTION 1920
# define VERTICAL_RESOLUTION 1080

typedef struct FdFData
{
	void	*mlx;
	void	*mlx_window;
} 	t_FdF;

/*
	fdf_start.c functions

	* fdf_init - initializing all 'fdf_data' fields, returns true on success, else false.
	* fdf_start - makes all preparations and start the program.
	* delete_fdf_data - deletes all feilds of 'fdf_data'.
	* render_landscape - starting the program after preparations, returns true on success, else false.
*/
int		fdf_init(t_FdF *fdf_data);
void	fdf_start(char *file_name);
void	delete_fdf_data(t_FdF *fdf_data);
int		render_landscape(t_LandscapeData *land_data);

/*
	draw_landscape.c functions

	* draw_landscape - starting to draw landscape, returns true on success, else false.
*/
int	draw_landscape(t_LandscapeData *land_data, t_FdF *fdf_data);

#endif