#ifndef LANDSCAPE_INIT_H
# define LANDSCAPE_INIT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "file_control.h"

# define PRINT_MESSAGE_DESCRIPTOR 1
# define INT_DIGITS 10
# define INT_DIGITS_WITH_SIGN 11
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct LandescapeCoordinates
{
	int		**map;
	size_t	x_size;
	size_t	y_size;
} 	t_LandscapeData;

/*
	utils.c functions

	* split_size - returns the size of split (str**).
	* remove_last_enter - returns new string, but without last character if it was '\n'.
*/
size_t	split_size(char **split);
char	*remove_last_enter(char *line);

/*
	error_handling.c functions

	* void	render_error - exit with message of issue while trying to render the landscape.
	* usage_arguments - exit and explaining how to use program arguments properly.
	* usage_file_values - exit and explaining what values file must have.
	* usage_file_content - exit and explaining what must file content have.
	* exit_with_error - exit with code 1 and also shows given str text.
*/
void	render_error();
void	usage_arguments();
void	usage_file_values();
void	usage_file_content();
void	exit_with_error(char *str);

/*
	validation.c functions

	* check_str_size - returns true if 'str' length is ok, else returns false. 
	* check_line_spacing - returns true if file_content line is ok, else returns false.
	* check_value_size - returns true if 'num' value fits in size of INT, else returns false.
	* check_file_name - returns true if file_name is ok, else returns false.
*/
int	check_str_size(char *str);
int	check_line_symbols(char *line);
int check_value_size(long long num);
int	check_file_name(char *file_name);

/*
	strings_to_ints.c functions

	* delete_land_data - deletes all feilds of 'land_data'.
	* strings_to_ints - makes matrix of ints from parsed file content, returns true on sucess, else false.
*/
void	delete_land_data(t_LandscapeData *land_data);
int		land_data_init(t_LandscapeData *land_data, t_FileData *file_data);

/*
	libft_funcs.c functions
*/
int			ft_isdigit(int c);
int			ft_is_space(char c);
size_t		ft_strlen(const char *s);
long long	ft_atoll(const char *str);
void		ft_free_split(char **split);
char		**ft_split(char const *s, char c);

#endif