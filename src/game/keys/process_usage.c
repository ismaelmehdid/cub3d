/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:17:20 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/23 23:02:14 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	open_or_close_door(t_cub_data *data)
{
	float	distance_to_door;

	if (data->ray.player_facing_door)
	{
		distance_to_door = sqrt(
				pow(data->player_data.x - data->ray.x_faced_door - 0.5, 2)
				+ pow(data->player_data.y - data->ray.y_faced_door - 0.5, 2));
		if (distance_to_door <= MAX_DOOR_INTERACT_DISTANCE)
		{
			if (data->settings.map
				[data->ray.y_faced_door][data->ray.x_faced_door] == 'C')
				data->settings.map
				[data->ray.y_faced_door][data->ray.x_faced_door] = 'O';
			else
				data->settings.map
				[data->ray.y_faced_door][data->ray.x_faced_door] = 'C';
		}
	}
}
