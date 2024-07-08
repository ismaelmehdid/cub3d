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

void    ft_mlx_pixel_put(t_cub_data *data, int x, int y, int color)
{
    char    *dst;

	if (!data)
		return ;
    dst = data->mlx.addr + (y * data->mlx.line_len + x * (data->mlx.bits / 8));
	if (dst < data->mlx.addr || dst >= data->mlx.addr + data->mlx.line_len * data->mlx.win_height)
        return;
    *(unsigned int*)dst = color;
}