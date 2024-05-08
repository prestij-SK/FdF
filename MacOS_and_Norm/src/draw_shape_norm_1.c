/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape_norm_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:50:04 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 13:59:42 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/draw.h"

static void	line_preperation_norm(t_BresenhamUtils *util, t_Line2D *line)
{
	util->steep = is_steep(line->start, line->end);
	if (util->steep)
	{
		swap_int(&line->start.x, &line->start.y);
		swap_int(&line->end.x, &line->end.y);
	}
	if (line->start.x > line->end.x)
	{
		swap_int(&line->start.x, &line->end.x);
		swap_int(&line->start.y, &line->end.y);
		swap_int(&line->color_start, &line->color_end);
	}
	util->delta.x = line->end.x - line->start.x;
	util->delta.y = abs(line->end.y - line->start.y);
	util->plot = 2 * util->delta.y - util->delta.x;
	if (line->start.x < line->end.x)
		util->step.x = 1;
	else
		util->step.x = -1;
	if (line->start.y < line->end.y)
		util->step.y = 1;
	else
		util->step.y = -1;
	util->temp.x = line->start.x;
	util->temp.y = line->start.y;
}

static void	plot_check_norm(t_BresenhamUtils *util)
{
	if (!util)
		return ;
	if (util->plot >= 0)
	{
		util->temp.y += util->step.y;
		util->plot -= 2 * util->delta.x;
	}
}

int	draw_line_bresenham(t_Image *img, t_Line2D *line)
{
	t_BresenhamUtils	util;
	int					pixel_color;
	int					i;

	if (!img || !line)
		return (ERROR_VALUE);
	line_preperation_norm(&util, line);
	i = 0;
	while (util.temp.x != line->end.x)
	{
		pixel_color = get_gradient_color(line, i);
		if (util.steep && in_range(util.temp.y, util.temp.x,
				img->size.x, img->size.y))
			alt_mlx_pixel_put(img, util.temp.y, util.temp.x, pixel_color);
		else if (!util.steep && in_range(util.temp.x, util.temp.y,
				img->size.x, img->size.y))
			alt_mlx_pixel_put(img, util.temp.x, util.temp.y, pixel_color);
		else
			return (0);
		util.temp.x += util.step.x;
		plot_check_norm(&util);
		util.plot += 2 * util.delta.y;
		++i;
	}
	return (1);
}

int	draw_line_bresenham_random_colors(t_Image *img, t_Line2D *line)
{
	t_BresenhamUtils	util;
	int					pixel_color;

	if (!img || !line)
		return (ERROR_VALUE);
	line_preperation_norm(&util, line);
	while (util.temp.x != line->end.x)
	{
		pixel_color = get_gradient_color(line, util.temp.x);
		if (util.steep && in_range(util.temp.y, util.temp.x,
				img->size.x, img->size.y))
			alt_mlx_pixel_put(img, util.temp.y, util.temp.x, pixel_color);
		else if (!util.steep && in_range(util.temp.x, util.temp.y,
				img->size.x, img->size.y))
			alt_mlx_pixel_put(img, util.temp.x, util.temp.y, pixel_color);
		else
			return (0);
		util.temp.x += util.step.x;
		plot_check_norm(&util);
		util.plot += 2 * util.delta.y;
	}
	return (1);
}
