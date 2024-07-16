/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:02:53 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/16 16:29:24 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	init_cub_data(struct s_cub_data *cub_data)
{
	cub_data->utils.settings_already_set = 0;
	cub_data->settings.ceiling_color = NULL;
	cub_data->settings.floor_color = NULL;
	cub_data->settings.e_texture_path = NULL;
	cub_data->settings.n_texture_path = NULL;
	cub_data->settings.s_texture_path = NULL;
	cub_data->settings.w_texture_path = NULL;
	cub_data->settings.map = NULL;
	cub_data->utils.map_path = NULL;
	cub_data->mlx.mlx_ptr = NULL;
	cub_data->mlx.win_ptr = NULL;
	cub_data->mlx.img = NULL;
	cub_data->mlx.addr = NULL;
}

static void	check_file_extention(struct s_cub_data *cub_data)
{
	char	*ext;

	ext = ft_strrchr(cub_data->utils.map_path, '.');
	if (!ext || ft_strcmp(ext, FILE_EXTENTION) != 0)
	{
		cub_exit(BAD_FILE_EXTENTION, cub_data);
	}
}

static void	init_exit_functions_array(struct s_cub_data *cub_data)
{
	cub_data->utils.exit_funcs[0] = cub_exit_success;
	cub_data->utils.exit_funcs[1] = mlx_error;
	cub_data->utils.exit_funcs[2] = bad_arguments_msg;
	cub_data->utils.exit_funcs[3] = missing_setting_error;
	cub_data->utils.exit_funcs[4] = east_bad_file_path_error;
	cub_data->utils.exit_funcs[5] = north_bad_file_path_error;
	cub_data->utils.exit_funcs[6] = south_bad_file_path_error;
	cub_data->utils.exit_funcs[7] = west_bad_file_path_error;
	cub_data->utils.exit_funcs[8] = duplicated_setting_error;
	cub_data->utils.exit_funcs[9] = bad_setting_format_error;
	cub_data->utils.exit_funcs[10] = bad_color_code_format_error;
	cub_data->utils.exit_funcs[11] = bad_file_extention_msg;
	cub_data->utils.exit_funcs[12] = bad_identifier_error;
	cub_data->utils.exit_funcs[13] = map_missing;
	cub_data->utils.exit_funcs[14] = unclosed_map_error;
	cub_data->utils.exit_funcs[15] = map_wrong_character_error;
	cub_data->utils.exit_funcs[16] = map_missing_player_spawn_pos;
	cub_data->utils.exit_funcs[17] = map_duplicated_player_spawn_pos;
	cub_data->utils.exit_funcs[18] = missing_map_error;
	cub_data->utils.exit_funcs[19] = other_msg;
}

void	parsing(struct s_cub_data *cub_data)
{
	set_null_to_ptrs(cub_data); // combine with init_cub_data ?
	init_cub_data(cub_data);
	init_exit_functions_array(cub_data);
	if (cub_data->utils.argc != ARGUMENTS_REQUIRED)
	{
		cub_exit(BAD_ARGUMENTS, cub_data);
	}
	cub_data->utils.map_path = cub_data->utils.argv[1];
	check_file_extention(cub_data);
	extract_settings(cub_data);
}
