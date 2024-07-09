/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:52:45 by asyvash           #+#    #+#             */
/*   Updated: 2024/07/05 18:52:45 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

int get_sx_sy(int var1, int var2)
{
    if (var1 < var2)
        return (1);
    return (-1);
}

void    bresenham_line_draw(t_cub_data *data, int x0_y0[2], int x1_y1[2])
{
    t_bresenham var;

    var.dx_dy[0] = abs(x1_y1[0] - x0_y0[0]);
    var.dx_dy[1] = -abs(x1_y1[1] - x0_y0[1]);
    var.sx_sy[0] = get_sx_sy(x0_y0[0], x1_y1[0]);
    var.sx_sy[1] = get_sx_sy(x0_y0[1], x1_y1[1]);
    var.err = var.dx_dy[0] + var.dx_dy[1];
    while (1)
    {
        ft_mlx_pixel_put(data, x0_y0[0], x0_y0[1], RED);
        if (x0_y0[0] == x1_y1[0] && x0_y0[1] == x1_y1[1])
            break;
        var.e2 = 2 * var.err;
        if (var.e2 >= var.dx_dy[1])
        {
            var.err += var.dx_dy[1];
            x0_y0[0] += var.sx_sy[0];
        }
        if (var.e2 <= var.dx_dy[0])
        {
            var.err += var.dx_dy[0];
            x0_y0[1] += var.sx_sy[1];
        }
    }
}

void    ft_mlx_pixel_put(t_cub_data *data, int x, int y, int color)
{
    char    *dst;
    
	if (!data)
		return ;
    dst = data->mlx.addr + \
        (y * data->mlx.line_len + x * (data->mlx.bits / 8));
	if (dst < data->mlx.addr || dst >= data->mlx.addr + \
        data->mlx.line_len * data->mlx.win_height)
        return;
    *(unsigned int*)dst = color;
}