#include "../header/landscape.h"

void	delete_landscape_data(t_Landscape *land_data)
{
	int	i;

	if (!land_data)
		return ;
	i = 0;
	while (i < land_data->size.y)
	{
		free(land_data->map[i]);
		land_data->map[i] = NULL;
		++i;
	}
	free(land_data->map);
	land_data->map = NULL;
	land_data->size.x = ERROR_VALUE;
	land_data->size.y = ERROR_VALUE;
}

int	landscape_init(t_Landscape *land_data, t_FileData *file_data)
{
	int	i;

	if (!land_data || !file_data)
		return (0);
	land_data->map = (t_Point3D **)malloc(sizeof(t_Point3D *) * file_data->row);
	if (!land_data->map)
		return (0);
	i = 0;
	while (i < file_data->row)
	{
		land_data->map[i] = (t_Point3D *)malloc(sizeof(t_Point3D) * file_data->column);
		if (!land_data->map[i])
		{
			while (i >= 0)
			{
				free(land_data->map[i]);
				--i;
			}
			free(land_data->map);
			land_data->map = NULL;
			return (0);
		}
		++i;
	}
	return (1);
}

int	assign_file_to_landscape(t_Landscape *land_data, t_FileData *file_data)
{
	long long	num;
	int			i;
	int			j;

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
			land_data->map[i][j].x = 0;
			land_data->map[i][j].y = 0;
			land_data->map[i][j].z = (int)num;
			++j;
		}
		++i;
	}
	return (1);
}

void	set_landscape_default(t_Landscape *land_data)
{
	int	x_new;
	int	y_new;
	int	i;
	int	j;

	if (!land_data)
		return ;
	x_new = COORD_X_START;
	y_new = COORD_Y_START;
	i = 0;
	while (i < land_data->size.y)
	{
		j = 0;
		while (j < land_data->size.x)
		{
			land_data->map[i][j].x = x_new;
			land_data->map[i][j].y = y_new;
			x_new += COORD_X_GAP;
			++j;
		}
		x_new = COORD_X_START;
		y_new += COORD_Y_GAP;
		++i;
	}
	// rotate_landscape(land_data, COORD_ANGLE);
}

t_Landscape	*create_landscape_data(t_FileData *file_data)
{
	t_Landscape	*new_land_data;

	if (!file_data)
		return (NULL);
	new_land_data = (t_Landscape *)malloc(sizeof(t_Landscape));
	if (!new_land_data)
		return (NULL);
	if (!landscape_init(new_land_data, file_data))
		return (NULL);
	if (!assign_file_to_landscape(new_land_data, file_data))
	{
		delete_landscape_data(new_land_data);
		return (NULL);
	}
	new_land_data->size.x = file_data->column;
	new_land_data->size.y = file_data->row;
	set_landscape_default(new_land_data);
	return (new_land_data);
}