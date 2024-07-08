/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:57:31 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/08 18:06:09 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	load_mlx(t_cub_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		cub_exit(MLX_ERROR, data);
	data->mlx.win_width = WIN_WIDTH;
	data->mlx.win_height = WIN_HEIGHT;
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
		data->mlx.win_width, data->mlx.win_height, "cub3D");
	if (!data->mlx.win_ptr)
	{
		free(data->mlx.mlx_ptr);
		cub_exit(MLX_ERROR, data);
	}
	data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, data->mlx.win_width,
		data->mlx.win_height);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, 
		&data->mlx.bits, &data->mlx.line_len, &data->mlx.edian);
}
