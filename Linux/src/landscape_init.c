#include "../header/landscape_init.h"

void	delete_land_data(t_LandscapeData *land_data)
{
	size_t	i;

	if (!land_data)
		return ;
	i = 0;
	while (i < land_data->x_size)
	{
		free(land_data->map[i]);
		land_data->map[i] = NULL;
		++i;
	}
	free(land_data->map);
	land_data->map = NULL;
	land_data->x_size = 0;
	land_data->y_size = 0;
}

static int	set_land_data(t_LandscapeData *land_data, t_FileData *file_data)
{
	if (!land_data || !file_data)
		return (0);
	land_data->map = (int **)malloc(sizeof(int *) * (file_data->row));
	if (!land_data->map)
		return (0);
	land_data->x_size = 0;
	while (land_data->x_size < file_data->row)
	{
		land_data->map[land_data->x_size] = (int *)malloc(sizeof(int) * file_data->column);
		if (!land_data->map[land_data->x_size])
		{
			delete_land_data(land_data);
			return (0);
		}
		++(land_data->x_size);
	}
	land_data->y_size = file_data->column;
	return (1);
}

static int	strings_to_ints(t_LandscapeData *land_data, t_FileData *file_data)
{
	long long	num;
	size_t		i;
	size_t		j;

	if (!land_data || !file_data)
		return (0);
	i = 0;
	while (i < file_data->row)
	{
		j = 0;
		while (j < file_data->column)
		{
			if (!check_str_size(file_data->file_content[i][j]))
				return (0);
			num = ft_atoll(file_data->file_content[i][j]);
			if (!check_value_size(num))
				return (0);
			land_data->map[i][j] = (int)num;
			++j;
		}
		++i;
	}
	return (1);
}

int	land_data_init(t_LandscapeData *land_data, t_FileData *file_data)
{
	if (!land_data || !file_data)
		return (0);
	if (!set_land_data(land_data, file_data))
		return (0);
	if (!strings_to_ints(land_data, file_data))
	{
		delete_land_data(land_data);
		return (0);
	}
	return (1);
}