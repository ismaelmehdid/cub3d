/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:10:04 by asyvash           #+#    #+#             */
/*   Updated: 2024/07/05 21:10:04 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

float	degToRad(int a)
{
    return (a * M_PI / 180.0);
}

static void move_forward_back(int keycode, t_cub_data **data)
{
    if (keycode == W)
    {
        (*data)->player_data.x += PLAYER_SPEED * sin((*data)->player_data.angle);
        (*data)->player_data.y -= PLAYER_SPEED * cos((*data)->player_data.angle);
    }
    else if (keycode == S)
    {
        (*data)->player_data.x -= PLAYER_SPEED * sin((*data)->player_data.angle);
        (*data)->player_data.y += PLAYER_SPEED * cos((*data)->player_data.angle);
    }
	render(*data);
}

static void move_left_right(int keycode, t_cub_data **data)
{
	float	strafe_speed;

	strafe_speed = 0.05;
    if (keycode == A)
    {
        (*data)->player_data.x -= strafe_speed * cos((*data)->player_data.angle);
        (*data)->player_data.y -= strafe_speed * sin((*data)->player_data.angle);

    }
    else if (keycode == D)
    {
        (*data)->player_data.x += strafe_speed * cos((*data)->player_data.angle);
        (*data)->player_data.y += strafe_speed * sin((*data)->player_data.angle);
    }
	render(*data);
}


static void    turn_left_right(int keycode, t_cub_data **data)
{
    float radian_step = 5 * M_PI / 180; // convert 5 degrees to radians
    if (keycode == left_arrow)
    {
        (*data)->player_data.angle -= radian_step;
        if ((*data)->player_data.angle < 0)
            (*data)->player_data.angle += 2 * M_PI;
    }
    else if (keycode == right_arrow)
    {
        (*data)->player_data.angle += radian_step;
        if ((*data)->player_data.angle >= 2 * M_PI)
            (*data)->player_data.angle -= 2 * M_PI;
    }
	render(*data);
}

int key_hook(int keycode, t_cub_data **data)
{
    if (keycode == ESC)
        cub_exit(SUCCESS, *data);
    else if (keycode == W || keycode == S)
        move_forward_back(keycode, data);
    else if (keycode == A || keycode == D)
        move_left_right(keycode, data);
    else if (keycode == left_arrow || keycode == right_arrow)
        turn_left_right(keycode, data);
    return (0);
}
