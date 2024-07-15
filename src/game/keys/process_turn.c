/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:55:53 by asyvash           #+#    #+#             */
/*   Updated: 2024/07/15 14:55:53 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	turn_left(t_cub_data *data)
{
	float	radian_step;

	radian_step = SENSITIVITY * M_PI / 180;
	data->player_data.angle -= radian_step;
	if (data->player_data.angle < 0)
		data->player_data.angle += 2 * M_PI;
}

void    turn_right(t_cub_data *data)
{
	float	radian_step;

	radian_step = SENSITIVITY * M_PI / 180;
	data->player_data.angle += radian_step;
	if (data->player_data.angle >= 2 * M_PI)
		data->player_data.angle -= 2 * M_PI;
}
