/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:39:35 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:40:50 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

int	check_file_name(char *file_name)
{
	int	len;

	if (!file_name)
		return (0);
	len = ft_strlen(file_name);
	if (len < 5)
		return (0);
	if ((file_name[len - 1] != 'f')
		|| (file_name[len - 2] != 'd')
		|| (file_name[len - 3] != 'f')
		|| (file_name[len - 4] != '.'))
	{
		return (0);
	}
	return (1);
}

int	check_line_symbols(char *line)
{
	int	len;
	int	i;

	if (!line)
		return (0);
	len = ft_strlen(line);
	i = 0;
	while (i < len)
	{
		while (line[i] == ' ')
			++i;
		if ((line[i] == '\n') && (i + 1 == len))
			break ;
		if ((line[i] == '-') && (i + 1 != len))
			++i;
		if (!ft_isdigit(line[i]) && line[i] != '\0')
			return (0);
		++i;
	}
	return (1);
}

int	check_str_size(char *str)
{
	size_t	str_len;

	if (!str)
		return (0);
	str_len = ft_strlen(str);
	if (str_len > INT_DIGITS)
	{
		if (str_len != INT_DIGITS_WITH_SIGN || (*str != '-' && *str != '+'))
		{
			return (0);
		}
	}
	return (1);
}

int	check_value_size(long long num)
{
	if (num < MIN_INT || num > MAX_INT)
	{
		return (0);
	}
	return (1);
}
