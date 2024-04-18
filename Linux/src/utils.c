#include "../header/utils.h"

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

void	swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}