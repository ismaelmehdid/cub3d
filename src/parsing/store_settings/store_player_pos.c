/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_player_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:57:57 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/07 16:33:52 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static void	check_if_player_pos(t_cub_data *cub_data, bool *set, int i, int j)
{
	if (is_player_spawn_pos(cub_data->settings.map[j][i]))
	{
		if (*set)
			cub_exit(MAP_DUPLICATED_PLAYER_SPAWN_POS, cub_data);
		cub_data->player_data.pole = cub_data->settings.map[j][i];
		cub_data->player_data.x = i;
		cub_data->player_data.y = j;
		*set = true;
	}
}

void	store_player_pos(t_cub_data *cub_data)
{
	int		i;
	int		j;
	bool	set;

	i = 0;
	j = 0;
	set = false;
	while (cub_data->settings.map[j])
	{
		while (cub_data->settings.map[j][i])
		{
			check_if_player_pos(cub_data, &set, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	if (!set)
		cub_exit(MAP_MISSING_PLAYER_SPAWN_POS, cub_data);
}