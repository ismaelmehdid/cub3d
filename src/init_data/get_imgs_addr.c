/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:54:33 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/22 20:23:35 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	get_imgs_adresses(t_cub_data *data)
{
	data->gun.std.data = mlx_get_data_addr(
			data->gun.std.img_ptr, &data->gun.std.bpp,
			&data->gun.std.size_line, &data->gun.std.endian);
	data->gun.std2.data = mlx_get_data_addr(
			data->gun.std2.img_ptr, &data->gun.std2.bpp,
			&data->gun.std2.size_line, &data->gun.std2.endian);
	data->gun.std4.data = mlx_get_data_addr(
			data->gun.std4.img_ptr, &data->gun.std4.bpp,
			&data->gun.std4.size_line, &data->gun.std4.endian);
	data->gun.std3.data = mlx_get_data_addr(
			data->gun.std3.img_ptr, &data->gun.std3.bpp,
			&data->gun.std3.size_line, &data->gun.std3.endian);
	data->gun.shoot1.data = mlx_get_data_addr(
			data->gun.shoot1.img_ptr, &data->gun.shoot1.bpp,
			&data->gun.shoot1.size_line, &data->gun.shoot1.endian);
	data->gun.shoot2.data = mlx_get_data_addr(
			data->gun.shoot2.img_ptr, &data->gun.shoot2.bpp,
			&data->gun.shoot2.size_line, &data->gun.shoot2.endian);
	data->gun.shoot3.data = mlx_get_data_addr(
			data->gun.shoot3.img_ptr, &data->gun.shoot3.bpp,
			&data->gun.shoot3.size_line, &data->gun.shoot3.endian);
	data->utils.minimap.frame.data = mlx_get_data_addr(
			data->utils.minimap.frame.img_ptr, &data->utils.minimap.frame.bpp,
			&data->utils.minimap.frame.size_line,
			&data->utils.minimap.frame.endian);
}

static void	get_walls_addr(t_cub_data *data)
{
	data->walls.north.data = mlx_get_data_addr(
			data->walls.north.img_ptr, &data->walls.north.bpp,
			&data->walls.north.size_line, &data->walls.north.endian);
	data->walls.south.data = mlx_get_data_addr(
			data->walls.south.img_ptr, &data->walls.south.bpp,
			&data->walls.south.size_line, &data->walls.south.endian);
	data->walls.east.data = mlx_get_data_addr(
			data->walls.east.img_ptr, &data->walls.east.bpp,
			&data->walls.east.size_line, &data->walls.east.endian);
	data->walls.west.data = mlx_get_data_addr(
			data->walls.west.img_ptr, &data->walls.west.bpp,
			&data->walls.west.size_line, &data->walls.west.endian);
	data->walls.door.data = mlx_get_data_addr(
			data->walls.door.img_ptr, &data->walls.door.bpp,
			&data->walls.door.size_line, &data->walls.door.endian);
}

void	get_imgs_addr(t_cub_data *data)
{
	get_imgs_adresses(data);
	get_walls_addr(data);
	data->gun.shoot_images[0] = &data->gun.shoot1;
	data->gun.shoot_images[1] = &data->gun.shoot2;
	data->gun.shoot_images[2] = &data->gun.shoot3;
	data->gun.shoot_images[3] = &data->gun.shoot1;
	data->gun.shoot_images[4] = &data->gun.shoot1;
	data->gun.gun_images[0] = &data->gun.std3;
	data->gun.gun_images[1] = &data->gun.std4;
}
