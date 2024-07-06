/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:38:35 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/07 00:52:47 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3D.h"

void	mlx_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mMLX error.\n",
		STDERR_FILENO);
}

void	map_wrong_character_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mWrong map character.\n",
		STDERR_FILENO);
}

void	map_duplicated_player_spawn_pos()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mDuplicated player spawn position.\n",
		STDERR_FILENO);
}

void	map_missing_player_spawn_pos()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mMissing player spawn position.\n",
		STDERR_FILENO);
}
