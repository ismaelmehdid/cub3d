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

#include "../../../include/cub3D.h"

static void minimap_frame(t_cub_data *data)
{
    int x0_y0[2];
    int x1_y1[2];

    x0_y0[0] = 0;
    x0_y0[1] = 220;
    x1_y1[0] = 220;
    x1_y1[1] = 220;
    bresenham_line_draw(data, x0_y0, x1_y1);
    x0_y0[0] = 220;
    x0_y0[1] = 0;
    bresenham_line_draw(data, x0_y0, x1_y1);
}

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
    while (y < data->mlx.win_height / 2)
    {
		x = 0;
        while (x < data->mlx.win_width)
        {
            ft_mlx_pixel_put(data, x, y, get_floor_color(data));
			x++;
        }
		y++;
    }
	y = data->mlx.win_height / 2;
    while (y < data->mlx.win_height)
    {
		x = 0;
        while (x < data->mlx.win_width)
        {
            ft_mlx_pixel_put(data, x, y, get_ceiling_color(data));
			x++;
        }
		y++;
    }
    minimap_frame(data);
}
