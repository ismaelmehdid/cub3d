/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:22:50 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/09 22:21:02 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

int map_player_pos_x(t_cub_data *cub_data, int x)
{
    return ((x * MINIMAP_SIZE) / cub_data->utils.map_width);
}

int map_player_pos_y(t_cub_data *cub_data, int y)
{
    return ((y * MINIMAP_SIZE) / cub_data->utils.map_height);
}


float	degToRad(int a)
{
    return (a * M_PI / 180.0);
}