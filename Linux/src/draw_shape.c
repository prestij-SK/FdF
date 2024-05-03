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

int draw_line_Bresenham(t_Image *img, t_Line2D *line)
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
        swap_int(&line->color_start, &line->color_end);
    }

    util.delta.x = line->end.x - line->start.x; // we don't need to use abs() here as we ensured to start from bigger
    util.delta.y = abs(line->end.y - line->start.y); // change in y
    util.plot = 2 * util.delta.y - util.delta.x ; // Initial decision parameter
    util.step.x = line->start.x < line->end.x ? 1 : -1; // Determine the direction in x
    util.step.y = line->start.y < line->end.y ? 1 : -1; // Determine the direction in y
    util.temp.x = line->start.x; // Initialize current x coordinate
    util.temp.y = line->start.y; // Initialize current y coordinate

    int i = 0; // n-th pixel counter along the line
    while (util.temp.x != line->end.x)
    {
        pixel_color = get_gradient_color(line, i);
        // Plot the point, taking into account whether the line is steep or not
        if (util.steep && in_range(util.temp.y, util.temp.x, img->size.x, img->size.y))
            alt_mlx_pixel_put(img, util.temp.y, util.temp.x, pixel_color);
        else if (!util.steep && in_range(util.temp.x, util.temp.y, img->size.x, img->size.y))
            alt_mlx_pixel_put(img, util.temp.x, util.temp.y, pixel_color);
        else
            return (0); // Quit the function if the coordinates are not in image's range
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

int draw_line_Bresenham_random_colors(t_Image *img, t_Line2D *line)
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

    while (util.temp.x != line->end.x)
    {
        // Plot the point, taking into account whether the line is steep or not
        if (util.steep && in_range(util.temp.y, util.temp.x, img->size.x, img->size.y))
        {
            pixel_color = get_gradient_color(line, util.temp.y);
            alt_mlx_pixel_put(img, util.temp.y, util.temp.x, pixel_color);
        }
        else if (!util.steep && in_range(util.temp.x, util.temp.y, img->size.x, img->size.y))
        {
            pixel_color = get_gradient_color(line, util.temp.x);
            alt_mlx_pixel_put(img, util.temp.x, util.temp.y, pixel_color);
        }
        else
            return (0); // Quit the function if the coordinates are not in image's range
        util.temp.x += util.step.x; // Move to the next x coordinate
        // Update decision parameter and y coordinate if necessary
        if (util.plot >= 0)
        {
            util.temp.y += util.step.y;
            util.plot -= 2 * util.delta.x;
        }
        util.plot += 2 * util.delta.y; // Update decision parameter for the next point
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
            landscape_set_coord_2D(land_data, &start, j, i);
            landscape_set_coord_2D(land_data, &end, j + 1, i);
            if (land_data->status.is_isometric)
            {
                coord_set_z_value_2D(land_data, &start, land_data->map[i][j]);
                coord_set_z_value_2D(land_data, &end, land_data->map[i][j + 1]);
            }
            line.start = start;
            line.end = end;
            line.color_start = get_z_level_color(land_data->map[i][j]);
            line.color_end = get_z_level_color(land_data->map[i][j + 1]);
            if (land_data->status.is_fiesta)
                draw_line_Bresenham_random_colors(land_table, &line);
            else
                draw_line_Bresenham(land_table, &line);
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
            landscape_set_coord_2D(land_data, &start, i, j);
            landscape_set_coord_2D(land_data, &end, i, j + 1);
            if (land_data->status.is_isometric)
            {
                coord_set_z_value_2D(land_data, &start, land_data->map[j][i]);
                coord_set_z_value_2D(land_data, &end, land_data->map[j + 1][i]);
            }
            line.start = start;
            line.end = end;
            line.color_start = get_z_level_color(land_data->map[j][i]);
            line.color_end = get_z_level_color(land_data->map[j + 1][i]);
            if (land_data->status.is_fiesta)
                draw_line_Bresenham_random_colors(land_table, &line);
            else
                draw_line_Bresenham(land_table, &line);
            ++j;
        }
        ++i;
    }
}

// void    new_z(t_Point2D *coord, t_Point2D center, int angle, int z_val, double *z_cord)
// {
// 	double	radian;
//     double c[3] = {coord->x, coord->y, z_val};
//     // double project[2][3] = {{1, 0, 0},
//     //                         {0, 1, 0}};
// 	radian = get_radians(angle);
//     double rz[3][3] = {{cos(radian), -sin(radian), 0},
//                        {sin(radian), cos(radian), 0},
//                        {0, 0, 1}};

//     double new_x = center.x + (rz[0][0] * (c[0] - center.x)) + (rz[0][1] * (c[1] - center.y)) + rz[0][2] * c[2];
//     double new_y = center.y + (rz[1][0] * (c[0] - center.x)) + (rz[1][1] * (c[1] - center.y)) + rz[1][2] * c[2];
//     double new_z = rz[1][0] * c[0] + rz[1][1] * c[1] + rz[1][2] * c[2];

//     coord->x = new_x;
//     coord->y = new_y;
//     *z_cord = new_z;
//     // coord->x = project[0][0] * new_x + project[0][1] * new_y + project[0][2] * new_z;
//     // coord->y = project[1][0] * new_x + project[1][1] * new_y + project[1][2] * new_z;
//     // coord->z = project[1][0] * new_x + project[1][1] * new_y + project[1][2] * new_z;
// }

// void    new_x(t_Point2D *coord, t_Point2D center, int angle, int z_val, double *z_cord)
// {
// 	double	radian;
//     double c[3] = {coord->x, coord->y, z_val};
//     // double project[2][3] = {{1, 0, 0},
//     //                         {0, 1, 0}};

// 	radian = get_radians(angle);
//     double rz[3][3] = {{1, 0, 0},
//                        {0, cos(radian), -sin(radian)},
//                        {0, sin(radian), cos(radian)}};

//     double new_x = center.x + (rz[0][0] * (c[0] - center.x)) + (rz[0][1] * (c[1] - center.y)) + rz[0][2] * c[2];
//     double new_y = center.y + (rz[1][0] * (c[0] - center.x)) + (rz[1][1] * (c[1] - center.y)) + rz[1][2] * c[2];
//     double new_z = rz[1][0] * c[0] + rz[1][1] * c[1] + rz[1][2] * c[2];

//     coord->x = new_x;
//     coord->y = new_y;
//     *z_cord = new_z;
//     // coord->x = project[0][0] * new_x + project[0][1] * new_y + project[0][2] * new_z;
//     // coord->y = project[1][0] * new_x + project[1][1] * new_y + project[1][2] * new_z;
//     // coord->z = project[1][0] * new_x + project[1][1] * new_y + project[1][2] * new_z;
// }

// void    new_y(t_Point2D *coord, t_Point2D center, int angle, int z_val, double *z_cord)
// {
// 	double	radian;
//     double c[3] = {coord->x, coord->y, z_val};
//     // double project[2][3] = {{1, 0, 0},
//     //                         {0, 1, 0}};
// 	radian = get_radians(angle);
//     double rz[3][3] = {{cos(radian), 0, sin(radian)},
//                        {0, 1, 0},
//                        {-sin(radian), 0, cos(radian)}};

//     double new_x = center.x + (rz[0][0] * (c[0] - center.x)) + (rz[0][1] * (c[1] - center.y)) + rz[0][2] * c[2];
//     double new_y = center.y + (rz[1][0] * (c[0] - center.x)) + (rz[1][1] * (c[1] - center.y)) + rz[1][2] * c[2];
//     double new_z = rz[1][0] * c[0] + rz[1][1] * c[1] + rz[1][2] * c[2];

//     coord->x = new_x;
//     coord->y = new_y;
//     *z_cord = new_z;
//     // coord->x = project[0][0] * new_x + project[0][1] * new_y + project[0][2] * new_z;
//     // coord->y = project[1][0] * new_x + project[1][1] * new_y + project[1][2] * new_z;
//     // coord->z = project[1][0] * new_x + project[1][1] * new_y + project[1][2] * new_z;
// }

// void    project(t_Point2D *coord, double *z_cord)
// {
//     double project[2][3] = {{1, 0, 0},
//                             {0, 1, 0}};
//     double new_x = project[0][0] * coord->x + project[0][1] * coord->y  + project[0][2] * *z_cord;
//     double new_y = project[1][0] * coord->x + project[1][1] * coord->y + project[1][2] * *z_cord;
//     double new_z = project[1][0] * coord->x + project[1][1] * coord->y + project[1][2] * *z_cord;
//     coord->x = new_x;
//     coord->y = new_y;
//     *z_cord = new_z;
// }

// void    new_draw_land(t_Landscape *land_data, t_Image *land_table)
// {
//     t_Line2D    line;
//     t_Point2D   start;
//     t_Point2D   end;
//     int         i;
//     int         j;

//     if (!land_data || !land_table)
//         return ;
//     i = 0;
//     while (i < land_data->size.y - 1)
//     {
//         j = 0;
//         while (j < land_data->size.x - 1)
//         {
//             t_Point2D	new_center;
//             new_center = land_data->setup.center;

// 			coord_start(land_data, &start);
// 			coord_start(land_data, &end);
// 			coord_gap(land_data, &start, j, i);
// 			coord_gap(land_data, &end, j, i + 1);
//             coord_center(land_data, &new_center);
//             int z_s = land_data->map[i][j] * 5;
//             int z_e = land_data->map[i + 1][j] * 5;
//             double z_cord;
//             new_z(&start, new_center, land_data->setup.angles.z, z_s, &z_cord);
//             new_x(&start, new_center, land_data->setup.angles.x, z_s, &z_cord);
//             new_y(&start, new_center, land_data->setup.angles.y, z_s, &z_cord);
//             // project(&start, &z_cord);
//             new_z(&end, new_center, land_data->setup.angles.z, z_e, &z_cord);
//             new_y(&end, new_center, land_data->setup.angles.y, z_e, &z_cord);
//             new_x(&end, new_center, land_data->setup.angles.x, z_e, &z_cord);
//             // project(&end, &z_cord);
//             line.start = start;
//             line.end = end;
//             line.color_start = get_z_level_color(land_data->map[i][j]);
//             line.color_end = get_z_level_color(land_data->map[i + 1][j]);
//             draw_line_Bresenham(land_table, &line);

//             coord_start(land_data, &start);
// 			coord_start(land_data, &end);
// 			coord_gap(land_data, &start, j, i);
// 			coord_gap(land_data, &end, j + 1, i);
//             z_s = land_data->map[i][j] * 5;
//             z_e = land_data->map[i][j + 1] * 5;
//             new_z(&start, new_center, land_data->setup.angles.z, z_s, &z_cord);
//             new_x(&start, new_center, land_data->setup.angles.x, z_s, &z_cord);
//             new_y(&start, new_center, land_data->setup.angles.y, z_s, &z_cord);
//             // project(&start, &z_cord);
//             new_z(&end, new_center, land_data->setup.angles.z, z_e, &z_cord);
//             new_y(&end, new_center, land_data->setup.angles.y, z_e, &z_cord);
//             new_x(&end, new_center, land_data->setup.angles.x, z_e, &z_cord);
//             // project(&end, &z_cord);
//             line.start = start;
//             line.end = end;
//             line.color_start = get_z_level_color(land_data->map[i][j]);
//             line.color_end = get_z_level_color(land_data->map[i][j + 1]);
//             draw_line_Bresenham(land_table, &line);
//             ++j;
//         }
//         ++i;
//     }
// }

static void draw_horizontal_line(t_Landscape *land_data, t_Image *land_table, int index_x, int index_y)
{
    t_Line2D    line;
    t_Point3D_d start;
    t_Point3D_d end;

    if (!land_data || !land_table)
        return ;
    landscape_set_coord_3D(land_data, &start, index_x, index_y);
    landscape_set_coord_3D(land_data, &end, index_x + 1, index_y); // +1 for horizontal
    // setup_line_3D(&line, &start, &end);
    line.start.x = start.x;
	line.start.y = start.y;
	line.end.x = end.x;
	line.end.y = end.y;
    line.color_start = get_z_level_color(land_data->map[index_y][index_x]);
	line.color_end = get_z_level_color(land_data->map[index_y][index_x + 1]);
    if (land_data->status.is_fiesta)
        draw_line_Bresenham_random_colors(land_table, &line);
    else
        draw_line_Bresenham(land_table, &line);
}

static void draw_vertical_line(t_Landscape *land_data, t_Image *land_table, int index_x, int index_y)
{
    t_Line2D    line;
    t_Point3D_d start;
    t_Point3D_d end;

    if (!land_data || !land_table)
        return ;
    landscape_set_coord_3D(land_data, &start, index_x, index_y);
    landscape_set_coord_3D(land_data, &end, index_x, index_y + 1); // +1 for vertical
    line.start.x = start.x;
	line.start.y = start.y;
	line.end.x = end.x;
	line.end.y = end.y;
    line.color_start = get_z_level_color(land_data->map[index_y][index_x]);
	line.color_end = get_z_level_color(land_data->map[index_y + 1][index_x]);
    if (land_data->status.is_fiesta)
        draw_line_Bresenham_random_colors(land_table, &line);
    else
        draw_line_Bresenham(land_table, &line);
}

static void draw_corner_lines(t_Landscape *land_data, t_Image *land_table)
{
    int         i;

    if (!land_data || !land_table)
        return ;
    i = 0;
    while (i < land_data->size.y - 1) // vertical side lines
    {
        draw_vertical_line(land_data, land_table, land_data->size.x - 1, i);
        ++i;
    }
    i = 0;
    while (i < land_data->size.x - 1) // horizontal side lines
    {
        draw_horizontal_line(land_data, land_table, i, land_data->size.y - 1);
        ++i;
    }
}

// Just remember before reading the code !
// i is for rows, which means it is for Y axis
// j is for columns, which means it is for X axis
void    draw_landscape_3D(t_Landscape *land_data, t_Image *land_table)
{
    int         i;
    int         j;

    if (!land_data || !land_table)
        return ;
    i = 0;
    while (i < land_data->size.y - 1)
    {
        j = 0;
        while (j < land_data->size.x - 1)
        {
            // printf("%d : %d\n", j, i);
            draw_horizontal_line(land_data, land_table, j, i);
            draw_vertical_line(land_data, land_table, j, i);
            ++j;
        }
        ++i;
    }
    draw_corner_lines(land_data, land_table);
}

void    draw_landscape(t_Landscape *land_data, t_Image *land_table)
{
    if (!land_data || !land_table)
        return ;
    if (land_data->status.is_2D)
    {
        draw_landscape_horizontal_lines(land_data, land_table);
        draw_landscape_vertical_lines(land_data, land_table);
    }
    else if (land_data->status.is_3D)
    {
        draw_landscape_3D(land_data, land_table);
    }
    // new_draw_land(land_data, land_table);
}