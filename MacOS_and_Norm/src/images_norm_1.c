/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_norm_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:06:50 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:07:10 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/images.h"

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

static void	del_buttons_norm(t_Image **buttons, void *mlx, int i)
{
	if (!buttons)
		return ;
	while (i >= 0)
	{
		delete_image(buttons[i], mlx);
		free(buttons[i]);
		--i;
	}
	free(buttons);
}

static void	just_for_norm(t_Image **buttons, int *x_new, int *y_new, int i)
{
	set_button_fields(buttons[i], *x_new, *y_new);
	*x_new += BUTTONS_X_SIZE + BUTTONS_GAP;
	if (i == (BUTTONS_TOTAL / 2) - 1)
	{
		*x_new = BUTTONS_X_POSITION;
		*y_new += BUTTONS_Y_SIZE + BUTTONS_GAP;
	}
}

t_Image	**create_buttons_image(void *mlx)
{
	t_Image	**buttons;
	int		i;
	int		x_new;
	int		y_new;

	if (!mlx)
		return (NULL);
	buttons = (t_Image **)malloc(sizeof(t_Image *) * (BUTTONS_TOTAL));
	if (!buttons)
		return (NULL);
	x_new = BUTTONS_X_POSITION;
	y_new = BUTTONS_Y_POSITION;
	i = -1;
	while (++i < BUTTONS_TOTAL)
	{
		buttons[i] = create_image(mlx, BUTTONS_X_SIZE, BUTTONS_Y_SIZE);
		if (!buttons[i])
		{
			del_buttons_norm(buttons, mlx, i);
			return (NULL);
		}
		just_for_norm(buttons, &x_new, &y_new, i);
	}
	set_buttons_name(buttons);
	return (buttons);
}
