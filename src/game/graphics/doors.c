/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:30:23 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/21 17:20:04 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	get_looking_door_values(t_ray_cast *ray, char map_value)
{
	if (map_value == 'C' || map_value == 'O')
	{
		ray->player_facing_door = true;
		ray->y_faced_door = ray->map_y;
		ray->x_faced_door = ray->map_x;
	}
	ray->door_hit = (map_value == 'C' || map_value == 'O');
}
