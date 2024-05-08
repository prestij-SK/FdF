/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:56:17 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 16:23:28 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/for_math.h"

double	get_radians(int angle)
{
	return (angle * M_PI / 180.0);
}

void	rotate_x_3d(t_Point3D_d *coord, int angle, t_Point2D center, int z_val)
{
	t_Point3D_d	temp;
	double		radian;
	double		rotate[3][3];

	radian = get_radians(angle);
	rotate[0][0] = 1;
	rotate[0][1] = 0;
	rotate[0][2] = 0;
	rotate[1][0] = 0;
	rotate[1][1] = cos(radian);
	rotate[1][2] = -sin(radian);
	rotate[2][0] = 0;
	rotate[2][1] = sin(radian);
	rotate[2][2] = cos(radian);
	temp.x = center.x + (rotate[0][0] * (coord->x - center.x))
		+ (rotate[0][1] * (coord->y - center.y)) + rotate[0][2] * z_val;
	temp.y = center.y + (rotate[1][0] * (coord->x - center.x))
		+ (rotate[1][1] * (coord->y - center.y)) + rotate[1][2] * z_val;
	temp.z = rotate[1][0] * coord->x + rotate[1][1] * coord->y
		+ rotate[1][2] * z_val;
	coord->x = temp.x;
	coord->y = temp.y;
	coord->z = temp.z;
}

void	rotate_y_3d(t_Point3D_d *coord, int angle, t_Point2D center, int z_val)
{
	t_Point3D_d	temp;
	double		radian;
	double		rotate[3][3];

	radian = get_radians(angle);
	rotate[0][0] = cos(radian);
	rotate[0][1] = 0;
	rotate[0][2] = sin(radian);
	rotate[1][0] = 0;
	rotate[1][1] = 1;
	rotate[1][2] = 0;
	rotate[2][0] = -sin(radian);
	rotate[2][1] = 0;
	rotate[2][2] = cos(radian);
	temp.x = center.x + (rotate[0][0] * (coord->x - center.x))
		+ (rotate[0][1] * (coord->y - center.y)) + rotate[0][2] * z_val;
	temp.y = center.y + (rotate[1][0] * (coord->x - center.x))
		+ (rotate[1][1] * (coord->y - center.y)) + rotate[1][2] * z_val;
	temp.z = rotate[1][0] * coord->x + rotate[1][1] * coord->y
		+ rotate[1][2] * z_val;
	coord->x = temp.x;
	coord->y = temp.y;
	coord->z = temp.z;
}

void	rotate_z_3d(t_Point3D_d *coord, int angle, t_Point2D center, int z_val)
{
	t_Point3D_d	temp;
	double		radian;
	double		rotate[3][3];

	radian = get_radians(angle);
	rotate[0][0] = cos(radian);
	rotate[0][1] = -sin(radian);
	rotate[0][2] = 0;
	rotate[1][0] = sin(radian);
	rotate[1][1] = cos(radian);
	rotate[1][2] = 0;
	rotate[2][0] = 0;
	rotate[2][1] = 0;
	rotate[2][2] = 1;
	temp.x = center.x + (rotate[0][0] * (coord->x - center.x))
		+ (rotate[0][1] * (coord->y - center.y)) + rotate[0][2] * z_val;
	temp.y = center.y + (rotate[1][0] * (coord->x - center.x))
		+ (rotate[1][1] * (coord->y - center.y)) + rotate[1][2] * z_val;
	temp.z = rotate[1][0] * coord->x + rotate[1][1] * coord->y
		+ rotate[1][2] * z_val;
	coord->x = temp.x;
	coord->y = temp.y;
	coord->z = temp.z;
}

void	orthographic_projection(t_Point3D_d *coord, int z_val)
{
	double	pr[2][3];
	double	new_x;
	double	new_y;
	double	new_z;

	pr[0][0] = 1;
	pr[0][1] = 0;
	pr[0][2] = 0;
	pr[1][0] = 0;
	pr[1][1] = 1;
	pr[1][2] = 0;
	new_x = pr[0][0] * coord->x + pr[0][1] * coord->y
		+ pr[0][2] * z_val;
	new_y = pr[1][0] * coord->x + pr[1][1] * coord->y
		+ pr[1][2] * z_val;
	new_z = pr[1][0] * coord->x + pr[1][1] * coord->y
		+ pr[1][2] * z_val;
	coord->x = new_x;
	coord->y = new_y;
	coord->z = new_z;
}
