/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:30:40 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/12 16:39:18 by asyvash          ###   ########.fr       */
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
	else if (code == MAP_MISSING)
	{
		missing_map_error();
	}
	else if (code == MAP_UNCLOSED)
	{
		unclosed_map_error();
	}
	else if (code == MLX_ERROR)
	{
		mlx_error();
	}
	else if (code == MAP_WRONG_CHARACTER)
	{
		map_wrong_character_error();
	}
	else if (code == MAP_DUPLICATED_PLAYER_SPAWN_POS)
	{
		map_duplicated_player_spawn_pos();
	}
	else if (code == MAP_MISSING_PLAYER_SPAWN_POS)
	{
		map_missing_player_spawn_pos();
	}
	free_everything(cub_data);
	if (code == SUCCESS)
		exit(SUCCESS);
	exit(EXIT_FAILURE);
}
