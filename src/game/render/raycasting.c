/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:09:53 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/12 01:00:04 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static float	ft_fabs(float value)
{
	if (value < 0)
		return (-value);
	return (value);
}

static void	dda_algorithm(t_cub_data *data, t_ray_cast *ray)
{
	bool	hit;

	hit = false;
	while (hit == false)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->settings.map[ray->map_x][ray->map_y] == '1')
			hit = true;
	}
}

// compute initial values about the ray angle and how many steps
// the vector is traveling for one X step and one Y step and which
// wall will be checked every step.

static void	compute_raycasting_values(t_cub_data *data, t_ray_cast *ray)
{
		ray->ray_angle = data->player_data.angle - (FOV / 2) + ((float)ray->column / data->mlx.win_width) * FOV; // get the angle of the ray for this pixel column
		ray->ray_dir_x = cos(ray->ray_angle * M_PI / 180); // convert angle to radian and get the x and y directions of the ray
		ray->ray_dir_y = sin(ray->ray_angle * M_PI / 180);
		ray->map_x = (int)data->player_data.x; // initial position
		ray->map_y = (int)data->player_data.y; // initial position
		ray->delta_dist_x = ft_fabs(1 / ray->ray_dir_x); // get how many x we go forward for one y traveled
		ray->delta_dist_y = ft_fabs(1 / ray->ray_dir_y); // get how many y we go up for one x traveled
		if (ray->ray_dir_x < 0)
		{
			ray->step_x = -1;
			ray->side_dist_x = (data->player_data.x - ray->map_x) * ray->delta_dist_x;
		}
		else
		{
			ray->step_x = 1;
			ray->side_dist_x = (ray->map_x + 1 - data->player_data.x) * ray->delta_dist_x;	
		}
		if (ray->ray_dir_y < 0)
		{
			ray->step_y = -1;
			ray->side_dist_y = (data->player_data.y - ray->map_y) * ray->delta_dist_y;
		}
		else
		{
			ray->step_y = 1;
			ray->side_dist_y = (ray->map_y + 1 - data->player_data.y) * ray->delta_dist_y;	
		}
}

static void	get_wall_dist(t_cub_data *data, t_ray_cast *ray)
{
	int		line_height;

	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player_data.x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player_data.y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	line_height = (int)(data->mlx.win_height / ray->perp_wall_dist);
	ray->line_draw_start = -line_height / 2 + data->mlx.win_height / 2;
	if (ray->line_draw_start < 0)
		ray->line_draw_start = 0;
	ray->line_draw_end = line_height / 2 + data->mlx.win_height / 2;
	if (ray->line_draw_end >= data->mlx.win_height)
		ray->line_draw_end = data->mlx.win_height - 1;
}

// for each columns of pixels, get the size of the wall with the player fov and draw it
void	raycasting(t_cub_data *data)
{
	t_ray_cast	ray;
	int			y;

	ray.column = 0;
	y = 0;
	while (ray.column < data->mlx.win_width)
	{
		compute_raycasting_values(data, &ray);
		dda_algorithm(data, &ray);
		get_wall_dist(data, &ray);
		int color = 255 / ray.perp_wall_dist; // need to change to put the texture of the wall
		y = ray.line_draw_start;
		while (y < ray.line_draw_end)
		{
			ft_mlx_pixel_put(data, ray.column, y, color);
			y++;
		}
		ray.column++;
	}
}
