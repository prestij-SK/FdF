/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:48:35 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 14:49:52 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/file_control.h"

static void	set_row_and_column(t_FileData *file_data, char *file_name)
{
	char	*line;
	int		descriptor;

	descriptor = open(file_name, O_RDONLY);
	if (descriptor == ERROR_VALUE)
		exit_with_error("File Openning Error!\n");
	file_data->row = 0;
	line = get_next_line(descriptor);
	if (!line)
		return ;
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			file_data->row = 0;
			free(line);
			return ;
		}
		++(file_data->row);
		free(line);
		line = get_next_line(descriptor);
	}
	file_data->column = 0;
	if (close(descriptor) == ERROR_VALUE)
		exit_with_error("File Closing Error!\n");
}

static int	split_and_add_line(t_FileData *file_data, char *line)
{
	char	**new_split;
	char	*temp;
	int		size;

	if (!file_data)
		return (0);
	temp = remove_last_enter(line);
	if (!temp)
		return (0);
	new_split = ft_split(temp, ' ');
	free(temp);
	if (!new_split)
		return (0);
	size = split_size(new_split);
	if (size == 0)
		return (0);
	else if (file_data->column == 0)
		file_data->column = size;
	else if (file_data->column != size)
		return (0);
	file_data->file_content[file_data->row_iter] = new_split;
	++(file_data->row_iter);
	return (1);
}

static int	parse_content(t_FileData *file_data)
{
	char	*line;

	if (!file_data)
		return (0);
	line = get_next_line(file_data->descriptor);
	if (!line)
		return (0);
	while (line)
	{
		if (!check_line_symbols(line))
		{
			get_next_line(ERROR_VALUE);
			free(line);
			return (0);
		}
		if (!split_and_add_line(file_data, line))
		{
			get_next_line(ERROR_VALUE);
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(file_data->descriptor);
	}
	return (1);
}

int	file_data_init(t_FileData *file_data, char *file_name)
{
	if (!file_data || !file_name)
		return (0);
	set_row_and_column(file_data, file_name);
	if (file_data->row == 0)
		return (0);
	set_descriptor(file_data, file_name);
	if (file_data->descriptor == ERROR_VALUE)
		exit_with_error("File Openning Error!\n");
	set_content_alloc(file_data);
	if (!file_data->file_content)
		return (0);
	if (!parse_content(file_data))
	{
		delete_file_data(file_data);
		return (0);
	}
	return (1);
}
