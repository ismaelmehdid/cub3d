/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:30:41 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/18 14:01:20 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void	destroy_mlx(t_cub_data *data)
{
	if (data->mlx.mlx_ptr && data->gun.shoot1.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->gun.shoot1.img_ptr);
	if (data->mlx.mlx_ptr && data->gun.shoot2.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->gun.shoot2.img_ptr);
	if (data->mlx.mlx_ptr && data->gun.shoot3.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->gun.shoot3.img_ptr);
	if (data->mlx.mlx_ptr && data->gun.std.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->gun.std.img_ptr);
	if (data->mlx.mlx_ptr && data->gun.std2.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->gun.std2.img_ptr);
	if (data->mlx.mlx_ptr && data->gun.std3.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->gun.std3.img_ptr);
	if (data->mlx.mlx_ptr && data->gun.std4.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->gun.std4.img_ptr);
	if (data->mlx.mlx_ptr && data->mlx.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.img);
	if (data->mlx.mlx_ptr && data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	if (data->mlx.mlx_ptr)
		mlx_destroy_display(data->mlx.mlx_ptr);
	if (data->mlx.mlx_ptr)
	{
		free(data->mlx.mlx_ptr);
		data->mlx.mlx_ptr = NULL;
	}
}

static void	free_walls_and_frame_imgs(t_cub_data *data)
{
	if (data->mlx.mlx_ptr && data->walls.east.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->walls.east.img_ptr);
	if (data->mlx.mlx_ptr && data->walls.north.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->walls.north.img_ptr);
	if (data->mlx.mlx_ptr && data->walls.west.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->walls.west.img_ptr);
	if (data->mlx.mlx_ptr && data->walls.south.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->walls.south.img_ptr);
	if (data->mlx.mlx_ptr && data->walls.door.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->walls.door.img_ptr);
	if (data->mlx.mlx_ptr && data->utils.minimap.frame.img_ptr)
	{
		mlx_destroy_image(data->mlx.mlx_ptr,
			data->utils.minimap.frame.img_ptr);
	}
}

static void	free_colors(t_cub_data *data)
{
	if (data->settings.ceiling_color)
	{
		free(data->settings.ceiling_color);
		data->settings.ceiling_color = NULL;
	}
	if (data->settings.floor_color)
	{
		free(data->settings.floor_color);
		data->settings.floor_color = NULL;
	}
}

static void	free_texture_path(t_cub_data *data)
{
	if (data->settings.e_texture_path)
	{
		free(data->settings.e_texture_path);
		data->settings.e_texture_path = NULL;
	}
	if (data->settings.n_texture_path)
	{
		free(data->settings.n_texture_path);
		data->settings.n_texture_path = NULL;
	}
	if (data->settings.s_texture_path)
	{
		free(data->settings.s_texture_path);
		data->settings.s_texture_path = NULL;
	}
	if (data->settings.w_texture_path)
	{
		free(data->settings.w_texture_path);
		data->settings.w_texture_path = NULL;
	}
}

void	free_everything(t_cub_data *data)
{
	free_texture_path(data);
	free_colors(data);
	free_double_array(&data->settings.map);
	free_walls_and_frame_imgs(data);
	destroy_mlx(data);
	exit (0);
}
