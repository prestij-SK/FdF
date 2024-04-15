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
# define BUTTONS_COLOR_HOVER 0x00FF00
# define BUTTONS_NOT_HOVER -1

// HOOK EVENT
# define EVENT_KEYDOWN 2 // pressed
# define EVENT_KEYUP 3 // released
# define EVENT_MOUSEDOWN 4
# define EVENT_MOUSEUP 5
# define EVENT_MOUSEMOVE 6
# define EVENT_EXPOSE 12
# define EVENT_DESTROY 17

// KEY CODES
# define KEY_ESC 65307

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
}	t_Image;

typedef struct FdFData
{
	void			*mlx;
	void			*mlx_window;
	t_LandscapeData	*land_data;
	t_Image			*land_table;
	t_Image			*option_table;
	t_Image			**buttons;
	int				button_index; // this will be used whenever mouse is on the button (-1 means no button is touched)
} 	t_FdF;

typedef struct InputData
{
	int	is_esc;
	int	is_b1;
}	t_Input;

/*
	fdf_start.c functions

	* render_error - exit with message of issue while trying to render the landscape. 
	* fdf_start - makes all preparations and starts the program.
	* delete_fdf_data - deletes all feilds of 'fdf_data'.
	* start_program - starting the main logic of FdF, returns true on success, else false.
	* fdf_data_init - initializing all 'fdf_data' fields, returns true on success, else false.
*/
void	render_error();
void	fdf_start(char *file_name);
void	delete_fdf_data(t_FdF *fdf_data);
int		start_program(t_LandscapeData *land_data);
int		fdf_data_init(t_FdF *fdf_data, t_LandscapeData *land_data);

/*
	buttons.c functions

	* buttons_image_init - initializing all 'fdf_data->buttons' fields, returns true on success, else false.
	* mouse_on_button - finds and returns the button index in which mouse cursor is pointing to.
	* delete_buttons_image - delets all fields of 'fdf_data->buttons'.
*/
int		buttons_image_init(t_FdF *fdf_data);
int		mouse_on_button(t_FdF *fdf_data, int x, int y);
void	delete_buttons_image(t_FdF *fdf_data, int size);

/*
	draw_shape.c functions

	* draw_rectangle_filled - draws rectangle filled with image's color.
*/
void draw_rectangle_filled(t_Image *img);

/*
	fdf_draw.c functions

	* fdf_draw - draws UI and the landscape, eturns true on success, else false.
*/
int	fdf_draw(t_FdF *fdf_data);

/*
	input.c functions

	* input_close_window - called when top right window 'X' closing button is clicked.
	* input_key_press - handles every 'key' that is pressed during the program.
	* input_mouse_move - checks the mouse movement and updates 'fdf_data'.
*/
int	input_close_window(t_FdF *fdf_data);
int	input_key_press(int key, t_FdF *fdf_data);
int	input_mouse_move(int x, int y, t_FdF *fdf_data);

/*
	update.c functions

	* update_end_program - deletes all allocated fields of 'fdf_data' and ends the program.
	* update_buttons_hover - checks all buttons and changes the color of the button on which mouse hovers. 
*/
void	update_end_program(t_FdF *fdf_data);
void	update_buttons_hover(t_FdF *fdf_data, int x, int y);

/*
	render.c functions

	* render_all - draws every image of 'fdf_data'.
*/
void	put_image(t_FdF *fdf_data, t_Image *img);
void	draw_button(t_FdF *fdf_data, int index);
void	draw_option_table(t_FdF *fdf_data);
void	draw_land_table(t_FdF *fdf_data);
void	render_all(t_FdF *fdf_data);

/*
	utils.c functions

	* print_message - prints the given 'str'.
	* split_size - returns the size of split (str**).
	* remove_last_enter - returns new string, but without last character if it was '\n'.
	* image_init - creates 't_Image' by given mlx and (x,y) size.
*/
void	print_message(char *str);
size_t	split_size(char **split);
char	*remove_last_enter(char *line);
t_Image	*image_init(void *mlx, int x_size, int y_size);

#endif