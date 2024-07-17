/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:06:50 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/17 15:35:08 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

int	scale_player_pos(float pos)
{
	pos *= MINIMAP_SIZE / (RANGE * 2);
	return (pos);
}

void	minimap_frame(t_cub_data *data)
{
	t_img	*frame;
	int		x;
	int		y;
	int		color;

	frame = &data->utils.minimap.frame;
	y = 0;
	while (y < frame->height)
	{
		x = 0;
		while (x < frame->width)
		{
			color = *(int *)(frame->data + y * \
				frame->size_line + x * (frame->bpp / 8));
			if ((color & 0xFFFFFF) != BLACK)
			{
				*(int *)(data->mlx.addr + y * \
					data->mlx.line_len + x * (data->mlx.bits / 8)) = color;
			}
			x++;
		}
		y++;
	}
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
