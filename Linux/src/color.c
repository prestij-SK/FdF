#include "../header/color.h"

static int	low_level_color(int val)
{
	if (val >= RANGE_LEVEL_LOW_1)
		return (COLOR_LEVEL_LOW_1);
	else if (val >= RANGE_LEVEL_LOW_2)
		return (COLOR_LEVEL_LOW_2);
	else if (val >= RANGE_LEVEL_LOW_3)
		return (COLOR_LEVEL_LOW_3);
	else if (val >= RANGE_LEVEL_LOW_4)
		return (COLOR_LEVEL_LOW_4);
	else if (val >= RANGE_LEVEL_LOW_5)
		return (COLOR_LEVEL_LOW_5);
	else if (val >= RANGE_LEVEL_LOW_6)
		return (COLOR_LEVEL_LOW_6);
	return (COLOR_LEVEL_LOW_7);
}

static int	high_level_color(int val)
{
	if (val <= RANGE_LEVEL_HIGH_1)
		return (COLOR_LEVEL_HIGH_1);
	else if (val <= RANGE_LEVEL_HIGH_2)
		return (COLOR_LEVEL_HIGH_2);
	else if (val <= RANGE_LEVEL_HIGH_3)
		return (COLOR_LEVEL_HIGH_3);
	else if (val <= RANGE_LEVEL_HIGH_4)
		return (COLOR_LEVEL_HIGH_4);
	else if (val <= RANGE_LEVEL_HIGH_5)
		return (COLOR_LEVEL_HIGH_5);
	else if (val <= RANGE_LEVEL_HIGH_6)
		return (COLOR_LEVEL_HIGH_6);
	else if (val <= RANGE_LEVEL_HIGH_7)
		return (COLOR_LEVEL_HIGH_7);
	else if (val <= RANGE_LEVEL_HIGH_8)
		return (COLOR_LEVEL_HIGH_8);
	return (COLOR_LEVEL_HIGH_9);
}

int	get_z_level_color(int z_val)
{
	if (z_val == RANGE_LEVEL_0)
		return (COLOR_LEVEL_0);
	if (z_val < RANGE_LEVEL_0)
		return (low_level_color(z_val));
	return (high_level_color(z_val));
}

double	line_fraction(t_Line2D *line, int index)
{
	int		dx;
	int		dy;
	double	fraction;

	if (!line)
		return (0.0);
	dx = abs(line->start.x - line->end.x);
	dy = abs(line->start.y - line->end.y);
	int steps = dx > dy ? dx : dy;
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