/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:09:53 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/21 22:49:34 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void	dda_algorithm(t_cub_data *data, t_ray_cast *ray)
{
	char	map_value;

	ray->hit = false;
	ray->door_hit = false;
	while (ray->hit == false)
	{
		// checking which line is the shortest between x and y
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x; // updating the length of the x axis vector by adding the distance to hit a vertical line
			ray->map_x += ray->step_x; // x is shorter so we move along the x axis
			ray->side = 0; // hit vertical line
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y; // updating the length of the x axis vector by adding the distance to hit an horizontal line
			ray->map_y += ray->step_y; // y is shorter so we move along the y axis
			ray->side = 1; // hit horizontal line
		}
		map_value = data->settings.map[ray->map_y][ray->map_x];
		if (map_value == '1' || map_value == 'C')
			ray->hit = true;
		get_looking_door_values(ray, map_value);
	}
}

// compute initial values about the ray angle and how many steps
// the vector is traveling for one X step and one Y step and which
// wall will be checked every step.

static void	compute_raycasting_values_utils(t_cub_data *data, t_ray_cast *ray)
{
	if (ray->ray_dir_x < 0) // ray going left
	{
		ray->step_x = -1;
		ray->side_dist_x
			= (data->player_data.x - ray->map_x) * ray->delta_dist_x; // distance to travel to hit a vertical line
	}
	else // ray going right
	{
		ray->step_x = 1;
		ray->side_dist_x
			= (ray->map_x + 1 - data->player_data.x) * ray->delta_dist_x; // distance to travel to hit a vertical line
	}
	if (ray->ray_dir_y < 0) // ray going down
	{
		ray->step_y = -1;
		ray->side_dist_y
			= (data->player_data.y - ray->map_y) * ray->delta_dist_y; // distance to travel to hit an horizontal line
	}
	else // ray going up
	{
		ray->step_y = 1;
		ray->side_dist_y
			= (ray->map_y + 1 - data->player_data.y) * ray->delta_dist_y; // distance to travel to hit an horizontal line
	}
}

static void	compute_raycasting_values(t_cub_data *data, t_ray_cast *ray)
{
	float	fov_radian;

	fov_radian = FOV * (M_PI / 180); // get the fov in radian
	ray->ray_angle = data->player_data.angle - (fov_radian / 2)
		+ ((float)ray->column / data->mlx.win_width) * fov_radian; // get the angle of the ray to cast
	// these two lines are giving the coordinates of a vector having the angle of the ray
	ray->ray_dir_x = cos(ray->ray_angle); // get the x coordinate of the angle
	ray->ray_dir_y = sin(ray->ray_angle); // get the y coordinate of the angle
	ray->delta_dist_x = ft_fabs(1 / ray->ray_dir_x); // get how many x we go forward for one y traveled
	ray->delta_dist_y = ft_fabs(1 / ray->ray_dir_y); // get how many y we go up for one x traveled
	compute_raycasting_values_utils(data, ray);
}

static void	get_wall_dist(t_cub_data *data, t_ray_cast *ray)
{
	// get the distance between the player and the wall (perpendicular)
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player_data.x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player_data.y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->raw_wall_dist = ray->perp_wall_dist;
	ray->perp_wall_dist
		= ray->perp_wall_dist * cos(ray->ray_angle - data->player_data.angle); // correcting the fish eye effect
	ray->line_height = (int)(data->mlx.win_height / ray->perp_wall_dist); // get the line height of the column to draw
	ray->line_draw_start = -(ray->line_height) / 2 + data->mlx.win_height / 2; // get the starting point of the drawing with the line_height variable
	if (ray->line_draw_start < 0) // cheking bounds
		ray->line_draw_start = 0;
	ray->line_draw_end = ray->line_height / 2 + data->mlx.win_height / 2; // get theending point of the drawing with the line_height variable
	if (ray->line_draw_end >= data->mlx.win_height) // cheking bounds
		ray->line_draw_end = data->mlx.win_height - 1;
}

// for each columns of pixels, get the size of the wall with the player fov and draw it
void	raycasting(t_cub_data *data)
{
	data->ray.player_facing_door = false;
	data->ray.column = 0;
	while (data->ray.column < data->mlx.win_width)
	{
		data->ray.map_x = (int)data->player_data.x; // initial position
		data->ray.map_y = (int)data->player_data.y; // initial position
		compute_raycasting_values(data, &data->ray);
		dda_algorithm(data, &data->ray);
		get_wall_dist(data, &data->ray);
		put_wall_texture(data, &data->ray);
		data->ray.column++;
	}
}
