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

void	update_mouse_scroll_up(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.zoom += COORD_PIXEL_ZOOM_RANGE;
}

void	update_mouse_scroll_down(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	if (fdf_data->land_data->setup.zoom - COORD_PIXEL_ZOOM_RANGE <= COORD_PIXEL_ZOOM_LIMIT)
		return ;
	fdf_data->land_data->setup.zoom -= COORD_PIXEL_ZOOM_RANGE;
}

void	update_left_arrow_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.move.x -= COORD_PIXEL_MOVE_RANGE;
}

void	update_right_arrow_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.move.x += COORD_PIXEL_MOVE_RANGE;
}

void	update_up_arrow_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.move.y -= COORD_PIXEL_MOVE_RANGE;
}

void	update_down_arrow_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.move.y += COORD_PIXEL_MOVE_RANGE;
}

// Rotation X
void	update_X_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.x += COORD_ROTATE_ANGLE;
	rotation_flip(fdf_data->land_data);
}

// Rotation X opposite
void	update_S_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.x -= COORD_ROTATE_ANGLE;
	rotation_flip(fdf_data->land_data);
}

// Rotation Y
void	update_C_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.y += COORD_ROTATE_ANGLE;
	rotation_flip(fdf_data->land_data);
}

// Rotation Y opposite
void	update_D_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.y -= COORD_ROTATE_ANGLE;
}

// Rotation Z
void	update_Z_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.z += COORD_ROTATE_ANGLE;
}

// Rotation Z opposite
void	update_A_key(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->setup.angles.z -= COORD_ROTATE_ANGLE;
	rotation_flip(fdf_data->land_data);
}

// Random coloring diagonal lines
void	update_party_time(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	if (!fdf_data->land_data->status.is_fiesta)
	{
		fdf_data->land_data->status.is_fiesta = STATUS_IS_ACTIVE;
		return ;
	}
	fdf_data->land_data->status.is_fiesta = STATUS_IS_NOT_ACTIVE;
}

// Show landscape in isometric projection
void	update_isometric(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->status.is_isometric = STATUS_IS_ACTIVE;
	fdf_data->land_data->status.is_conic = STATUS_IS_NOT_ACTIVE;
	fdf_data->land_data->setup.angles.x = COORD_X_ANGLE;
	fdf_data->land_data->setup.angles.y = COORD_Y_ANGLE;
	fdf_data->land_data->setup.angles.z = COORD_Z_ANGLE;
}

// Show landscape int conic projection
void	update_conic(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->status.is_conic = STATUS_IS_ACTIVE;
	fdf_data->land_data->status.is_isometric = STATUS_IS_NOT_ACTIVE;
	fdf_data->land_data->setup.angles.x = 0;
	fdf_data->land_data->setup.angles.y = 0;
	fdf_data->land_data->setup.angles.z = 0;
}

void update_2D_Plane(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->status.is_2D = STATUS_IS_ACTIVE;
	fdf_data->land_data->status.is_3D = STATUS_IS_NOT_ACTIVE;
}

void update_3D_Plane(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->land_data->status.is_3D = STATUS_IS_ACTIVE;
	fdf_data->land_data->status.is_2D = STATUS_IS_NOT_ACTIVE;
}

// We don't need x and y, as fdf_data will have hover button's active index
void	update_mouse_left_click(t_FdF *fdf_data)
{
	char	*temp_str;

	if (!fdf_data)
		return ;
	if (fdf_data->active_button == BUTTONS_NOT_ACTIVE)
		return ;
	temp_str = fdf_data->buttons[fdf_data->active_button]->name;
	if (!ft_strncmp(temp_str, "Isometric", 9))
		update_isometric(fdf_data);
	else if (!ft_strncmp(temp_str, "Conic", 5))
		update_conic(fdf_data);
	else if (!ft_strncmp(temp_str, "X Rotate*", 9))
		update_S_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Y Rotate*", 9))
		update_D_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Z Rotate*", 9))
		update_A_key(fdf_data);
	else if (!ft_strncmp(temp_str, "X Rotate", 8))
		update_X_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Y Rotate", 8))
		update_C_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Z Rotate", 8))
		update_Z_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Zoom In", 7))
		update_mouse_scroll_up(fdf_data);
	else if (!ft_strncmp(temp_str, "Zoom Out", 8))
		update_mouse_scroll_down(fdf_data);
	else if (!ft_strncmp(temp_str, "Move Left", 9))
		update_left_arrow_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Move Right", 10))
		update_right_arrow_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Move Up", 7))
		update_up_arrow_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Move Down", 9))
		update_down_arrow_key(fdf_data);
	else if (!ft_strncmp(temp_str, "Fiesta", 6))
		update_party_time(fdf_data);
	else if (!ft_strncmp(temp_str, "Reset", 5))
		landscape_set_default(fdf_data->land_data, fdf_data->land_table->size.x, fdf_data->land_table->size.y);
	else if (!ft_strncmp(temp_str, "2D Plane", 8))
		update_2D_Plane(fdf_data);
	else if (!ft_strncmp(temp_str, "3D Plane", 8))
		update_3D_Plane(fdf_data);
	else if (!ft_strncmp(temp_str, "Exit", 4))
		update_end_program(fdf_data);
}

int	update_frame(t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	render_land_table(fdf_data);
	// printf("x_angle: %d   %d\n", fdf_data->land_data->setup.angles.x, fdf_data->land_data->z_val_flip);
	// printf("y_angle: %d   %d\n", fdf_data->land_data->setup.angles.y, fdf_data->land_data->z_val_flip);
	return (1);
}