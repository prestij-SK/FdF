/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:47:50 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/04 15:54:49 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/color.h"

static int	low_level_color(int val)
{
	if (val >= RANGE_LEVEL_LOW_1)
		return (COLOR_LEVEL_LOW_1);
	else if (val >= RANGE_LEVEL_LOW_2)
		return (COLOR_LEVEL_LOW_2);
	else if (val >= RANGE_LEVEL_LOW_3)
		return (COLOR_LEVEL_LOW_3);
	else if (val >= RANGE_LEVEL_LOW_4)
		return (COLOR_LEVEL_LOW_4);
	else if (val >= RANGE_LEVEL_LOW_5)
		return (COLOR_LEVEL_LOW_5);
	else if (val >= RANGE_LEVEL_LOW_6)
		return (COLOR_LEVEL_LOW_6);
	return (COLOR_LEVEL_LOW_7);
}

static int	high_level_color(int val)
{
	if (val <= RANGE_LEVEL_HIGH_1)
		return (COLOR_LEVEL_HIGH_1);
	else if (val <= RANGE_LEVEL_HIGH_2)
		return (COLOR_LEVEL_HIGH_2);
	else if (val <= RANGE_LEVEL_HIGH_3)
		return (COLOR_LEVEL_HIGH_3);
	else if (val <= RANGE_LEVEL_HIGH_4)
		return (COLOR_LEVEL_HIGH_4);
	else if (val <= RANGE_LEVEL_HIGH_5)
		return (COLOR_LEVEL_HIGH_5);
	else if (val <= RANGE_LEVEL_HIGH_6)
		return (COLOR_LEVEL_HIGH_6);
	else if (val <= RANGE_LEVEL_HIGH_7)
		return (COLOR_LEVEL_HIGH_7);
	else if (val <= RANGE_LEVEL_HIGH_8)
		return (COLOR_LEVEL_HIGH_8);
	return (COLOR_LEVEL_HIGH_9);
}

int	get_z_level_color(int z_val)
{
	if (z_val == RANGE_LEVEL_0)
		return (COLOR_LEVEL_0);
	if (z_val < RANGE_LEVEL_0)
		return (low_level_color(z_val));
	return (high_level_color(z_val));
}
