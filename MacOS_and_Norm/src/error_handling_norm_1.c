/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_norm_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:26:16 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 14:27:07 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

void	usage_file_values(void)
{
	print_message("Wrong File Values!\n");
	print_message("File must contain only integers");
	print_message(" that fits to size of 'int'.\n");
}

void	fdf_init_error(void)
{
	print_message("FdF initiating Error!\n");
	print_message("Failed to initiate FdF program preparations.\n");
	exit(EXIT_FAILURE);
}

void	render_error(void)
{
	print_message("Rendering Error!\n");
	print_message("Issue while trying to run rendering the landscape\n");
	exit(EXIT_FAILURE);
}

void	program_end(void)
{
	print_message("Program Ended with no issues!\n");
	system("leaks fdf");
	exit(EXIT_SUCCESS);
}
