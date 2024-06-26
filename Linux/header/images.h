#ifndef IMAGES_H
# define IMAGES_H

# include "utils.h"
# include "color.h"
# include "../mlx_linux/mlx.h"

// LAND TABLE
# define LAND_X_POSITION 0
# define LAND_Y_POSITION 0
# define LAND_X_SIZE 1920
# define LAND_Y_SIZE 770

// OPTION TABLE
# define OPTION_X_POSITION 0
# define OPTION_Y_POSITION 770
# define OPTION_X_SIZE 1920
# define OPTION_Y_SIZE 310

// BUTTONS TABLE
# define BUTTONS_X_POSITION 75
# define BUTTONS_Y_POSITION 780
# define BUTTONS_X_SIZE 95
# define BUTTONS_Y_SIZE 45
# define BUTTONS_GAP 15
# define BUTTONS_TOTAL 20
# define BUTTONS_NOT_ACTIVE -1

typedef struct ImageData
{
	void		*img;
	char		*addr;
	char		*name;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_Point2D	pos;
	t_Point2D	size;
	int			color;
}	t_Image;

/*
	image.c functions

	* create_land_image - creates image for 'Land Table'.
	* create_option_image - creates image for 'Option Table'.
	* create_buttons_image - creates images for 'Buttons'.
	* delete_iamge - deletes all 'img' fields.
	* create_image - creates new 't_Image' type and returns it, NULL if creation failed.
	* delete_buttons_image - deletes all 'buttons' images
*/
t_Image	*create_land_image(void *mlx);
t_Image	*create_option_image(void *mlx);
t_Image	**create_buttons_image(void *mlx);
void	delete_image(t_Image *img, void *mlx);
t_Image	*create_image(void *mlx, int x_size, int y_size);
void	delete_buttons_image(t_Image **buttons, void *mlx);

#endif
