/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_control.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:36:52 by skedikia          #+#    #+#             */
/*   Updated: 2024/05/04 15:37:24 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_CONTROL_H
# define FILE_CONTROL_H

# include "utils.h"
# include "get_next_line.h"

typedef struct FileData
{
	char	***file_content;
	int		row;
	int		column;
	int		row_iter;
	int		descriptor;
}	t_FileData;

/*
	file_control.c functions

	* delete_file_data - deletes all feilds of 'file_data'.
	* file_data_init - initializing all 'file_data' fields,
	* 				   returns true on success, else false.
*/
void	delete_file_data(t_FileData *file_data);
int		file_data_init(t_FileData *file_data, char *file_name);
void	set_descriptor(t_FileData *file_data, char *file_name);
void	set_content_alloc(t_FileData *file_data);

#endif
