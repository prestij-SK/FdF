#include "../header/fdf.h"

void	print_message(char *str)
{
	write(PRINT_MESSAGE_DESCRIPTOR, str, ft_strlen(str));
}

size_t	split_size(char **split)
{
	size_t	i;

	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		++i;
	}
	return (i);
}

char	*remove_last_enter(char *line)
{
	char	*new_line;
	size_t	len;
	size_t	i;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		--len;
	new_line = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_line[i] = line[i];
		++i;
	}
	new_line[i] = '\0';
	return (new_line);
}

t_Image	*image_init(void *mlx, int x_size, int y_size)
{
	t_Image	*new_img;

	if (!mlx)
		return (NULL);
	new_img = (t_Image *)malloc(sizeof(t_Image));
	if (!new_img)
		return (NULL);
	new_img->img = mlx_new_image(mlx, x_size, y_size);
	if (!new_img->img)
	{
		free(new_img);
		return (NULL);
	}
	new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bits_per_pixel,
										&new_img->line_length, &new_img->endian);
	if (!new_img->addr)
	{
		free(new_img);
		return (NULL);
	}
	return (new_img);
}