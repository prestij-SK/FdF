#include "../header/fdf.h"

void	update_end_program(t_FdF *fdf_data)
{
	delete_fdf_data(fdf_data);
	delete_landscape_data(fdf_data->land_data);
	program_end();
}

void	update_buttons_hover(t_FdF *fdf_data, int x, int y)
{
	int	temp_index;

	if (!fdf_data)
		return ;
	temp_index = mouse_on_button(fdf_data, x, y);
	if (temp_index == BUTTONS_NOT_ACTIVE)
	{
		if (fdf_data->active_button != BUTTONS_NOT_ACTIVE)
		{
			fdf_data->buttons[fdf_data->active_button]->color = BUTTONS_COLOR;
			render_button(fdf_data, fdf_data->active_button);
			fdf_data->active_button = BUTTONS_NOT_ACTIVE;
		}
	}
	else
	{
		fdf_data->buttons[temp_index]->color = BUTTONS_COLOR_HOVER;
		render_button(fdf_data, temp_index);
		fdf_data->active_button = temp_index;
	}
}

// We don't need x and y, as fdf_data will have hover button's active index
void	update_mouse_left_click(t_FdF *fdf_data)
{
	char*	temp_str;

	if (!fdf_data)
		return ;
	if (fdf_data->active_button == BUTTONS_NOT_ACTIVE)
		return ;
	temp_str = fdf_data->buttons[fdf_data->active_button]->name;
	if (!ft_strncmp(temp_str, "Parallel", 8))
		printf("Paral\n");
	else if (!ft_strncmp(temp_str, "Conic", 5))
		printf("Con\n");
	else if (!ft_strncmp(temp_str, "Spin Left", 9))
	{
		// rotate_landscape(fdf_data->land_data, COORD_ANGLE);
		// render_land_table(fdf_data);
	}
	else if (!ft_strncmp(temp_str, "Spin Right", 10))
		printf("SpinR\n");
	else if (!ft_strncmp(temp_str, "Zoom In", 7))
		printf("Zin\n");
	else if (!ft_strncmp(temp_str, "Zoom Out", 8))
		printf("Zout\n");
	else if (!ft_strncmp(temp_str, "Move Left", 9))
		printf("ML\n");
	else if (!ft_strncmp(temp_str, "Move Right", 10))
		printf("MR\n");
	else if (!ft_strncmp(temp_str, "Move Up", 7))
		printf("MU\n");
	else if (!ft_strncmp(temp_str, "Move Down", 9))
		printf("MD\n");
	else if (!ft_strncmp(temp_str, "Reset", 5))
		printf("Res\n");
	else if (!ft_strncmp(temp_str, "Exit", 4))
		update_end_program(fdf_data);
}