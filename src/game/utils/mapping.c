/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:22:50 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/08 18:23:19 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

int	map_player_pos_x(t_cub_data *cub_data, int x)
{
	return (x * cub_data->mlx.win_width) / cub_data->utils.map_width;
}

int	map_player_pos_y(t_cub_data *cub_data, int y)
{
	return (y * cub_data->mlx.win_height) / cub_data->utils.map_height;
}