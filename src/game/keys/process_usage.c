/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:17:20 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/18 15:42:29 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	open_or_close_door(t_cub_data *data)
{
	if (data->ray->player_facing_door)
		printf("oui\n");
	else
		printf("non\n");
	if (data->ray->player_facing_door)
	{
		if (data->settings.map[data->ray->y_faced_door][data->ray->x_faced_door] == 'C')
		{
			printf("x=%d\n",data->ray->x_faced_door);
			printf("y=%d\n",data->ray->y_faced_door);
			data->settings.map[data->ray->y_faced_door][data->ray->x_faced_door] = 'O';
		}
		else
			data->settings.map[data->ray->y_faced_door][data->ray->x_faced_door] = 'C';
	}
}
