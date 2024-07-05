/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:30:40 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/05 19:51:01 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_exit(t_errors code, t_cub_data *cub_data)
{
	if (code == BAD_ARGUMENTS)
	{
		bad_arguments_msg(cub_data);
	}
	else if (code == BAD_FILE_EXTENTION)
	{
		bad_file_extention_msg();
	}
	else if (code == OTHER)
	{
		other_msg();
	}
	else if (code == BAD_SETTING_FORMAT)
	{
		bad_setting_format_error();
	}
	else if (code == DUPLICATED_SETTING)
	{
		duplicated_setting_error();
	}
	else if (code == E_BAD_FILE_PATH)
	{
		east_bad_file_path_error();
	}
	else if (code == N_BAD_FILE_PATH)
	{
		north_bad_file_path_error();
	}
	else if (code == S_BAD_FILE_PATH)
	{
		south_bad_file_path_error();
	}
	else if (code == W_BAD_FILE_PATH)
	{
		west_bad_file_path_error();
	}
	else if (code == BAD_COLOR_CODE_FORMAT)
	{
		bad_color_code_format_error();
	}
	else if (code == BAD_IDENTIFIER)
	{
		bad_identifier_error();
	}
	else if (code == MISSING_SETTING)
	{
		missing_setting_error();
	}
	free_everything(cub_data);
	exit(EXIT_FAILURE);
}
