/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:30:40 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/02 19:54:09 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

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
	exit(EXIT_FAILURE);
	/*
	else if (code == MISSING_SETTING)
	else if (code == BAD_IDENTIFIER)
	else if (code == MAP_UNCLOSED)
	else if (code == MAP_WRONG_CHARACTER)
	else if (code == MAP_MISSING_CHARACTER)
	*/
}
