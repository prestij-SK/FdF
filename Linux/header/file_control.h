#ifndef FILE_CONTROL_H
# define FILE_CONTROL_H

# include "fdf.h"
# include "get_next_line.h"

# define ERROR_CODE -1

typedef struct FileData
{
	char	***file_content;
	size_t	row;
	size_t	column;
	size_t	row_iter;
	int		descriptor;
} 	t_FileData;

/*
	file_control.c functions

	* file_data_init - initializing all 'file_data' fields
*/
void	delete_file_data(t_FileData *file_data);
int		file_data_init(t_FileData *file_data, char *file_name);

#endif