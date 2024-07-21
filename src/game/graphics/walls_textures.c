/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:07:35 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/21 17:20:40 by imehdid          ###   ########.fr       */
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

	if (ray->side == 0) // horizontal line hit so calculing the ray hit position with the y axis
		wall_x = data->player_data.y + ray->raw_wall_dist * ray->ray_dir_y;
	else // vertical line hit so calculing the ray hit position with the y axis
		wall_x = data->player_data.x + ray->raw_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x); // get the fractional part of wall_x
	ray->texture_x = (int)(wall_x * (double)(texture->width)); // get the exact x of texture_x by scaling wall_x with the texture size
	if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1 && ray->ray_dir_y > 0)) // inverting the textures of the west and the south
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
		// these two lines are scaling the texture y coordinates to the screen
		d = y * 256 - data->mlx.win_height * 128 + ray->line_height * 128; // getting fixed point numbers
		ray->texture_y = ((d * texture->height) / ray->line_height) / 256; // scaling it and reconverting it to float
		if (ray->texture_y < 0) // checking bounds
			ray->texture_y = 0;
		if (ray->texture_y >= texture->height) // checking bounds
			ray->texture_y = texture->height - 1;
		color = get_texture_color(texture, ray->texture_x, ray->texture_y);
		ft_mlx_pixel_put(data, ray->column, y, color);
		y++;
	}
}

void	put_wall_texture(t_cub_data *data, t_ray_cast *ray)
{
	if (ray->door_hit) // don't put texture if it's an open door
		put_wall(data, ray, &data->walls.door);
	else if (ray->side == 0) // vertical line hit so west or east
	{
		if (ray->ray_dir_x > 0) // ray going right so hitting east
			put_wall(data, ray, &data->walls.east);
		else // hitting west
			put_wall(data, ray, &data->walls.west);
	}
	else // horizontal so north or south
	{
		if (ray->ray_dir_y > 0) // ray going up so hitting south
			put_wall(data, ray, &data->walls.south);
		else // hitting north
			put_wall(data, ray, &data->walls.north);
	}
}
