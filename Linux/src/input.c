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
	if (!fdf_data)
		return (0);
	if (key == KEY_ESC)
		update_end_program(fdf_data);
	return (1);
}

int	input_close_window(t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	update_end_program(fdf_data);
	return (1);
}