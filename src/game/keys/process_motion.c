/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_motion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:55:56 by asyvash           #+#    #+#             */
/*   Updated: 2024/07/15 14:55:56 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	move_forward(t_cub_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x + PLAYER_SPEED * cos(data->player_data.angle);
	if (data->settings.map[(int)data->player_data.y][(int)new_x] != '1')
	{
		data->player_data.x = new_x;
	}
	new_y = data->player_data.y + PLAYER_SPEED * sin(data->player_data.angle);
	if (data->settings.map[(int)new_y][(int)data->player_data.x] != '1')
	{
		data->player_data.y = new_y;
	}
}

void	move_backward(t_cub_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x - PLAYER_SPEED * cos(data->player_data.angle);
	if (data->settings.map[(int)data->player_data.y][(int)new_x] != '1')
	{
		data->player_data.x = new_x;
	}
	new_y = data->player_data.y - PLAYER_SPEED * sin(data->player_data.angle);
	if (data->settings.map[(int)new_y][(int)data->player_data.x] != '1')
	{
		data->player_data.y = new_y;
	}
}

void	move_left(t_cub_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x + STRAFE_SPEED * sin(data->player_data.angle);
	if (data->settings.map[(int)data->player_data.y][(int)new_x] != '1')
	{
		data->player_data.x = new_x;
	}
	new_y = data->player_data.y - STRAFE_SPEED * cos(data->player_data.angle);
	if (data->settings.map[(int)new_y][(int)data->player_data.x] != '1')
	{
		data->player_data.y = new_y;
	}
}

void	move_right(t_cub_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x - STRAFE_SPEED * sin(data->player_data.angle);
	if (data->settings.map[(int)data->player_data.y][(int)new_x] != '1')
	{
		data->player_data.x = new_x;
	}
	new_y = data->player_data.y + STRAFE_SPEED * cos(data->player_data.angle);
	if (data->settings.map[(int)new_y][(int)data->player_data.x] != '1')
	{
		data->player_data.y = new_y;
	}
}
