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