/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_control_norm_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:50:03 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 14:50:26 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/file_control.h"

void	delete_file_data(t_FileData *file_data)
{
	int	i;

	if (!file_data)
		return ;
	i = 0;
	if (file_data->file_content)
	{
		while (i < file_data->row_iter)
		{
			ft_free_split(file_data->file_content[i]);
			file_data->file_content[i] = NULL;
			++i;
		}
	}
	free(file_data->file_content);
	file_data->file_content = NULL;
	file_data->row = ERROR_VALUE;
	file_data->column = ERROR_VALUE;
	if (close(file_data->descriptor) == ERROR_VALUE)
		exit_with_error("File Closing Error!\n");
	file_data->descriptor = ERROR_VALUE;
}

void	set_descriptor(t_FileData *file_data, char *file_name)
{
	if (!file_data)
		return ;
	file_data->descriptor = open(file_name, O_RDONLY);
}

int	set_content_alloc(t_FileData *file_data)
{
	if (!file_data)
		return (0);
	file_data->file_content = (char ***)malloc(sizeof(char **) * (file_data->row + 1));
	if (!file_data->file_content)
		return (0);
	file_data->row_iter = 0;
	file_data->file_content[file_data->row] = NULL;
	return (1);
}
