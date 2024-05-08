#include "../header/utils.h"

void	exit_with_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	usage_arguments()
{
	print_message("Wrong Arguments!\n");
	print_message("Usage: ./fdf file_name.fdf.\n");
	exit(EXIT_FAILURE);
}

void	usage_file_content()
{
	print_message("Wrong File Content!\n");
	print_message("File must contain rectangular matrix of integers, without any additional spaces.\n");
	exit(EXIT_FAILURE);
}

void	usage_file_values()
{
	print_message("Wrong File Values!\n");
	print_message("File must contain only integers that fits to size of 'int'.\n");
}

void	fdf_init_error()
{
	print_message("FdF initiating Error!\n");
	print_message("Failed to initiate FdF program preparations.\n");
	exit(EXIT_FAILURE);
}

void	render_error()
{
	print_message("Rendering Error!\n");
	print_message("Issue while trying to run rendering the landscape\n");
	exit(EXIT_FAILURE);
}

void	program_end()
{
	print_message("Program Ended with no issues!\n");
	exit(EXIT_SUCCESS);
}