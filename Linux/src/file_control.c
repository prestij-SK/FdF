#include "../header/file_control.h"

void	delete_file_data(t_FileData *file_data)
{
	size_t	i;

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
	file_data->row = 0;
	file_data->column = 0;
	if (close(file_data->descriptor) == ERROR_CODE)
		exit_with_error("File Closing Error!\n");
	file_data->descriptor = -1;
}

static void	set_row_and_column(t_FileData *file_data, char *file_name)
{
	char	*line;
	int		descriptor;

	if (!file_data)
		return ;
	descriptor = open(file_name, O_RDONLY);
	if (descriptor == ERROR_CODE)
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
	if (close(descriptor) == ERROR_CODE)
		exit_with_error("File Closing Error!\n");
}

static void	set_descriptor(t_FileData *file_data, char *file_name)
{
	if (!file_data)
		return ;
	file_data->descriptor = open(file_name, O_RDONLY);
}

static void	set_content_alloc(t_FileData *file_data)
{
	if (!file_data)
		return ;
	file_data->file_content = (char ***)malloc(sizeof(char **) * file_data->row);
	file_data->row_iter = 0;
}

static int	split_and_add_line(t_FileData *file_data, char *line)
{
	char	**new_split;
	char	*temp;
	size_t	size;

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
		if (!check_line_spacing(line))
		{
			get_next_line(ERROR_CODE);
			free(line);
			return (0);
		}
		if (!split_and_add_line(file_data, line))
		{
			get_next_line(ERROR_CODE);
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
	if (file_data->descriptor == ERROR_CODE)
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