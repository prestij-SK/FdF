#include "../header/utils.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

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

long long	ft_atoll(const char *str)
{
	size_t		i;
	long long	nbr;
	int			isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] && ft_is_space(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg = 1;
		++i;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		++i;
	}
	if (isneg)
		return (-nbr);
	return (nbr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((i < n - 1) && s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}