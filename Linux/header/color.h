#ifndef COLOR_H
# define COLOR_H

# include "utils.h"

// FDF IMAGE COLORS
# define LAND_COLOR 0x222020
# define OPTION_COLOR 0x3F3C5C
# define BUTTONS_COLOR 0xB69D3A
# define BUTTONS_COLOR_HOVER 0x81CA58
# define STRING_COLOR 0x000000

// LANDSCAPE LEVEL COLORS DEFAULT
# define COLOR_LEVEL_LOW_7 0xA82E21
# define COLOR_LEVEL_LOW_6 0x73351B
# define COLOR_LEVEL_LOW_5 0x5B4E1A
# define COLOR_LEVEL_LOW_4 0x0A461E
# define COLOR_LEVEL_LOW_3 0x2C2470
# define COLOR_LEVEL_LOW_2 0x2934CD
# define COLOR_LEVEL_LOW_1 0x45A2E9
# define COLOR_LEVEL_0 0x69D449
# define COLOR_LEVEL_HIGH_1 0x663300
# define COLOR_LEVEL_HIGH_2 0xBC752F
# define COLOR_LEVEL_HIGH_3 0x9FAE54
# define COLOR_LEVEL_HIGH_4 0x4D3C1C
# define COLOR_LEVEL_HIGH_5 0x4A463E
# define COLOR_LEVEL_HIGH_6 0x898782
# define COLOR_LEVEL_HIGH_7 0xA6D4CB
# define COLOR_LEVEL_HIGH_8 0xE7F2F0
# define COLOR_LEVEL_HIGH_9 0x3A44CD

// LANDSCAPE LEVEL RANGES
# define RANGE_LEVEL_LOW_7 -100
# define RANGE_LEVEL_LOW_6 -80
# define RANGE_LEVEL_LOW_5 -60
# define RANGE_LEVEL_LOW_4 -40
# define RANGE_LEVEL_LOW_3 -20
# define RANGE_LEVEL_LOW_2 -10
# define RANGE_LEVEL_LOW_1 -5
# define RANGE_LEVEL_0 0
# define RANGE_LEVEL_HIGH_1 5
# define RANGE_LEVEL_HIGH_2 10
# define RANGE_LEVEL_HIGH_3 20
# define RANGE_LEVEL_HIGH_4 30
# define RANGE_LEVEL_HIGH_5 40
# define RANGE_LEVEL_HIGH_6 50
# define RANGE_LEVEL_HIGH_7 60
# define RANGE_LEVEL_HIGH_8 80
# define RANGE_LEVEL_HIGH_9 100

typedef struct RGB
{
	int	r;
	int	g;
	int	b;
}	t_RGB;

typedef struct Line2D_int
{
	t_Point2D	start;
	t_Point2D	end;
	int			color_start;
	int			color_end;
}	t_Line2D;

/*
	color.c functions

	* get_z_level_color - every level of landscape will have a color, this function just chooses it by 'z_val'.
	* set_rgb - set 'rgb_color' r,g,b fields to 'color' first, second and third 8 bits
	* line_fraction - counting fraction for current pixel index on the line (interpolation)
	* get_gradient_color - returns the color for the current pixel of the line
*/
int		get_z_level_color(int z_val);
void	set_rgb(t_RGB *rgb_color, int color);
double	line_fraction(t_Line2D *line, int index);
int		get_gradient_color(t_Line2D *line, int index);

#endif