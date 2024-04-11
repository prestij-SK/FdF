#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../header/landscape_init.h"

// WINDOW
# define WINDOW_HORIZONTAL_RESOLUTION 1920
# define WINDOW_VERTICAL_RESOLUTION 1080

// LAND
# define LAND_X_POSITION 0
# define LAND_Y_POSITION 0
# define LAND_X_SIZE 1920
# define LAND_Y_SIZE 730
# define LAND_COLOR 0x00222121

// INFO TABLE
# define TABLE_X_POSITION 0
# define TABLE_Y_POSITION 730
# define TABLE_X_SIZE 1920
# define TABLE_Y_SIZE 350
# define TABLE_COLOR 0x00454262

// BUTTONS
# define BUTTONS_X_POSITION 75
# define BUTTONS_Y_POSITION 750
# define BUTTONS_X_SIZE 100
# define BUTTONS_Y_SIZE 50
# define BUTTONS_GAP 25
# define BUTTONS_TOTAL 10
# define BUTTONS_COLOR 0x00B69D3A

typedef struct Point
{
	int	x;
	int	y;
}	t_Point;

typedef struct	ImageData {
	void	*img;
	char	*addr;
	char	*name;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_Point	pos;
	t_Point size;
	int		color;
	int		on_image;
}	t_Image;

typedef struct FdFData
{
	void		*mlx;
	void		*mlx_window;
	t_Image		*land;
	t_Image		*table;
	t_Image		**buttons;
} 	t_FdF;

typedef struct InputData
{
	int	is_esc;
	int	is_b1;
}	t_Input;

/*
	fdf_start.c functions

	* fdf_init - initializing all 'fdf_data' fields, returns true on success, else false.
	* fdf_start - makes all preparations and start the program.
	* delete_fdf_data - deletes all feilds of 'fdf_data'.
	* render_landscape - starting the program after preparations, returns true on success, else false.
	* image_init - creates new 't_Image' type and returns it after initializing all fields.
	* delete_buttons_image - deletes every button's image.
*/
int		fdf_init(t_FdF *fdf_data);
void	fdf_start(char *file_name);
void	delete_fdf_data(t_FdF *fdf_data);
int		render_landscape(t_LandscapeData *land_data);
t_Image	*image_init(void *mlx, int x_size, int y_size);
void	delete_buttons_image(t_FdF *fdf_data, int size);

/*
	fdf_draw.c functions

	* render - displays all components of 'fdf_data'.
	* input - hooks all inputs and initializes 'input_data' fields.
	* draw_landscape - starting to draw landscape, returns true on success, else false.
*/
void	render(t_FdF *fdf_data);
void	input(t_FdF *fdf_data, t_Input *input_data);
int		fdf_draw(t_LandscapeData *land_data, t_FdF *fdf_data);

/*
	fdf_draw.c functions

	* draw_rectangle - draws
*/
void draw_rectangle(t_Image *img);

/*
	input_handler.c functions

	* input_init - initialize all input combinations into their default state.
	* key_press - checks what key is pressed and initializes 'input_data' field.
*/
void	input_init(t_Input *input_data);
int		key_press(int key_code, t_Input *input_data);

#endif