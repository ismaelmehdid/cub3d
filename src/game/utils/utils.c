/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:06:50 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/13 16:54:55 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

int	scale_player_pos(float pos)
{
	pos *= MINIMAP_SIZE / (RANGE * 2);
	pos += (RANGE * 2);
	return (pos);
}

void	minimap_frame(t_cub_data *data)
{
	int	x0_y0[2];
	int	x1_y1[2];

	x0_y0[0] = 0;
	x0_y0[1] = 220;
	x1_y1[0] = 220;
	x1_y1[1] = 220;
	bresenham_line_draw(data, x0_y0, x1_y1);
	x0_y0[0] = 220;
	x0_y0[1] = 0;
	bresenham_line_draw(data, x0_y0, x1_y1);
}

long	get_current_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

float	deg_to_rad(int a)
{
	return (a * M_PI / 180.0);
}

float	ft_fabs(float value)
{
	if (value < 0)
		return (-value);
	return (value);
}
