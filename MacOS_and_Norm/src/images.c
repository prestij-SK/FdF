/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:49:14 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:06:33 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
