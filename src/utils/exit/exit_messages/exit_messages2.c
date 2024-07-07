/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:37:55 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/07 15:22:41 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3D.h"

void	east_bad_file_path_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the east texture file.\n\033[0m",
		STDERR_FILENO);
}

void	north_bad_file_path_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the north texture file.\n\033[0m",
		STDERR_FILENO);
}

void	south_bad_file_path_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the south texture file.\n\033[0m",
		STDERR_FILENO);
}

void	west_bad_file_path_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the west texture file.\n\033[0m",
		STDERR_FILENO);
}

