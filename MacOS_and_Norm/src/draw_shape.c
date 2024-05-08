/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:30:17 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 13:55:41 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/draw.h"

static void	draw_horizontal_line_3d(t_Landscape *land_data, t_Image *land_table,
				int index_x, int index_y)
{
	t_Line2D	line;
	t_Point3D_d	start;
	t_Point3D_d	end;

	if (!land_data || !land_table)
		return ;
	landscape_set_coord_3d(land_data, &start, index_x, index_y);
	landscape_set_coord_3d(land_data, &end, index_x + 1, index_y);
	line.start.x = start.x;
	line.start.y = start.y;
	line.end.x = end.x;
	line.end.y = end.y;
	line.color_start = get_z_level_color(land_data->map[index_y][index_x]);
	line.color_end = get_z_level_color(land_data->map[index_y][index_x + 1]);
	if (land_data->status.is_fiesta)
		draw_line_bresenham_random_colors(land_table, &line);
	else
		draw_line_bresenham(land_table, &line);
}

static void	draw_vertical_line_3d(t_Landscape *land_data, t_Image *land_table,
				int index_x, int index_y)
{
	t_Line2D	line;
	t_Point3D_d	start;
	t_Point3D_d	end;

	if (!land_data || !land_table)
		return ;
	landscape_set_coord_3d(land_data, &start, index_x, index_y);
	landscape_set_coord_3d(land_data, &end, index_x, index_y + 1);
	line.start.x = start.x;
	line.start.y = start.y;
	line.end.x = end.x;
	line.end.y = end.y;
	line.color_start = get_z_level_color(land_data->map[index_y][index_x]);
	line.color_end = get_z_level_color(land_data->map[index_y + 1][index_x]);
	if (land_data->status.is_fiesta)
		draw_line_bresenham_random_colors(land_table, &line);
	else
		draw_line_bresenham(land_table, &line);
}

static void	draw_corner_lines_3d(t_Landscape *land_data, t_Image *land_table)
{
	int	i;

	if (!land_data || !land_table)
		return ;
	i = 0;
	while (i < land_data->size.y - 1)
	{
		draw_vertical_line_3d(land_data, land_table, land_data->size.x - 1, i);
		++i;
	}
	i = 0;
	while (i < land_data->size.x - 1)
	{
		draw_horizontal_line_3d(land_data, land_table, i,
			land_data->size.y - 1);
		++i;
	}
}

// Just remember before reading the code !
// i is for rows, which means it is for Y axis
// j is for columns, which means it is for X axis
void	draw_landscape_3d(t_Landscape *land_data, t_Image *land_table)
{
	int	i;
	int	j;

	if (!land_data || !land_table)
		return ;
	i = 0;
	while (i < land_data->size.y - 1)
	{
		j = 0;
		while (j < land_data->size.x - 1)
		{
			draw_horizontal_line_3d(land_data, land_table, j, i);
			draw_vertical_line_3d(land_data, land_table, j, i);
			++j;
		}
		++i;
	}
	draw_corner_lines_3d(land_data, land_table);
}

void	draw_landscape(t_Landscape *land_data, t_Image *land_table)
{
	if (!land_data || !land_table)
		return ;
	if (land_data->status.is_2d)
	{
		draw_landscape_horizontal_lines_2d(land_data, land_table);
		draw_landscape_vertical_lines_2d(land_data, land_table);
	}
	else if (land_data->status.is_3d)
	{
		draw_landscape_3d(land_data, land_table);
	}
}
