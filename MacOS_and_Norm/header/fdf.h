/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:10:45 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/04 15:14:22 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "utils.h"
# include "landscape.h"
# include "mlx.h"
# include "images.h"
# include "draw.h"
# include "for_math.h"
# include "color.h"

// WINDOW
# define WINDOW_WIDTH 2045
# define WINDOW_HEIGHT 1105

// HOOK EVENTS
# define EVENT_KEYDOWN 2 // pressed
# define EVENT_KEYUP 3 // released
// # define EVENT_MOUSEDOWN 4 // not used
// # define EVENT_MOUSEUP 5 // not used
# define EVENT_MOUSEMOVE 6
// # define EVENT_EXPOSE 12 // not used
# define EVENT_DESTROY 17 // Window cross icon

// KEY CODES FOR LINUX
// # define KEY_ESC 65307
// # define KEY_LEFT_ARROW 65361
// # define KEY_RIGHT_ARROW 65363
// # define KEY_UP_ARROW 65362
// # define KEY_DOWN_ARROW 65364
// # define KEY_X 120
// # define KEY_C 99
// # define KEY_Z 122
// # define KEY_A 97
// # define KEY_S 115
// # define KEY_D 100

// KEY CODES FOR MACOS
# define KEY_ESC 53
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_UP_ARROW 126
# define KEY_DOWN_ARROW 125
# define KEY_X 7
# define KEY_C 8
# define KEY_Z 6
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

// MOUSE CODES
# define LEFT_CLICK 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct FdFData
{
	void			*mlx;
	void			*mlx_window;
	t_Landscape		*land_data;
	t_Image			*land_table;
	t_Image			*option_table;
	t_Image			**buttons;
	int				active_button;
}	t_FdF;

/*
	fdf_start.c functions

	* fdf_start - makes all preparations and starts the program.
	* start_program - starting the main logic of FdF,
	* 				  returns true on success, else false.
	* delete_fdf_data - deletes all feilds of 'fdf_data'.
	* fdf_data_init - initializing all 'fdf_data' fields,
	* 				  returns true on success, else false.
*/
void	fdf_start(char *file_name);
int		start_program(t_FdF *fdf_data);
void	delete_fdf_data(t_FdF *fdf_data);
int		fdf_data_init(t_FdF *fdf_data, t_FileData *file_data);

/*
	input.c functions

	* input_close_window - called when top right window 'X'
	* 					   closing button is clicked.
	* input_key_press - handles every 'key' that is pressed during
	* 					the program.
	* input_mouse_move - checks the mouse movement and updates 'fdf_data'.
	* input_mouse_button - checks the mouse buttons clicks and updates
	* 					   'fdf_data'.
*/
int		input_close_window(t_FdF *fdf_data);
int		input_key_press(int key, t_FdF *fdf_data);
int		input_mouse_move(int x, int y, t_FdF *fdf_data);
int		input_mouse_button(int button, int x, int y, t_FdF *fdf_data);

/*
	update.c functions

	* update_XYZASD_key - these functions are for rotating for X,Y,Z axis.
	* 					  The ASD do the same but rotation to
	* 					  opposite side (to left).
	* update_conic - shows landscape in conic projection.
	* update_isometric - shows landscape in isometric projection.
	* update_party_time - shows landscape but with random colors
	* 					  on diagonals when moving.
	* update_end_program - deletes all allocated fields of 'fdf_data'
	* 					   and ends the program.
	* update_up_arrow_key - operation for UP arrow key (move up).
	* update_down_arrow_key - operation for DOWN arrow key (move down).
	* update_left_arrow_key - operation for LEFT arrow key (move left).
	* update_right_arrow_key - operation for RIGHT arrow key (move right).
	* update_mouse_scroll_up - operation for mouse scroll up (which is zoom in).
	* update_mouse_left_click - checks all buttons and does operation on
	* 						    landscape image.
	* update_mouse_scroll_down - operation for mouse scroll down
	* 							 (which is zoom out).
	* update_buttons_hover - checks all buttons and changes the color of the
	* 						 button on which mouse hovers. 
*/
int		update_frame(t_FdF *fdf_data);
void	update_x_key(t_FdF *fdf_data);
void	update_c_key(t_FdF *fdf_data);
void	update_z_key(t_FdF *fdf_data);
void	update_a_key(t_FdF *fdf_data);
void	update_s_key(t_FdF *fdf_data);
void	update_d_key(t_FdF *fdf_data);
void	update_conic(t_FdF *fdf_data);
void	update_2d_plane(t_FdF *fdf_data);
void	update_3d_plane(t_FdF *fdf_data);
void	update_isometric(t_FdF *fdf_data);
void	update_party_time(t_FdF *fdf_data);
void	update_end_program(t_FdF *fdf_data);
void	update_up_arrow_key(t_FdF *fdf_data);
void	update_down_arrow_key(t_FdF *fdf_data);
void	update_left_arrow_key(t_FdF *fdf_data);
void	update_right_arrow_key(t_FdF *fdf_data);
void	update_mouse_scroll_up(t_FdF *fdf_data);
void	update_mouse_left_click(t_FdF *fdf_data);
void	update_mouse_scroll_down(t_FdF *fdf_data);
void	update_buttons_hover(t_FdF *fdf_data, int x, int y);

/*
	update_utils.c functions

	* can_zoom_out - check if limit for zooming out is reached.
	* rotation_flip - this will flip z_values if rotation is in
	* 				  such coordinates quadrants that drawing
	* 				  would be different.
*/
int		can_zoom_out(t_Landscape *land_data);
void	rotation_flip(t_Landscape *land_data);

/*
	render.c functions

	* render_all - display every image of 'fdf_data'.
	* render_land_table - display land table.
	* render_option_table - display option table.
	* render_button - display button of given index
	* render_image - display given image.
*/
void	render_all(t_FdF *fdf_data);
void	render_land_table(t_FdF *fdf_data);
void	render_option_table(t_FdF *fdf_data);
void	render_button(t_FdF *fdf_data, int index);
void	render_image(t_FdF *fdf_data, t_Image *img);

/*
	fdf_utils.c functions

	* fdf_null_fields - set all 'fdf_data' fields to NULL.
	* mouse_on_button - finds and returns the button index in
	* 					which mouse cursor is pointing to.
*/
void	fdf_null_fields(t_FdF *fdf_data);
int		mouse_on_button(t_FdF *fdf_data, int x, int y);

#endif
