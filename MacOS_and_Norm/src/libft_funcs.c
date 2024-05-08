/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:15:30 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 17:15:33 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

static size_t	word_counter(const char *str, char del)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*str != '\0')
	{
		if (*str == del)
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*get_word(const char *str, char del, size_t *index)
{
	char	*word;
	size_t	i;

	while (str[*index] == del)
		++(*index);
	i = 0;
	while (str[i + *index] && str[i + *index] != del)
		++i;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i + *index] && str[i + *index] != del)
	{
		word[i] = str[i + *index];
		++i;
	}
	*index += i;
	word[i] = '\0';
	return (word);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		++i;
	}
	free(split[i]);
	split[i] = NULL;
	free(split);
	split = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	size_t	word_count;
	size_t	word_i;
	size_t	i;

	if (!s)
		return (NULL);
	word_count = word_counter(s, c);
	mat = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!mat)
		return (NULL);
	i = 0;
	word_i = 0;
	while (word_i < word_count)
	{
		mat[word_i] = get_word(s, c, &i);
		if (!mat[word_i])
		{
			ft_free_split(mat);
			return (NULL);
		}
		++word_i;
	}
	mat[word_i] = NULL;
	return (mat);
}
