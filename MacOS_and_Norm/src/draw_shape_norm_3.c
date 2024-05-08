/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape_norm_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:19:06 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 14:20:59 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/draw.h"

void	alt_mlx_pixel_put(t_Image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_rectangle_filled(t_Image *img)
{
	int	i;
	int	j;

	if (!img)
		return ;
	i = 0;
	while (i < img->size.x)
	{
		j = 0;
		while (j < img->size.y)
		{
			*(unsigned int *)(img->addr + (i) * (img->bits_per_pixel / 8)
					+ (j) * img->line_length) = img->color;
			j++;
		}
		i++;
	}
}
