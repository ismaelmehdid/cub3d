/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:07:35 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/23 23:07:32 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static int	get_texture_color(t_img *texture, int x, int y)
{
	return (*(int *)(texture->data + y
		* texture->size_line + x * (texture->bpp / 8)));
}

static void	get_wall_texture_coords(
	t_cub_data *data,
	t_ray_cast *ray,
	t_img *texture)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = data->player_data.y + ray->raw_wall_dist * ray->ray_dir_y;
	else
		wall_x = data->player_data.x + ray->raw_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	ray->texture_x = (int)(wall_x * (double)(texture->width));
	if ((ray->side == 0 && ray->ray_dir_x < 0)
		|| (ray->side == 1 && ray->ray_dir_y > 0))
		ray->texture_x = texture->width - ray->texture_x - 1;
}

static void	put_wall(t_cub_data *data, t_ray_cast *ray, t_img *texture)
{
	int				y;
	unsigned int	color;
	int				d;

	y = ray->line_draw_start;
	get_wall_texture_coords(data, ray, texture);
	while (y < ray->line_draw_end)
	{
		d = y - data->mlx.win_height / 2 + ray->line_height / 2;
		ray->texture_y = ((d * texture->height) / ray->line_height);
		if (ray->texture_y < 0)
			ray->texture_y = 0;
		if (ray->texture_y >= texture->height)
			ray->texture_y = texture->height - 1;
		color = get_texture_color(texture, ray->texture_x, ray->texture_y);
		ft_mlx_pixel_put(data, ray->column, y, color);
		y++;
	}
}

void	put_wall_texture(t_cub_data *data, t_ray_cast *ray)
{
	if (ray->door_hit)
		put_wall(data, ray, &data->walls.door);
	else if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			put_wall(data, ray, &data->walls.west);
		else
			put_wall(data, ray, &data->walls.east);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			put_wall(data, ray, &data->walls.north);
		else
			put_wall(data, ray, &data->walls.south);
	}
}
