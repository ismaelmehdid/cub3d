/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:38:49 by asyvash           #+#    #+#             */
/*   Updated: 2024/07/11 23:38:49 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void	put_scaled_pixel_to_image(t_cub_data *data, t_img *img,
	int x_y[2], int x_y_offset[2])
{
	int	color;
	int	scaled_x_y[2];

	color = *(int *)(img->data + x_y[1] * \
		img->size_line + x_y[0] * (img->bpp / 8));
	if ((color & 0xFFFFFF) != 0x000000)
	{
		scaled_x_y[1] = 0;
		while (scaled_x_y[1] < 3)
		{
			scaled_x_y[0] = 0;
			while (scaled_x_y[0] < 3)
			{
				*(int *)(data->mlx.addr + ((x_y[1] * 3 + scaled_x_y[1]) \
					+ x_y_offset[1]) * data->mlx.line_len +
						((x_y[0] * 3 + scaled_x_y[0]) + x_y_offset[0]) * \
							(data->mlx.bits / 8)) = color;
				scaled_x_y[0]++;
			}
			scaled_x_y[1]++;
		}
	}
}

static void	put_weapon_img(t_cub_data *data, t_img *img, int x_y_offset[2])
{
	int	x_y[2];

	x_y[1] = 0;
	while (x_y[1] < img->height)
	{
		x_y[0] = 0;
		while (x_y[0] < img->width)
		{
			put_scaled_pixel_to_image(data, img, x_y, x_y_offset);
			x_y[0]++;
		}
		x_y[1]++;
	}
}

static void	animate_shoot(t_cub_data *data, int x_y_offset[2])
{
	long	current_time;

	current_time = get_current_time_in_ms();
	if (data->gun.last_shoot_time == 0)
		data->gun.last_shoot_time = current_time;
	if (current_time - data->gun.last_shoot_time > 150)
	{
		data->gun.last_shoot_time = current_time;
		data->gun.shoot_frame++;
		if (data->gun.shoot_frame > 3)
		{
			data->gun.is_shooting = false;
			data->gun.shoot_frame = 0;
			data->gun.last_shoot_time = 0;
		}
	}
	x_y_offset[0] = (data->mlx.win_width - \
		(data->gun.shoot_images[data->gun.shoot_frame]->width * 3)) / 2;
	x_y_offset[1] = data->mlx.win_height - \
		(data->gun.shoot_images[data->gun.shoot_frame]->height * 3);
	put_weapon_img(data, data->gun.shoot_images[data->gun.shoot_frame],
		x_y_offset);
}

void	weapon_logic(t_cub_data *data, int gun_frame)
{
	int	x_y_offset[2];

	x_y_offset[0] = (data->mlx.win_width - \
		(data->gun.gun_images[gun_frame]->width * 3)) / 2;
	x_y_offset[1] = data->mlx.win_height - \
		(data->gun.gun_images[gun_frame]->height * 3);
	if (data->gun.is_shooting == true)
		animate_shoot(data, x_y_offset);
	else if (data->gun.shoot_frame == 0)
		put_weapon_img(data, data->gun.gun_images[gun_frame], x_y_offset);
}
