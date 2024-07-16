/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:37:08 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/16 16:37:44 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3D.h"

void	bad_setting_format_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mBad setting format.\033[0m\n",
		STDERR_FILENO);
}

void	other_msg(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	perror("");
}

void	bad_file_extention_msg(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mBad file extention.", STDERR_FILENO);
	ft_putstr_fd("\n\033[0;32mShould be a '.cub' file\033[0m\n",
		STDERR_FILENO);
}

void	bad_arguments_msg(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mWrong arguments.", STDERR_FILENO);
	ft_putstr_fd("\n\033[0;32mExpected ./cub3D valid_map.cub\n\033[0m",
		STDERR_FILENO);
}

void	duplicated_setting_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mDuplicated settings.\n\033[0m",
		STDERR_FILENO);
}
