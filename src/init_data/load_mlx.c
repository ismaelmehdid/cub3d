/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:57:31 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/29 12:31:54 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	load_textures_imgs(t_cub_data *data)
{
	data->gun.std.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			GUN_IMG_1, &data->gun.std.width, &data->gun.std.height);
	data->gun.std2.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			GUN_IMG_2, &data->gun.std2.width, &data->gun.std2.height);
	data->gun.std3.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			GUN_IMG_3, &data->gun.std3.width, &data->gun.std3.height);
	data->gun.std4.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			GUN_IMG_4, &data->gun.std4.width, &data->gun.std4.height);
	data->gun.shoot1.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			SHOOT_IMG_1, &data->gun.shoot1.width, &data->gun.shoot1.height);
	data->gun.shoot2.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			SHOOT_IMG_2, &data->gun.shoot2.width, &data->gun.shoot2.height);
	data->gun.shoot3.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			SHOOT_IMG_3, &data->gun.shoot3.width, &data->gun.shoot3.height);
	data->utils.minimap.frame.img_ptr = \
		mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, FRAME,
			&data->utils.minimap.frame.width,
			&data->utils.minimap.frame.height);
}

static void	load_walls_imgs(t_cub_data *data)
{
	data->walls.north.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.n_texture_path,
			&data->walls.north.width, &data->walls.north.height);
	data->walls.south.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.s_texture_path,
			&data->walls.south.width, &data->walls.south.height);
	data->walls.east.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.e_texture_path,
			&data->walls.east.width, &data->walls.east.height);
	data->walls.west.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.w_texture_path,
			&data->walls.west.width, &data->walls.west.height);
	data->walls.door.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, DOOR,
			&data->walls.door.width, &data->walls.door.height);
}

static void	check_loaded_imgs(t_cub_data *data)
{
	if (!data->walls.west.img_ptr || !data->walls.east.img_ptr || \
		!data->walls.south.img_ptr || !data->walls.north.img_ptr)
		cub_exit(MLX_ERROR, data);
	if (!data->gun.shoot1.img_ptr || !data->gun.shoot2.img_ptr
		|| !data->gun.shoot3.img_ptr || !data->gun.std.img_ptr
		|| !data->gun.std2.img_ptr || !data->gun.std3.img_ptr
		|| !data->gun.std4.img_ptr || !data->utils.minimap.frame.img_ptr)
		cub_exit(MLX_ERROR, data);
	if (!data->walls.door.img_ptr)
		cub_exit(MLX_ERROR, data);
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
	mlx_mouse_hide(data->mlx.mlx_ptr, data->mlx.win_ptr);
	data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, data->mlx.win_width,
			data->mlx.win_height);
	if (!data->mlx.img)
		cub_exit(MLX_ERROR, data);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img,
			&data->mlx.bits, &data->mlx.line_len, &data->mlx.edian);
	load_walls_imgs(data);
	load_textures_imgs(data);
	check_loaded_imgs(data);
	get_imgs_addr(data);
}
