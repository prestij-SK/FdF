#include "../header/fdf.h"

// -1 return will mean that no button was under mouse pointer
int	mouse_on_button(t_FdF *fdf_data, int x, int y)
{
	int	i;
	int	temp_width;
	int	temp_height;

	if (!fdf_data)
		return (BUTTONS_NOT_ACTIVE);
	i = 0;
	while (i < BUTTONS_TOTAL)
	{
		temp_width = fdf_data->buttons[i]->pos.x + fdf_data->buttons[i]->size.x;
		temp_height = fdf_data->buttons[i]->pos.y + fdf_data->buttons[i]->size.y;
		if ((x >= fdf_data->buttons[i]->pos.x) && (x <= temp_width) &&
			(y >= fdf_data->buttons[i]->pos.y) && (y <= temp_height))
		{
			return (i);
		}
		++i;
	}
	return (BUTTONS_NOT_ACTIVE);
}