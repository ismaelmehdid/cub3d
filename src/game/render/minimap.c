/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:59:42 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/08 19:04:44 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void	draw_element(t_cub_data *cub_data, int i, int j, int color)
{
	int	x;
	int	y;
	int	end_x;
	int	end_y;

	x = i * cub_data->utils.minimap_data.cell_width;
	y = j * cub_data->utils.minimap_data.cell_height;
	end_x = x + cub_data->utils.minimap_data.cell_width;
	end_y = y + cub_data->utils.minimap_data.cell_height;
	while (y < end_y)
	{
		x = i * cub_data->utils.minimap_data.cell_width;
		while (x < end_x)
		{
			ft_mlx_pixel_put(cub_data, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_map_elements(t_cub_data *cub_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	cub_data->utils.minimap_data.cell_width =
		cub_data->mlx.win_width / cub_data->utils.map_width;
	cub_data->utils.minimap_data.cell_height =
		cub_data->mlx.win_height / cub_data->utils.map_height;
	while (cub_data->settings.map[j])
	{
		i = 0;
		while (cub_data->settings.map[j][i])
		{
			if (cub_data->settings.map[j][i] == '1')
				draw_element(cub_data, i, j, WHITE);
			else
				draw_element(cub_data, i, j, GREY);
			i++;
		}
		j++;
	}
}

static void	draw_player_dot(t_cub_data *cub_data)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	y;
	int	x;

	start_x = cub_data->player_data.x - PLAYER_DOT_SIZE / 2;
	start_y = cub_data->player_data.y - PLAYER_DOT_SIZE / 2;
	end_x = start_x + PLAYER_DOT_SIZE;
	end_y = start_y + PLAYER_DOT_SIZE;
	y = start_y;
	while (y < end_y)
	{
		x = start_x;
		while (x < end_x)
		{
			ft_mlx_pixel_put(cub_data, x, y, RED);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_cub_data *cub_data)
{
	draw_map_elements(cub_data);
	draw_player_dot(cub_data);
}