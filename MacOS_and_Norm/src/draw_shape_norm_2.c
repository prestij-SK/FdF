/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape_norm_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:59:59 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 14:18:49 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/draw.h"

static void	line_start_end_color_norm(t_Line2D *line, int z_1, int z_2)
{
	if (!line)
		return ;
	line->color_start = get_z_level_color(z_1);
	line->color_end = get_z_level_color(z_2);
}

static void	line_start_end_set_norm(t_Line2D *line, t_Point2D *start,
			t_Point2D *end)
{
	if (!line || !start || !end)
		return ;
	line->start.x = start->x;
	line->start.y = start->y;
	line->end.x = end->x;
	line->end.y = end->y;
}

static void	check_line_draw_norm(t_Landscape *land_data,
			t_Image *land_table, t_Line2D *line)
{
	if (!land_data || !land_table || !line)
		return ;
	if (land_data->status.is_fiesta)
		draw_line_bresenham_random_colors(land_table, line);
	else
		draw_line_bresenham(land_table, line);
}

void	draw_landscape_horizontal_lines_2d(t_Landscape *land_data,
			t_Image *land_table)
{
	t_Line2D	line;
	t_Point2D	start;
	t_Point2D	end;
	int			i;
	int			j;

	i = -1;
	while (++i < land_data->size.y)
	{
		j = -1;
		while (++j < land_data->size.x - 1)
		{
			landscape_set_coord_2d(land_data, &start, j, i);
			landscape_set_coord_2d(land_data, &end, j + 1, i);
			if (land_data->status.is_isometric)
			{
				coord_set_z_value_2d(land_data, &start, land_data->map[i][j]);
				coord_set_z_value_2d(land_data, &end, land_data->map[i][j + 1]);
			}
			line_start_end_set_norm(&line, &start, &end);
			line_start_end_color_norm(&line, land_data->map[i][j],
				land_data->map[i][j + 1]);
			check_line_draw_norm(land_data, land_table, &line);
		}
	}
}

void	draw_landscape_vertical_lines_2d(t_Landscape *land_data,
			t_Image *land_table)
{
	t_Line2D	line;
	t_Point2D	start;
	t_Point2D	end;
	int			i;
	int			j;

	i = -1;
	while (++i < land_data->size.x)
	{
		j = -1;
		while (++j < land_data->size.y - 1)
		{
			landscape_set_coord_2d(land_data, &start, i, j);
			landscape_set_coord_2d(land_data, &end, i, j + 1);
			if (land_data->status.is_isometric)
			{
				coord_set_z_value_2d(land_data, &start, land_data->map[j][i]);
				coord_set_z_value_2d(land_data, &end, land_data->map[j + 1][i]);
			}
			line_start_end_set_norm(&line, &start, &end);
			line_start_end_color_norm(&line, land_data->map[j][i],
				land_data->map[j + 1][i]);
			check_line_draw_norm(land_data, land_table, &line);
		}
	}
}
