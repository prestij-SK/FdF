#include "../header/fdf.h"

void	update_buttons_hover(t_FdF *fdf_data, int x, int y)
{
	int	temp_index;

	if (!fdf_data)
		return ;
	temp_index = mouse_on_button(fdf_data, x, y);
	if (temp_index == BUTTONS_NOT_HOVER)
	{
		if (fdf_data->button_index != BUTTONS_NOT_HOVER)
		{
			fdf_data->buttons[fdf_data->button_index]->color = BUTTONS_COLOR;
			draw_button(fdf_data, fdf_data->button_index);
			fdf_data->button_index = BUTTONS_NOT_HOVER;
		}
	}
	else
	{
		fdf_data->buttons[temp_index]->color = BUTTONS_COLOR_HOVER;
		draw_button(fdf_data, temp_index);
		fdf_data->button_index = temp_index;
	}
}

void	update_end_program(t_FdF *fdf_data)
{
	delete_fdf_data(fdf_data);
	delete_land_data(fdf_data->land_data);
	print_message("Program Ended!\n");
	exit(EXIT_SUCCESS);
}