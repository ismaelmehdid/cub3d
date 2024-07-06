/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:38:35 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/06 22:40:08 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/cub3D.h"

void	mlx_error()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mMLX error.\n",
		STDERR_FILENO);
}
