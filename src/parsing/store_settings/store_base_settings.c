/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_base_settings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:27:29 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/15 22:52:44 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	store_setting(struct s_cub_data *cub_data, char **line_elements, int fd)
{
	if (store_texture_path(cub_data, line_elements, fd) == 0)
	{
		printf("Texture path stored successfully.\n");
	}
	else if (store_colors(cub_data, line_elements, fd, '0') == 0)
	{
		printf("Color stored successfully.\n");
	}
	else
	{
		free_double_array(&line_elements);
		reach_eof_to_avoid_leaks(NULL, fd);
		close(fd);
		cub_exit(BAD_IDENTIFIER, cub_data);
	}
	cub_data->utils.settings_already_set++;
	free_double_array(&line_elements);
}
