/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:30:40 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/03 20:17:56 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void bad_setting_format_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mBad setting format.\n",
		STDERR_FILENO);
}

static void	other_msg()
{
	ft_putstr_fd("Error\n\033[0;31m", STDERR_FILENO);
	perror("");
}

static void	bad_file_extention_msg()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mBad file extention", STDERR_FILENO);
	ft_putstr_fd("\n\033[0;32mShould be a '.cub' file\n", STDERR_FILENO);
}

static void	bad_arguments_msg(t_cub_data *cub_data)
{
	int	i;

	i = 0;
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mWrong arguments: ", STDERR_FILENO);
	while (i < cub_data->utils.argc)
	{
		ft_putstr_fd(cub_data->utils.argv[i], STDERR_FILENO);
		if (i + 1 != cub_data->utils.argc)
		{
			ft_putstr_fd(" ", STDERR_FILENO);
		}
		i++;
	}
	ft_putstr_fd("\n\033[0;32mExpected ./cub3D valid_map.cub\n", STDERR_FILENO);
}

static void	duplicated_setting_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mDuplicated settings.\n",
		STDERR_FILENO);
}

static void	east_bad_file_path_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the east texture file.\n",
		STDERR_FILENO);
}

static void	north_bad_file_path_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the north texture file.\n",
		STDERR_FILENO);
}

static void	south_bad_file_path_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the south texture file.\n",
		STDERR_FILENO);
}

static void	west_bad_file_path_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the west texture file.\n",
		STDERR_FILENO);
}

static void	bad_color_code_format_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mBad color code format. Should be 'R,G,B' and 0 <= color <= 255.\n",
		STDERR_FILENO);
}

static void	bad_identifier_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mBad identifier or some settings are missing.\n",
		STDERR_FILENO);
}


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
	free_everything(cub_data);
	exit(EXIT_FAILURE);
	/*
	else if (code == MISSING_SETTING)
	else if (code == BAD_IDENTIFIER)
	else if (code == MAP_UNCLOSED)
	else if (code == MAP_WRONG_CHARACTER)
	else if (code == MAP_MISSING_CHARACTER)
	*/
}
