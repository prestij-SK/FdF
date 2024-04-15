#include "../header/landscape_init.h"
#include "../header/fdf.h"

void	exit_with_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	usage_arguments()
{
	print_message("Wrong Arguments!\n");
	print_message("Usage: ./fdf file_name.fdf\n");
	exit(EXIT_FAILURE);
}

void	usage_file_content()
{
	print_message("Wrong File Content!\n");
	print_message("File must contain rectangular matrix, without any additional spaces\n");
	exit(EXIT_FAILURE);
}

void	usage_file_values()
{
	print_message("Wrong File Values!\n");
	print_message("File must contain only integers that fits to size of 'int'\n");
	exit(EXIT_FAILURE);
}