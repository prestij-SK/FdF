#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define PRINT_MESSAGE_DESCRIPTOR 1
# define ERROR_VALUE -1
# define INT_DIGITS 10
# define INT_DIGITS_WITH_SIGN 11
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct Point2D_int
{
	int	x;
	int	y;
}	t_Point2D;

typedef struct Point3D_int
{
	int	x;
	int	y;
	int	z;
}	t_Point3D;

typedef struct Point2D_double
{
	double	x;
	double	y;
}	t_Point2D_d;

typedef struct Point3D_double
{
	double	x;
	double	y;
	double	z;
}	t_Point3D_d;

typedef struct Line2D_int
{
	t_Point2D	start;
	t_Point2D	end;
	int			color_start;
	int			color_end;
}	t_Line2D;

/*
	utils.c functions
	
	* print_message - prints the given 'str'.
	* swap_int - simple swap for ints.
	* split_size - returns the size of split (str**).
	* remove_last_enter - returns new string, but without last character if it was '\n'.
*/
void	print_message(char *str);
void	swap_int(int *a, int *b);
size_t	split_size(char **split);
char	*remove_last_enter(char *line);

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
	error_handling.c functions

	* program_end - exit program with success message.
	* render_error - exit with message of issue while trying to render the landscape. 
	* usage_arguments - exit and explaining how to use program arguments properly.
	* usage_file_values - exit and explaining what values file must have.
	* usage_file_content - exit and explaining what must file content have.
	* exit_with_error - exit with code 1 and also shows given str text.
*/
void	program_end();
void	render_error();
void	fdf_init_error();
void	usage_arguments();
void	usage_file_values();
void	usage_file_content();
void	exit_with_error(char *str);

/*
	libft_funcs.c functions
*/
int			ft_isdigit(int c);
int			ft_is_space(char c);
size_t		ft_strlen(const char *s);
long long	ft_atoll(const char *str);
void		ft_free_split(char **split);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif