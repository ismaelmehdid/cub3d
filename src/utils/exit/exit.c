/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:30:40 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/02 17:43:12 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void	bad_arguments_msg(t_cub_data *cub_data)
{
	int	i;

	i = 0;
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mWrong arguments: ", STDERR_FILENO);
	while (i < cub_data->utils.argc)
	{
		ft_putstr_fd(cub_data->utils.argv[i], STDERR_FILENO);
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
	exit(EXIT_FAILURE);
	/*
	else if (code == MISSING_SETTING)
	else if (code == BAD_FILE_EXTENTION)
	else if (code == BAD_IDENTIFIER)
	else if (code == MAP_UNCLOSED)
	else if (code == MAP_WRONG_CHARACTER)
	else if (code == MAP_MISSING_CHARACTER)
	*/
}
