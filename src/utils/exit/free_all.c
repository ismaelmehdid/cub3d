/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:30:41 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/14 18:28:28 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void	free_texture_path(t_cub_data *cub_data)
{
	if (cub_data->settings.e_texture_path)
	{
		free(cub_data->settings.e_texture_path);
		cub_data->settings.e_texture_path = NULL;
	}
	if (cub_data->settings.n_texture_path)
	{
		free(cub_data->settings.n_texture_path);
		cub_data->settings.n_texture_path = NULL;
	}
	if (cub_data->settings.s_texture_path)
	{
		free(cub_data->settings.s_texture_path);
		cub_data->settings.s_texture_path = NULL;
	}
	if (cub_data->settings.w_texture_path)
	{
		free(cub_data->settings.w_texture_path);
		cub_data->settings.w_texture_path = NULL;
	}
}

static void	free_colors(t_cub_data *cub_data)
{
	if (cub_data->settings.ceiling_color)
	{
		free(cub_data->settings.ceiling_color);
		cub_data->settings.ceiling_color = NULL;
	}
	if (cub_data->settings.floor_color)
	{
		free(cub_data->settings.floor_color);
		cub_data->settings.floor_color = NULL;
	}
}

static void	free_map(t_cub_data *cub_data)
{
	free_double_array(&cub_data->settings.map);
}

static void	destroy_mlx(t_cub_data *cub_data)
{
	if (cub_data->mlx.mlx_ptr && cub_data->gun.shoot1.img_ptr)
		mlx_destroy_image(cub_data->mlx.mlx_ptr, cub_data->gun.shoot1.img_ptr);
	if (cub_data->mlx.mlx_ptr && cub_data->gun.shoot2.img_ptr)
		mlx_destroy_image(cub_data->mlx.mlx_ptr, cub_data->gun.shoot2.img_ptr);
	if (cub_data->mlx.mlx_ptr && cub_data->gun.shoot3.img_ptr)
		mlx_destroy_image(cub_data->mlx.mlx_ptr, cub_data->gun.shoot3.img_ptr);
	if (cub_data->mlx.mlx_ptr && cub_data->gun.std.img_ptr)
		mlx_destroy_image(cub_data->mlx.mlx_ptr, cub_data->gun.std.img_ptr);
	if (cub_data->mlx.mlx_ptr && cub_data->gun.std2.img_ptr)
		mlx_destroy_image(cub_data->mlx.mlx_ptr, cub_data->gun.std2.img_ptr);
	if (cub_data->mlx.mlx_ptr && cub_data->gun.std3.img_ptr)
		mlx_destroy_image(cub_data->mlx.mlx_ptr, cub_data->gun.std3.img_ptr);
	if (cub_data->mlx.mlx_ptr && cub_data->gun.std4.img_ptr)
		mlx_destroy_image(cub_data->mlx.mlx_ptr, cub_data->gun.std4.img_ptr);
	if (cub_data->mlx.mlx_ptr && cub_data->mlx.img)
		mlx_destroy_image(cub_data->mlx.mlx_ptr, cub_data->mlx.img);
	if (cub_data->mlx.mlx_ptr && cub_data->mlx.win_ptr)
		mlx_destroy_window(cub_data->mlx.mlx_ptr, cub_data->mlx.win_ptr);
	if (cub_data->mlx.mlx_ptr)
		mlx_destroy_display(cub_data->mlx.mlx_ptr);
	if (cub_data->mlx.mlx_ptr)
	{
		free(cub_data->mlx.mlx_ptr);
		cub_data->mlx.mlx_ptr = NULL;
	}
}

void	free_everything(t_cub_data *cub_data)
{
	free_texture_path(cub_data);
	free_colors(cub_data);
	free_map(cub_data);
	destroy_mlx(cub_data); // need to destroy walls images
	exit (0);
}
