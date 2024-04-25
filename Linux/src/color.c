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

double	fraction_count(double p1, double p2, double p_curr)
{
	if (p1 != p2)
		return ((p_curr - p1) / (p2 - p1));
	return (0.0);
}

static float	line_fraction(t_Line2D *line, int index)
{
	int		dx;
	int		dy;
	float	fraction;

	if (!line)
		return (0.0);
	dx = abs(line->start.x - line->end.x);
	dy = abs(line->start.y - line->end.y);
	int steps = dx > dy ? dx : dy;
	// if (dx > dy)
	// 	fraction = fraction_count(line->start.x, line->end.x, curr_x);
	// else
	// 	fraction = fraction_count(line->start.y, line->end.y, curr_y);
	fraction = (float)index / steps;
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

// int get_gradient_color(t_Line2D *line, int index)
// {
//     t_RGB rgb_start;
//     t_RGB rgb_end;
//     t_RGB new_color;

//     if (!line)
//         return 0;

//     set_rgb(&rgb_start, line->color_start);
//     set_rgb(&rgb_end, line->color_end);

//     float fraction = line_fraction(line, index);

// 	new_color.r = rgb_start.r + (rgb_end.r - rgb_start.r) * fraction;
// 	new_color.g = rgb_start.g + (rgb_end.g - rgb_start.g) * fraction;
// 	new_color.b = rgb_start.b + (rgb_end.b - rgb_start.b) * fraction;

//     // Interpolate each color component separately
//     // int r = (int)(rgb_start.r + (rgb_end.r - rgb_start.r) * fraction);
//     // int g = (int)(rgb_start.g + (rgb_end.g - rgb_start.g) * fraction);
//     // int b = (int)(rgb_start.b + (rgb_end.b - rgb_start.b) * fraction);

//     // Ensure color component values stay within [0, 255] range
//     new_color.r = (new_color.r < 0) ? 0 : ((new_color.r > 255) ? 255 : new_color.r);
//     new_color.g = (new_color.g < 0) ? 0 : ((new_color.g > 255) ? 255 : new_color.g);
//     new_color.b = (new_color.b < 0) ? 0 : ((new_color.b > 255) ? 255 : new_color.b);

//     // Pack the RGB components into a single integer

//     return (new_color.r << 16) | (new_color.g << 8) | new_color.b;
// }