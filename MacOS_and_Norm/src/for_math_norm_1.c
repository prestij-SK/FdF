/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_math_norm_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:23:37 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 16:23:58 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/for_math.h"

void	rotate_x_2d(t_Point2D *coord, int angle, t_Point2D center)
{
	double	new_y;
	double	radian;

	if (!coord)
		return ;
	radian = get_radians(angle);
	new_y = center.y + ((coord->y - center.y) * cos(radian));
	coord->y = new_y;
}

void	rotate_y_2d(t_Point2D *coord, int angle, t_Point2D center)
{
	double	new_x;
	double	radian;

	if (!coord)
		return ;
	radian = get_radians(angle);
	new_x = center.x + ((coord->x - center.x) * cos(radian));
	coord->x = new_x;
}

void	rotate_z_2d(t_Point2D *coord, int angle, t_Point2D center)
{
	double	new_x;
	double	new_y;
	double	radian;

	if (!coord)
		return ;
	radian = get_radians(angle);
	new_x = center.x + ((coord->x - center.x) * cos(radian))
		- ((coord->y - center.y) * sin(radian));
	new_y = center.y + ((coord->x - center.x) * sin(radian))
		+ ((coord->y - center.y) * cos(radian));
	coord->x = new_x;
	coord->y = new_y;
}
