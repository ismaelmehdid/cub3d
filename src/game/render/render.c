/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:27:15 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/08 18:35:50 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

int	render(t_cub_data *cub_data)
{
	draw_minimap(cub_data);
	mlx_put_image_to_window(
		cub_data->mlx.mlx_ptr,
		cub_data->mlx.win_ptr,
		cub_data->mlx.img,
		0,
		0);
	return (0);
}