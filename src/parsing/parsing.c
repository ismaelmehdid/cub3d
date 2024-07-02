/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:02:53 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/02 18:19:43 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	extract_settings(struct s_cub_data *cub_data)
{
	
}

void	parsing(struct s_cub_data *cub_data)
{
	if (cub_data->utils.argc != ARGUMENTS_REQUIRED)
	{
		cub_exit(BAD_ARGUMENTS, cub_data);
	}
	extract_settings
}