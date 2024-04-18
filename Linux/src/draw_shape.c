#include "../header/draw.h"

void    alt_mlx_pixel_put(t_Image *img, int x, int y, int color)
{
    char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_rectangle_filled(t_Image *img)
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
            *(unsigned int *)(img->addr + (i) * (img->bits_per_pixel / 8) +
							 			  (j) * img->line_length) = img->color;
            j++;
        }
        i++;
    }
}

void    draw_line_Bresenham(t_Image *img, t_Point2D start, t_Point2D end)
{
    t_BresenhamUtils    util;

    if (!img)
        return ;
    util.steep = is_steep(start, end); // Check if the line is steep
    // Swap coordinates if the line is steep to simplify calculations
    if (util.steep)
    {
        swap_int(&start.x, &start.y);
        swap_int(&end.x, &end.y);
    }
    // Ensure that we always iterate from left to right
    if (start.x > end.x)
    {
        swap_int(&start.x, &end.x);
        swap_int(&start.y, &end.y);
    }

    util.delta.x = end.x - start.x; // we don't need to use abs() here as we ensured to start from bigger
    util.delta.y = abs(end.y - start.y); // change in y
    util.plot = 2 * util.delta.y - util.delta.x ; // Initial decision parameter
    util.step.x = start.x < end.x ? 1 : -1; // Determine the direction in x
    util.step.y = start.y < end.y ? 1 : -1; // Determine the direction in y
    util.temp.x = start.x; // Initialize current x coordinate
    util.temp.y = start.y; // Initialize current y coordinate

    // Iterate over each point along the line
    while (util.temp.x != end.x)
    {
        // Plot the point, taking into account whether the line is steep or not
        if (util.steep)
            alt_mlx_pixel_put(img, util.temp.y, util.temp.x, LINE_COLOR);
        else
            alt_mlx_pixel_put(img, util.temp.x, util.temp.y, LINE_COLOR);
        util.temp.x += util.step.x; // Move to the next x coordinate

        // Update decision parameter and y coordinate if necessary
        if (util.plot >= 0)
        {
            util.temp.y += util.step.y;
            util.plot -= 2 * util.delta.x;
        }
        util.plot += 2 * util.delta.y; // Update decision parameter for the next point
    }
}

void    draw_landscape_horizontal_lines(t_Landscape *land_data, t_Image *land_table)
{
    t_Point2D start;
    t_Point2D end;
    int i;
    int j;

    if (!land_data || !land_table)
        return ;
    i = 0;
    while (i < land_data->size.y)
    {
        j = 0;
        while (j < land_data->size.x - 1)
        {
            start.x = land_data->map[i][j].x;
            start.y = land_data->map[i][j].y;
            end.x = land_data->map[i][j + 1].x;
            end.y = land_data->map[i][j + 1].y;
            draw_line_Bresenham(land_table, start, end);
            ++j;
        }
        ++i;
    }
}

void    draw_landscape_vertical_lines(t_Landscape *land_data, t_Image *land_table)
{
    t_Point2D start;
    t_Point2D end;
    int i;
    int j;

    if (!land_data || !land_table)
        return ;
    i = 0;
    while (i < land_data->size.y - 1)
    {
        j = 0;
        while (j < land_data->size.x)
        {
            start.x = land_data->map[i][j].x;
            start.y = land_data->map[i][j].y;
            end.x = land_data->map[i + 1][j].x;
            end.y = land_data->map[i + 1][j].y;
            draw_line_Bresenham(land_table, start, end);
            ++j;
        }
        ++i;
    }
}

void    draw_landscape(t_Landscape *land_data, t_Image *land_table)
{
    if (!land_data || !land_table)
        return ;
    draw_landscape_horizontal_lines(land_data, land_table);
    draw_landscape_vertical_lines(land_data, land_table);
}