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

static void move_forward_back(int keycode, t_cub_data **data)
{
    if (keycode == W)
    {
        (*data)->player_data.y -= PLAYER_SPEED * \
            sin(degToRad((*data)->player_data.angle));
        (*data)->player_data.x += PLAYER_SPEED * \
            cos(degToRad((*data)->player_data.angle));
    }
    else if (keycode == S)
    {
        (*data)->player_data.y += PLAYER_SPEED * \
            sin(degToRad((*data)->player_data.angle));
        (*data)->player_data.x -= PLAYER_SPEED * \
            cos(degToRad((*data)->player_data.angle));
    }
}

static void move_left_right(int keycode, t_cub_data **data)
{
    if (keycode == A)
    {
        (*data)->player_data.y += PLAYER_SPEED * \
            cos(degToRad((*data)->player_data.angle));
        (*data)->player_data.x += PLAYER_SPEED * \
            sin(degToRad((*data)->player_data.angle));
    }
    else if (keycode == D)
    {
        (*data)->player_data.y -= PLAYER_SPEED * \
            cos(degToRad((*data)->player_data.angle));
        (*data)->player_data.x -= PLAYER_SPEED * \
            sin(degToRad((*data)->player_data.angle));
    }
}


static void    turn_left_right(int keycode, t_cub_data **data)
{
    if (keycode == left_arrow)
    {
        (*data)->player_data.angle += 5;
        if ((*data)->player_data.angle > 360)
            (*data)->player_data.angle -= 360;
    }
    else if (keycode == right_arrow)
    {
        (*data)->player_data.angle -= 5;
        if ((*data)->player_data.angle < 0)
            (*data)->player_data.angle += 360;
    }
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
