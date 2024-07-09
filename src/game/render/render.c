/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:27:15 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/09 16:38:46 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

int	render(t_cub_data *data)
{
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.img);
    data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, data->mlx.win_width, data->mlx.win_height);
    data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits, &data->mlx.line_len, &data->mlx.edian);
	fill_background(data, 0, 0);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->mlx.img, 0, 0);
	return (0);
}