/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:54:33 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/18 13:59:39 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	load_door_img(t_cub_data *data)
{
	data->walls.door.img_ptr = mlx_xpm_file_to_image(
		data->mlx.mlx_ptr, DOOR,
		&data->walls.door.width, &data->walls.door.height);
	data->walls.door.data = mlx_get_data_addr(
		data->walls.door.img_ptr, &data->walls.door.bpp,
		&data->walls.door.size_line, &data->walls.door.endian);
}
