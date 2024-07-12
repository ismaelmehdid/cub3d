/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:27:15 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/12 18:47:01 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

int	render(t_cub_data *data)
{
	printf("Player angle in rad: %f", data->player_data.angle);
	fill_background(data, 0, 0);
	draw_minimap(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->mlx.img, 0, 0);
	return (0);
}