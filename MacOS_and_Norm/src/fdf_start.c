/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:31:48 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 14:33:12 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	delete_fdf_data(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	delete_landscape_data(fdf_data->land_data);
	free(fdf_data->land_data);
	fdf_mlx_delete(fdf_data);
	fdf_null_fields(fdf_data);
}

int	fdf_data_init(t_FdF *fdf_data, t_FileData *file_data)
{
	if (!fdf_data || !file_data)
		return (0);
	fdf_data->land_data = create_landscape_data(file_data);
	landscape_set_default(fdf_data->land_data, LAND_X_SIZE, LAND_Y_SIZE);
	if (!fdf_data->land_data)
		return (0);
	fdf_data->mlx = mlx_init();
	if (!fdf_data->mlx)
		return (0);
	fdf_data->mlx_window = mlx_new_window(fdf_data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "dasist ABUBA");
	if (!fdf_data->mlx_window)
		return (0);
	fdf_data->land_table = create_land_image(fdf_data->mlx);
	if (!fdf_data->land_table)
		return (0);
	fdf_data->option_table = create_option_image(fdf_data->mlx);
	if (!fdf_data->option_table)
		return (0);
	fdf_data->buttons = create_buttons_image(fdf_data->mlx);
	if (!fdf_data->buttons)
		return (0);
	fdf_data->active_button = BUTTONS_NOT_ACTIVE;
	return (1);
}

static void	input_update_render(t_FdF *fdf_data)
{
	if (!fdf_data)
		return ;
	mlx_hook(fdf_data->mlx_window, EVENT_MOUSEMOVE, 1L << 6,
		input_mouse_move, fdf_data);
	mlx_mouse_hook(fdf_data->mlx_window, input_mouse_button, fdf_data);
	mlx_hook(fdf_data->mlx_window, EVENT_KEYDOWN, 1L << 0,
		input_key_press, fdf_data);
	mlx_hook(fdf_data->mlx_window, EVENT_DESTROY, 0,
		input_close_window, fdf_data);
	mlx_loop_hook(fdf_data->mlx, update_frame, fdf_data);
}

int	start_program(t_FdF *fdf_data)
{
	if (!fdf_data)
		return (0);
	render_all(fdf_data);
	input_update_render(fdf_data);
	mlx_loop(fdf_data->mlx);
	return (1);
}

void	fdf_start(char *file_name)
{
	t_FdF		fdf_data;
	t_FileData	file_data;

	if (!file_name)
		usage_arguments();
	if (!check_file_name(file_name))
		usage_arguments();
	if (!file_data_init(&file_data, file_name))
		usage_file_content();
	fdf_null_fields(&fdf_data);
	if (!fdf_data_init(&fdf_data, &file_data))
	{
		delete_file_data(&file_data);
		delete_fdf_data(&fdf_data);
		fdf_init_error();
	}
	delete_file_data(&file_data);
	if (!start_program(&fdf_data))
	{
		delete_fdf_data(&fdf_data);
		render_error();
	}
	delete_fdf_data(&fdf_data);
}
