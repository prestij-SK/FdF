#include "../header/fdf.h"

void	delete_buttons_image(t_FdF *fdf_data, int size)
{
	int i = 0;

	if (!fdf_data)
		return ;
	while (i < size)
	{
		mlx_destroy_image(fdf_data->mlx, fdf_data->buttons[i]->img);
		free(fdf_data->buttons[i]);
		++i;
	}
	free(fdf_data->buttons);
	fdf_data->buttons = NULL;
}

static void	set_buttons_name(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	fdf_data->buttons[0]->name = "name_1";
	fdf_data->buttons[1]->name = "name_2";
	fdf_data->buttons[2]->name = "name_3";
	fdf_data->buttons[3]->name = "name_4";
	fdf_data->buttons[4]->name = "name_5";
	fdf_data->buttons[5]->name = "name_6";
	fdf_data->buttons[6]->name = "name_7";
	fdf_data->buttons[7]->name = "name_8";
	fdf_data->buttons[8]->name = "name_9";
	fdf_data->buttons[9]->name = "name_10";
}

int	buttons_image_init(t_FdF *fdf_data)
{
	int	i;
	int	x_new;
	int	y_new;

	if (!fdf_data)
		return (0);
	fdf_data->buttons = (t_Image **)malloc(sizeof(t_Image *) * (BUTTONS_TOTAL + 1));
	if (!fdf_data->buttons)
		return (0);
	x_new = BUTTONS_X_POSITION;
	y_new = BUTTONS_Y_POSITION;
	i = 0;
	while (i < BUTTONS_TOTAL)
	{
		fdf_data->buttons[i] = image_init(fdf_data->mlx, BUTTONS_X_SIZE, BUTTONS_Y_SIZE);
		if (!fdf_data->buttons[i])
		{
			delete_buttons_image(fdf_data, i);
			return (0);
		}
		fdf_data->buttons[i]->pos.x = x_new;
		fdf_data->buttons[i]->pos.y = y_new;
		fdf_data->buttons[i]->size.x = BUTTONS_X_SIZE;
		fdf_data->buttons[i]->size.y = BUTTONS_Y_SIZE;
		fdf_data->buttons[i]->color = BUTTONS_COLOR;
		x_new += BUTTONS_X_SIZE + BUTTONS_GAP;
		if (i == (BUTTONS_TOTAL / 2) - 1)
		{
			x_new = BUTTONS_X_POSITION;
			y_new += BUTTONS_Y_SIZE + BUTTONS_GAP;
		}
		++i;
	}
	fdf_data->buttons[i] = NULL;
	set_buttons_name(fdf_data);
	return (1);
}

// -1 return will mean that no button was under mouse pointer
int	mouse_on_button(t_FdF *fdf_data, int x, int y)
{
	int	i;
	int	temp_width;
	int	temp_height;

	if (!fdf_data)
		return (BUTTONS_NOT_HOVER);
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
	return (BUTTONS_NOT_HOVER);
}