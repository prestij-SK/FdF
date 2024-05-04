#include "../header/fdf.h"

int	can_zoom_out(t_Landscape *land_data)
{
	int	current;

	if (!land_data)
		return (0);
	current = land_data->setup.gap.x + land_data->setup.zoom;
	if (current - COORD_PIXEL_ZOOM_RANGE <= 0)
		return (0);
	return (1);
}

void	rotation_flip(t_Landscape *land_data)
{
	int	x_angle;
	int	y_angle;

	if (!land_data)
		return ;
	x_angle = abs(land_data->setup.angles.x / QUARTER_ROTATION_DEGREE) % 4;
	y_angle = abs(land_data->setup.angles.y / QUARTER_ROTATION_DEGREE) % 4;
	if (x_angle == FIRST_QUADRANT || x_angle == FOURTH_QUADRANT)
		land_data->z_val_flip = 0;
	else if (x_angle == SECOND_QUADRANT || x_angle == THIRD_QUADRANT)
		land_data->z_val_flip = 1;
	if (land_data->z_val_flip)
	{
		if (y_angle == SECOND_QUADRANT || y_angle == THIRD_QUADRANT)
			land_data->z_val_flip = 0;
	}
	else if (y_angle == FIRST_QUADRANT || y_angle == FOURTH_QUADRANT)
		land_data->z_val_flip = 0;
	else if (y_angle == SECOND_QUADRANT || y_angle == THIRD_QUADRANT)
		land_data->z_val_flip = 1;
}