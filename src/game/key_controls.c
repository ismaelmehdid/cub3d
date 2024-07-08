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

int	key_hook(int keycode, t_cub_data **data)
{
	if (keycode == ESC)
		cub_exit(SUCCESS, *data);
	else if (keycode == W)
		(*data)->player_data.y += PLAYER_SPEED;
	else if (keycode == S)
		(*data)->player_data.y -= PLAYER_SPEED;
	else if (keycode == A)
		(*data)->player_data.x -= PLAYER_SPEED;
	else if (keycode == D)
		(*data)->player_data.x += PLAYER_SPEED;
    /*if (keycode == W)
    if (keycode == A)
    if (keycode == S)
    if (keycode == D)
    if (keycode == left_arrow)
    if (keycode == right_arrow)*/
	return (0);
}