/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:24:17 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/08 14:27:35 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

void	exit_with_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	usage_arguments(void)
{
	print_message("Wrong Arguments!\n");
	print_message("Usage: ./fdf file_name.fdf.\n");
	exit(EXIT_FAILURE);
}

void	usage_file_content(void)
{
	print_message("Wrong File Content!\n");
	print_message("File must contain rectangular matrix of integers,");
	print_message(" without any additional spaces.\n");
	exit(EXIT_FAILURE);
}
