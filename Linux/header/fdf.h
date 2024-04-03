#ifndef FdF_H
# define FdF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../mlx_linux/mlx.h"
# include "file_control.h"

# define PRINT_MESSAGE_DESCRIPTOR 1

/*
	utils.c functions

	* usage_arguments - exit and explaining how to use program arguments properly.
	* usage_file_values - exit and explaining what values file must have.
	* usage_file_content - exit and explaining what must file content have.
	* split_size - returns the size of split (str**)
	* exit_with_error - exit with code 1 and also shows given str text.
*/
void	usage_arguments();
void	usage_file_values();
void	usage_file_content();
size_t	split_size(char **split);
void	exit_with_error(char *str);
char	*remove_last_enter(char *line);

/*
	fdf_start.c functions

	* fdf_start - start and preparation for the main logic.
*/
void	fdf_start(char *file_name);

/*
	validation.c functions

	* check_line_spacing - returns true if file_content line is ok, else returns false.
	* check_file_name - returns true if file_name is ok, else returns false.
*/
int	check_line_spacing(char *line);
int	check_file_name(char *file_name);

/*
	libft_funcs.c functions
*/
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_free_split(char **split);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif