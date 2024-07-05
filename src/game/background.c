/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:51:01 by asyvash           #+#    #+#             */
/*   Updated: 2024/07/05 18:51:01 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int  create_trgb(unsigned char r, unsigned char g, unsigned char b)
{
    int t;

    t = 0;
    return (t << 24 | r << 16 | g << 8 | b);
}

static int  get_floor_color(t_cub_data *data)
{
    return (create_trgb(data->settings.floor_color->r, 
        data->settings.floor_color->g, data->settings.floor_color->b));
}

static int  get_ceiling_color(t_cub_data *data)
{
    return (create_trgb(data->settings.ceiling_color->r, 
        data->settings.ceiling_color->g, data->settings.ceiling_color->b));
}

void	fill_background(t_cub_data *data, int x, int y)
{
    while (y < data->mlx.height / 2)
    {
		x = 0;
        while (x < data->mlx.width)
        {
            ft_mlx_pixel_put(data, x, y, get_floor_color(data));
			x++;
        }
		y++;
    }
	y = data->mlx.height / 2;
    while (y < data->mlx.height)
    {
		x = 0;
        while (x < data->mlx.width)
        {
            ft_mlx_pixel_put(data, x, y, get_ceiling_color(data));
			x++;
        }
		y++;
    }
    mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->mlx.img, 0, 0);
}