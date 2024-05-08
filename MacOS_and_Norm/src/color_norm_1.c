/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_norm_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:54:59 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/04 15:55:02 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/color.h"

double	line_fraction(t_Line2D *line, int index)
{
	int		dx;
	int		dy;
	int		steps;
	double	fraction;

	if (!line)
		return (0.0);
	dx = abs(line->start.x - line->end.x);
	dy = abs(line->start.y - line->end.y);
	if (dx > dy)
		steps = dx;
	else
		steps = dy;
	fraction = (double)index / steps;
	return (fraction);
}

void	set_rgb(t_RGB *rgb_color, int color)
{
	if (!rgb_color)
		return ;
	rgb_color->r = (color >> 16) & 0xFF;
	rgb_color->g = (color >> 8) & 0xFF;
	rgb_color->b = color & 0xFF;
}

int	get_gradient_color(t_Line2D *line, int index)
{
	t_RGB	rgb_start;
	t_RGB	rgb_end;
	int		new_color;
	double	fraction;

	if (!line)
		return (0);
	set_rgb(&rgb_start, line->color_start);
	set_rgb(&rgb_end, line->color_end);
	new_color = 0;
	fraction = line_fraction(line, index);
	new_color = rgb_start.r + (rgb_end.r - rgb_start.r) * fraction;
	new_color = new_color << 8;
	new_color += rgb_start.g + (rgb_end.g - rgb_start.g) * fraction;
	new_color = new_color << 8;
	new_color += rgb_start.b + (rgb_end.b - rgb_start.b) * fraction;
	return (new_color);
}
