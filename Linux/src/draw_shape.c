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

int draw_line_Bresenham(t_Image *img, t_Line2D *line, int z_val)
{
    t_BresenhamUtils    util;
    int                 pixel_color;

    if (!img || !line)
        return (ERROR_VALUE);
    util.steep = is_steep(line->start, line->end); // Check if the line is steep
    // Swap coordinates if the line is steep to simplify calculations
    if (util.steep)
    {
        swap_int(&line->start.x, &line->start.y);
        swap_int(&line->end.x, &line->end.y);
    }
    // Ensure that we always iterate from left to right
    if (line->start.x > line->end.x)
    {
        swap_int(&line->start.x, &line->end.x);
        swap_int(&line->start.y, &line->end.y);
    }

    util.delta.x = line->end.x - line->start.x; // we don't need to use abs() here as we ensured to start from bigger
    util.delta.y = abs(line->end.y - line->start.y); // change in y
    util.plot = 2 * util.delta.y - util.delta.x ; // Initial decision parameter
    util.step.x = line->start.x < line->end.x ? 1 : -1; // Determine the direction in x
    util.step.y = line->start.y < line->end.y ? 1 : -1; // Determine the direction in y
    util.temp.x = line->start.x; // Initialize current x coordinate
    util.temp.y = line->start.y; // Initialize current y coordinate

    // int color;
    // if (z_val != 0)
    //     color = LINE_COLOR;
    // else
    //     color = 0xFF0000;
    // Iterate over each point along the line
    int i = 0;
    while (util.temp.x != line->end.x)
    {
        pixel_color = get_gradient_color(line, i);
        // Plot the point, taking into account whether the line is steep or not
        if (util.steep && in_range(util.temp.y, util.temp.x, img->size.x, img->size.y))
        {
            // pixel_color = get_gradient_color(line, util.temp.y, util.temp.x);
            alt_mlx_pixel_put(img, util.temp.y, util.temp.x, pixel_color);
        }
        else if (!util.steep && in_range(util.temp.x, util.temp.y, img->size.x, img->size.y))
        {
            // pixel_color = get_gradient_color(line, util.temp.x, util.temp.y);
            alt_mlx_pixel_put(img, util.temp.x, util.temp.y, pixel_color);
        }
        else
            return (0); // this will quit the function if the coordinates are not in image's range
        util.temp.x += util.step.x; // Move to the next x coordinate
        // Update decision parameter and y coordinate if necessary
        if (util.plot >= 0)
        {
            util.temp.y += util.step.y;
            util.plot -= 2 * util.delta.x;
        }
        util.plot += 2 * util.delta.y; // Update decision parameter for the next point
        ++i;
    }
    return (1);
}

void    draw_landscape_horizontal_lines(t_Landscape *land_data, t_Image *land_table)
{
    t_Line2D    line;
    t_Point2D   start;
    t_Point2D   end;
    int         i;
    int         j;

    if (!land_data || !land_table)
        return ;
    i = 0;
    while (i < land_data->size.y)
    {
        j = 0;
        while (j < land_data->size.x - 1)
        {
            landscape_set_coord(land_data, &start, j, i);
            landscape_set_coord(land_data, &end, j + 1, i);
            if (land_data->map[i][j] != 0)
            {
                if (land_data->z_val_flip)
                {
                    start.y += (land_data->map[i][j]) * COORD_Z_VALUE_MULTIPLIER;
                }
                else
                {
                    start.y -= (land_data->map[i][j]) * COORD_Z_VALUE_MULTIPLIER;
                }
            }
            if (land_data->map[i][j + 1] != 0)
            {
                if (land_data->z_val_flip)
                {
                    end.y += (land_data->map[i][j + 1]) * COORD_Z_VALUE_MULTIPLIER;
                }
                else
                {
                    end.y -= (land_data->map[i][j + 1]) * COORD_Z_VALUE_MULTIPLIER;
                }
            }
            line.start = start;
            line.end = end;
            line.color_start = get_z_level_color(land_data->map[i][j]);
            line.color_end = get_z_level_color(land_data->map[i][j + 1]);
            if (land_data->map[i][j] != 0 || land_data->map[i][j + 1] != 0)
                draw_line_Bresenham(land_table, &line, 1);
            else
                draw_line_Bresenham(land_table, &line, 0);
                // break ; this would optimize, but it will draw wrong when you get to edge x < 0 or y < 0
            ++j;
        }
        ++i;
    }
}

void    draw_landscape_vertical_lines(t_Landscape *land_data, t_Image *land_table)
{
    t_Line2D    line;
    t_Point2D   start;
    t_Point2D   end;
    int         i;
    int         j;

    if (!land_data || !land_table)
        return ;
    i = 0;
    while (i < land_data->size.x)
    {
        j = 0;
        while (j < land_data->size.y - 1)
        {
            landscape_set_coord(land_data, &start, i, j);
            landscape_set_coord(land_data, &end, i, j + 1);
            if (land_data->map[j][i] != 0)
            {
                if (land_data->z_val_flip)
                {
                    start.y += (land_data->map[j][i]) * COORD_Z_VALUE_MULTIPLIER;
                }
                else
                {
                    start.y -= (land_data->map[j][i]) * COORD_Z_VALUE_MULTIPLIER;
                }
            }
            if (land_data->map[j + 1][i] != 0)
            {
                if (land_data->z_val_flip)
                {
                    end.y += (land_data->map[j + 1][i]) * COORD_Z_VALUE_MULTIPLIER;
                }
                else
                {
                    end.y -= (land_data->map[j + 1][i]) * COORD_Z_VALUE_MULTIPLIER;
                }
            }
            line.start = start;
            line.end = end;
            line.color_start = get_z_level_color(land_data->map[j][i]);
            line.color_end = get_z_level_color(land_data->map[j + 1][i]);
            if (land_data->map[j][i] != 0 || land_data->map[j + 1][i] != 0)
                draw_line_Bresenham(land_table, &line, 1);
            else
                draw_line_Bresenham(land_table, &line, 0);
                // break ; this would optimize, but it will draw wrong when you get to edge x < 0 or y < 0
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