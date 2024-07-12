/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:59:34 by asyvash           #+#    #+#             */
/*   Updated: 2024/07/07 15:59:34 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	game_algorithm(t_cub_data *data)
{
	printf("angle: %f\n", data->player_data.angle);
	printf("x: %f\n", data->player_data.x);
	printf("y: %f\n", data->player_data.y);
	fill_background(data, 0, 0);
	raycasting(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, 
		data->mlx.win_ptr, data->mlx.img, 0, 0);
	mlx_loop_hook(data->mlx.mlx_ptr, render, data);
}

void	game_loop(t_cub_data *data)
{
	game_algorithm(data);
	mlx_hook(data->mlx.win_ptr, 2, 1L << 0, (void *)key_hook, &data);
	mlx_hook(data->mlx.win_ptr, 17, 1L << 17, (void *)free_everything, &(*data));
	mlx_mouse_hook(data->mlx.win_ptr, mouse_hook, data);
	mlx_loop(data->mlx.mlx_ptr);
}