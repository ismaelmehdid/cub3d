/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:57:31 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/16 16:49:14 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void	load_weapon_shoot_imgs(t_cub_data *data)
{
	data->gun.shoot1.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, "./game_data/textures/shoot.xpm",
			&data->gun.shoot1.width, &data->gun.shoot1.height);
	data->gun.shoot1.data = mlx_get_data_addr(
			data->gun.shoot1.img_ptr, &data->gun.shoot1.bpp,
			&data->gun.shoot1.size_line, &data->gun.shoot1.endian);
	data->gun.shoot2.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, "./game_data/textures/shoot2.xpm",
			&data->gun.shoot2.width, &data->gun.shoot2.height);
	data->gun.shoot2.data = mlx_get_data_addr(
			data->gun.shoot2.img_ptr, &data->gun.shoot2.bpp,
			&data->gun.shoot2.size_line, &data->gun.shoot2.endian);
	data->gun.shoot3.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, "./game_data/textures/shoot3.xpm",
			&data->gun.shoot3.width, &data->gun.shoot3.height);
	data->gun.shoot3.data = mlx_get_data_addr(
			data->gun.shoot3.img_ptr, &data->gun.shoot3.bpp,
			&data->gun.shoot3.size_line, &data->gun.shoot3.endian);
	data->gun.shoot_frame = 0;
	data->gun.is_shooting = false;
	data->gun.last_shoot_time = 0;
	data->gun.shoot_images[0] = &data->gun.shoot1;
	data->gun.shoot_images[1] = &data->gun.shoot2;
	data->gun.shoot_images[2] = &data->gun.shoot3;
	data->gun.shoot_images[3] = &data->gun.shoot1;
	data->gun.shoot_images[4] = &data->gun.shoot1;
}

static void	load_weapon_std_imgs(t_cub_data *data)
{
	data->gun.std.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, "./game_data/textures/std1.xpm",
			&data->gun.std.width, &data->gun.std.height);
	data->gun.std.data = mlx_get_data_addr(data->gun.std.img_ptr,
			&data->gun.std.bpp, &data->gun.std.size_line, &data->gun.std.endian);
	data->gun.std2.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			"./game_data/textures/std2.xpm",
			&data->gun.std2.width, &data->gun.std2.height);
	data->gun.std2.data = mlx_get_data_addr(data->gun.std2.img_ptr,
			&data->gun.std2.bpp, &data->gun.std2.size_line, &data->gun.std2.endian);
	data->gun.std3.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			"./game_data/textures/std3.xpm",
			&data->gun.std3.width, &data->gun.std3.height);
	data->gun.std3.data = mlx_get_data_addr(data->gun.std3.img_ptr,
			&data->gun.std3.bpp, &data->gun.std3.size_line, &data->gun.std3.endian);
	data->gun.std4.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			"./game_data/textures/std4.xpm",
			&data->gun.std4.width, &data->gun.std4.height);
	data->gun.std4.data = mlx_get_data_addr(data->gun.std4.img_ptr,
			&data->gun.std4.bpp, &data->gun.std4.size_line, &data->gun.std4.endian);
	data->gun.gun_images[0] = &data->gun.std3;
	data->gun.gun_images[1] = &data->gun.std4;
}

void	set_null_to_ptrs(t_cub_data *data)
{
	data->gun.shoot1.img_ptr = NULL;
	data->gun.shoot2.img_ptr = NULL;
	data->gun.shoot3.img_ptr = NULL;
	data->gun.std.img_ptr = NULL;
	data->gun.std2.img_ptr = NULL;
	data->gun.std3.img_ptr = NULL;
	data->gun.std4.img_ptr = NULL;
	data->mlx.mlx_ptr = NULL;
	data->mlx.img = NULL;
	data->mlx.win_ptr = NULL;
	data->keys.keys[0] = false;
	data->keys.keys[1] = false;
	data->keys.keys[2] = false;
	data->keys.keys[3] = false;
	data->keys.keys[4] = false;
	data->keys.keys[5] = false;
	data->walls.east.img_ptr = NULL;
	data->walls.north.img_ptr = NULL;
	data->walls.south.img_ptr = NULL;
	data->walls.west.img_ptr = NULL;
}

static void	load_walls_imgs(t_cub_data *data)
{
	data->walls.north.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.n_texture_path,
			&data->walls.north.width, &data->walls.north.height);
	data->walls.north.data = mlx_get_data_addr(
			data->walls.north.img_ptr, &data->walls.north.bpp,
			&data->walls.north.size_line, &data->walls.north.endian);
	data->walls.south.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.s_texture_path,
			&data->walls.south.width, &data->walls.south.height);
	data->walls.south.data = mlx_get_data_addr(
			data->walls.south.img_ptr, &data->walls.south.bpp,
			&data->walls.south.size_line, &data->walls.south.endian);
	data->walls.east.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.e_texture_path,
			&data->walls.east.width, &data->walls.east.height);
	data->walls.east.data = mlx_get_data_addr(
			data->walls.east.img_ptr, &data->walls.east.bpp,
			&data->walls.east.size_line, &data->walls.east.endian);
	data->walls.west.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.w_texture_path,
			&data->walls.west.width, &data->walls.west.height);
	data->walls.west.data = mlx_get_data_addr(
			data->walls.west.img_ptr, &data->walls.west.bpp,
			&data->walls.west.size_line, &data->walls.west.endian);
}

void	load_mlx(t_cub_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		cub_exit(MLX_ERROR, data);
	mlx_get_screen_size(data->mlx.mlx_ptr, &data->mlx.win_width,
		&data->mlx.win_height);
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
			data->mlx.win_width, data->mlx.win_height, "cub3D");
	if (!data->mlx.win_ptr)
		cub_exit(MLX_ERROR, data);
	data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, data->mlx.win_width,
			data->mlx.win_height);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img,
			&data->mlx.bits, &data->mlx.line_len, &data->mlx.edian);
	load_walls_imgs(data);
	load_weapon_std_imgs(data);
	load_weapon_shoot_imgs(data);
	if (!data->gun.shoot1.img_ptr || !data->gun.shoot2.img_ptr
		|| !data->gun.shoot3.img_ptr || !data->gun.std.img_ptr
		|| !data->gun.std2.img_ptr || !data->gun.std3.img_ptr
		|| !data->gun.std4.img_ptr)
		cub_exit(MLX_ERROR, data);
}
