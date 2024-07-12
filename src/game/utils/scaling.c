/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:06:50 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/12 16:07:30 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

int	scale_player_pos(float pos) // for minimap
{
	pos *= MINIMAP_SIZE / (RANGE * 2);
	pos += (RANGE * 2);
	return (pos);
}