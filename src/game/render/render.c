/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:27:15 by imehdid           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/12 18:47:01 by imehdid          ###   ########.fr       */
=======
/*   Updated: 2024/07/12 22:12:03 by asyvash          ###   ########.fr       */
>>>>>>> 3773851423fb82bfc5f7a63610f9d235cd5db476
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

int	render(t_cub_data *data)
{
<<<<<<< HEAD
	printf("Player angle in rad: %f", data->player_data.angle);
	fill_background(data, 0, 0);
	draw_minimap(data);
=======
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
    fill_background(data, 0, 0);
>>>>>>> 3773851423fb82bfc5f7a63610f9d235cd5db476
	raycasting(data);
    draw_minimap(data);
	weapon_logic(data, gun_frame);
    mlx_put_image_to_window(data->mlx.mlx_ptr,
        data->mlx.win_ptr, data->mlx.img, 0, 0);
    return (0);
}