#include "../header/fdf.h"

int	check_file_name(char *file_name)
{
	int	len;

	if (!file_name)
		return (0);
	len = ft_strlen(file_name);
	if (len < 5)
		return (0);
	if ((file_name[len - 1] != 'f') ||
		(file_name[len - 2] != 'd') ||
		(file_name[len - 3] != 'f') ||
		(file_name[len - 4] != '.'))
	{
		return (0);
	}
	return (1);
}

int	check_line_spacing(char *line)
{
	int	len;
	int	i;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (line[0] == ' ' || line[len - 1] == ' ')
		return (0);
	i = 0;
	while (i < len)
	{
		while (line[i] == ' ')
			++i;
		if ((line[i] == '\n') && (i + 1 == len))
			break ;
		if ((line[i] == '-') && (i + 1 != len))
			++i;
		if (!ft_isdigit(line[i]))
			return (0);
		++i;
	}
	return (1);
}