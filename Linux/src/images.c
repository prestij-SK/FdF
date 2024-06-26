#include "../header/images.h"

void	delete_image(t_Image *img, void *mlx)
{
	if (!img || !mlx)
		return ;
	mlx_destroy_image(mlx, img->img);
}

t_Image	*create_image(void *mlx, int x_size, int y_size)
{
	t_Image	*new_img;

	if (!mlx)
		return (NULL);
	new_img = (t_Image *)malloc(sizeof(t_Image));
	if (!new_img)
		return (NULL);
	new_img->img = mlx_new_image(mlx, x_size, y_size);
	if (!new_img->img)
	{
		free(new_img);
		return (NULL);
	}
	new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bits_per_pixel,
										&new_img->line_length, &new_img->endian);
	if (!new_img->addr)
	{
		free(new_img);
		return (NULL);
	}
	return (new_img);
}

t_Image	*create_option_image(void *mlx)
{
	t_Image	*new_image;

	if (!mlx)
		return (NULL);
	new_image = create_image(mlx, OPTION_X_SIZE, OPTION_Y_SIZE);
	if (!new_image)
		return (NULL);
	new_image->name = "Option Table";
	new_image->pos.x = OPTION_X_POSITION;
	new_image->pos.y = OPTION_Y_POSITION;
	new_image->size.x = OPTION_X_SIZE;
	new_image->size.y = OPTION_Y_SIZE;
	new_image->color = OPTION_COLOR;
	return (new_image);
}

t_Image	*create_land_image(void *mlx)
{
	t_Image	*new_image;

	if (!mlx)
		return (NULL);
	new_image = create_image(mlx, LAND_X_SIZE, LAND_Y_SIZE);
	if (!new_image)
		return (NULL);
	new_image->name = "Landscape Table";
	new_image->pos.x = LAND_X_POSITION;
	new_image->pos.y = LAND_Y_POSITION;
	new_image->size.x = LAND_X_SIZE;
	new_image->size.y = LAND_Y_SIZE;
	new_image->color = LAND_COLOR;
	return (new_image);
}

void	delete_buttons_image(t_Image **buttons, void *mlx)
{
	int	i;

	if (!buttons || !mlx)
		return ;
	i = 0;
	while (i < BUTTONS_TOTAL)
	{
		delete_image(buttons[i], mlx);
		free(buttons[i]);
		buttons[i] = NULL;
		++i;
	}
}

static void	set_buttons_name(t_Image **buttons)
{
	if (!buttons)
		return ;
	buttons[0]->name = "Isometric";
	buttons[1]->name = "X Rotate";
	buttons[2]->name = "Y Rotate";
	buttons[3]->name = "Z Rotate";
	buttons[4]->name = "Zoom In";
	buttons[5]->name = "Move Left";
	buttons[6]->name = "Move Right";
	buttons[7]->name = "Fiesta";
	buttons[8]->name = "3D Plane";
	buttons[9]->name = "Reset";
	buttons[10]->name = "Conic";
	buttons[11]->name = "X Rotate*";
	buttons[12]->name = "Y Rotate*";
	buttons[13]->name = "Z Rotate*";
	buttons[14]->name = "Zoom Out";
	buttons[15]->name = "Move Up";
	buttons[16]->name = "Move Down";
	buttons[17]->name = "Do Nothing";
	buttons[18]->name = "2D Plane";
	buttons[19]->name = "Exit";
}

static void	set_button_fields(t_Image *button, int x, int y)
{
	if (!button)
		return ;
	button->pos.x = x;
	button->pos.y = y;
	button->size.x = BUTTONS_X_SIZE;
	button->size.y = BUTTONS_Y_SIZE;
	button->color = BUTTONS_COLOR;
}

t_Image	**create_buttons_image(void *mlx)
{
	t_Image	**buttons;
	int	i;
	int	x_new;
	int	y_new;

	if (!mlx)
		return (NULL);
	buttons = (t_Image **)malloc(sizeof(t_Image *) * (BUTTONS_TOTAL));
	if (!buttons)
		return (NULL);
	x_new = BUTTONS_X_POSITION;
	y_new = BUTTONS_Y_POSITION;
	i = 0;
	while (i < BUTTONS_TOTAL)
	{
		buttons[i] = create_image(mlx, BUTTONS_X_SIZE, BUTTONS_Y_SIZE);
		if (!buttons[i])
		{
			while (i >= 0)
			{
				delete_image(buttons[i], mlx);
				free(buttons[i]);
				--i;
			}
			free(buttons);
			return (NULL);
		}
		set_button_fields(buttons[i], x_new, y_new);
		x_new += BUTTONS_X_SIZE + BUTTONS_GAP;
		if (i == (BUTTONS_TOTAL / 2) - 1)
		{
			x_new = BUTTONS_X_POSITION;
			y_new += BUTTONS_Y_SIZE + BUTTONS_GAP;
		}
		++i;
	}
	set_buttons_name(buttons);
	return (buttons);
}