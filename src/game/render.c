/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:27:15 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/17 15:37:56 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	render(t_cub_data *data)
{
	static long	last_time;
	static int	gun_frame;
	long		current_time;

	if (!last_time)
		last_time = 0;
	if (!gun_frame)
		gun_frame = 0;
	current_time = get_current_time_in_ms();
	if (current_time - last_time > 1500)
	{
		last_time = current_time;
		gun_frame = (gun_frame + 1) % 2;
	}
	handle_keys(data);
	fill_background(data, 0, 0);
	raycasting(data);
	draw_minimap(data, 0, 0);
	weapon_logic(data, gun_frame);
	mlx_put_image_to_window(data->mlx.mlx_ptr,
		data->mlx.win_ptr, data->mlx.img, 0, 0);
	return (0);
}
