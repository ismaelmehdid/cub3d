/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:30:41 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/03 17:43:45 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void	free_texture_path(t_cub_data *cub_data)
{
	if (cub_data->settings.e_texture_path)
	{
		free(cub_data->settings.e_texture_path);
		cub_data->settings.e_texture_path = NULL;
	}
	if (cub_data->settings.n_texture_path)
	{
		free(cub_data->settings.n_texture_path);
		cub_data->settings.n_texture_path = NULL;
	}
	if (cub_data->settings.s_texture_path)
	{
		free(cub_data->settings.s_texture_path);
		cub_data->settings.s_texture_path = NULL;
	}
	if (cub_data->settings.w_texture_path)
	{
		free(cub_data->settings.w_texture_path);
		cub_data->settings.w_texture_path = NULL;
	}
}

static void	free_colors(t_cub_data *cub_data)
{
	if (cub_data->settings.ceiling_color)
	{
		free(cub_data->settings.ceiling_color);
		cub_data->settings.ceiling_color = NULL;
	}
	if (cub_data->settings.floor_color)
	{
		free(cub_data->settings.floor_color);
		cub_data->settings.floor_color = NULL;
	}
}

static void	free_map(t_cub_data *cub_data)
{
	int	i;

	i = 0;
	if (cub_data->settings.map)
	{
		while (cub_data->settings.map[i])
		{
			free(cub_data->settings.map[i]);
			cub_data->settings.map[i] = NULL;
			i++;
		}
		free(cub_data->settings.map);
		cub_data->settings.map = NULL;
	}
}

void	free_everything(t_cub_data *cub_data)
{
	free_texture_path(cub_data);
	free_colors(cub_data);
	free_map(cub_data);
}
