#ifndef DRAW_H
# define DRAW_H

# include "utils.h"
# include "landscape.h"
# include "../mlx_linux/mlx.h"
# include "images.h"
# include "color.h"

// This is created just for Norminette
typedef struct BresenhamUtils
{
	t_Point2D	temp;
	t_Point2D	delta;
	t_Point2D	step;
	int			steep;
	int			plot;
}	t_BresenhamUtils;

/*
	draw_shape.c functions

	* draw_rectangle_filled - draws rectangle filled with image's color.
	* alt_mlx_pixel_put - draws pixel on the 'img' by given (x, y) and color.
	* draw_landscape - draws landscape on 'land_table' image.
	* draw_line_Bresenham - draws a line on the 'img' from (x1, y1) to (x2, y2) with Bresenham Algorithm.
	* draw_line_Bresenham_random_colors - does same line drawing but with random coloring on diagonals.
	* draw_landscape_vertical_lines - draws vertical lines coordinates of 'land_data' to 'land_table' image.
	* draw_landscape_horizontal_lines - draws horizontal lines coordinates of 'land_data' to 'land_table' image.
*/
void	draw_rectangle_filled(t_Image *img);
void	alt_mlx_pixel_put(t_Image *img, int x, int y, int color);
void    draw_landscape(t_Landscape *land_data, t_Image *land_table);
int		draw_line_Bresenham(t_Image *img, t_Line2D *line);
int		draw_line_Bresenham_random_colors(t_Image *img, t_Line2D *line);
void    draw_landscape_vertical_lines(t_Landscape *land_data, t_Image *land_table);
void    draw_landscape_horizontal_lines(t_Landscape *land_data, t_Image *land_table);

/*
	draw_utils.c functions

	is_steep - is the line steep by checking delta_y > delta_x.
	in_range - check if given coordinates are in range of width and height.
	setup_line_3D - initializes 'line' fields with given 'start' and 'end' coordinates for 3D plane.
*/
int		is_steep(t_Point2D start, t_Point2D end);
int		in_range(int x, int y, int width, int height);
void	setup_line_3D(t_Line2D *line, t_Point3D_d *start, t_Point3D_d *end);






void    new_draw_land(t_Landscape *land_data, t_Image *land_table);

#endif