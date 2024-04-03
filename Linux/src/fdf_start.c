#include "../header/fdf.h"

// DELETE
static void	display_file_data(t_FileData *file_data)
{
	printf("row: %ld\n", file_data->row);
	printf("column: %ld\n", file_data->column);
	size_t	i = 0;
	size_t	j = 0;
	while (i < file_data->row)
	{
		j = 0;
		while (j < file_data->column)
		{
			printf("%s ", file_data->file_content[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
}

void	fdf_start(char *file_name)
{
	t_FileData	file_data;

	if (!file_name)
		usage_arguments();
	if (!check_file_name(file_name))
		usage_arguments();
	if(!file_data_init(&file_data, file_name))
		usage_file_content();
	// string to ints
	display_file_data(&file_data);
	delete_file_data(&file_data);
	// drawing
	// free nums
}