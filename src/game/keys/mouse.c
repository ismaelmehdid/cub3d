/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:26:35 by asyvash           #+#    #+#             */
/*   Updated: 2024/07/17 21:26:35 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void    turn_left_by_mouse(t_cub_data *data, int delta_x)
{
    float   radian_step;

    radian_step = (delta_x * MOUSE_SENSITIVITY) * M_PI / 180;
    data->player_data.angle -= radian_step;
    if (data->player_data.angle < 0)
        data->player_data.angle += 2 * M_PI;
}

static void    turn_right_by_mouse(t_cub_data *data, int delta_x)
{
    float   radian_step;

    radian_step = (delta_x * MOUSE_SENSITIVITY) * M_PI / 180;
    data->player_data.angle += radian_step;
    if (data->player_data.angle >= 2 * M_PI)
        data->player_data.angle -= 2 * M_PI;
}

static void    reset_mouse_to_center(t_cub_data *data)
{
    int center_x;
    int center_y;

    center_x = data->mlx.win_width / 2;
    center_y = data->mlx.win_height / 2;
    mlx_mouse_move(data->mlx.mlx_ptr, data->mlx.win_ptr, center_x, center_y);
}

int mouse_hook_turn(int x, int y, t_cub_data *data)
{
    int center_x;
    int center_y;
    int delta_x;

    center_x = data->mlx.win_width / 2;
    center_y = data->mlx.win_height / 2;
    if (x == center_x && y == center_y)
        return (0);
    delta_x = x - center_x;
    if (ft_abs(delta_x) > TRESHOLD)
    {
        if (delta_x < 0)
            turn_left_by_mouse(data, -delta_x);
        else if (delta_x > 0)
            turn_right_by_mouse(data, delta_x);
        reset_mouse_to_center(data);
    }
    return (0);
}

int	mouse_hook_shoot(int button, int x, int y, t_cub_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		data->gun.is_shooting = true;
		data->gun.shoot_frame = 0;
	}
	return (0);
}