/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_utils_norm_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:42:39 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:43:24 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/landscape.h"

void	coord_start(t_Landscape *land_data, t_Point2D *coord)
{
	if (!land_data || !coord)
		return ;
	coord->x = land_data->setup.start.x;
	coord->y = land_data->setup.start.y;
}

void	coord_gap(t_Landscape *land_data, t_Point2D *coord,
		int index_x, int index_y)
{
	if (!land_data || !coord)
		return ;
	coord->x += land_data->setup.gap.x * index_x;
	coord->y += land_data->setup.gap.y * index_y;
}

void	coord_zoom(t_Landscape *land_data, t_Point2D *coord)
{
	if (!land_data || !coord)
		return ;
	coord->x *= land_data->setup.zoom;
	coord->y *= land_data->setup.zoom;
}

void	coord_move(t_Landscape *land_data, t_Point2D *coord)
{
	if (!land_data || !coord)
		return ;
	coord->x += land_data->setup.move.x;
	coord->y += land_data->setup.move.y;
}

void	coord_center(t_Landscape *land_data, t_Point2D *coord)
{
	if (!land_data || !coord)
		return ;
	coord->x = land_data->setup.center.x + ((land_data->size.x / 2)
			* land_data->setup.zoom);
	coord->y = land_data->setup.center.y + ((land_data->size.y / 2)
			* land_data->setup.zoom);
}
