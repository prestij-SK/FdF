#include "../header/fdf.h"

int	input_mouse_move(int x, int y, t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	update_buttons_hover(fdf_data, x, y);
	return (1);
}

int	input_key_press(int key, t_FdF *fdf_data)
{
	// printf("%d: \n", key);
	if (!fdf_data)
		return (0);
	if (key == KEY_ESC)
		update_end_program(fdf_data);
	else if (key == KEY_LEFT_ARROW)
		update_left_arrow_key(fdf_data);
	else if (key == KEY_RIGHT_ARROW)
		update_right_arrow_key(fdf_data);
	else if (key == KEY_UP_ARROW)
		update_up_arrow_key(fdf_data);
	else if (key == KEY_DOWN_ARROW)
		update_down_arrow_key(fdf_data);
	else if (key == KEY_X)
		update_X_key(fdf_data);
	else if (key == KEY_C)
		update_C_key(fdf_data);
	else if (key == KEY_Z)
		update_Z_key(fdf_data);
	else if (key == KEY_S)
		update_A_key(fdf_data);
	else if (key == KEY_D)
		update_S_key(fdf_data);
	else if (key == KEY_A)
		update_D_key(fdf_data);
	return (1);
}

int	input_close_window(t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	update_end_program(fdf_data);
	return (1);
}

int	input_mouse_button(int button, int x, int y, t_FdF *fdf_data)
{
	(void) x;
	(void) y;
	// printf("%d\n", button);
	if (!fdf_data)
		return (0);
	if (button == LEFT_CLICK)
		update_mouse_left_click(fdf_data);
	else if (button == SCROLL_UP)
		update_mouse_scroll_up(fdf_data);
	else if (button == SCROLL_DOWN)
		update_mouse_scroll_down(fdf_data);
	// printf("zoom: %d\n", fdf_data->land_data->setup.zoom);
	return (1);
}