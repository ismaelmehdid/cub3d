/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:31:28 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/13 17:19:21 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static bool	check_neighbours(char **map, int i, int j, int map_height)
{
	int	y;
	int	x;
	int	ni;
	int	nj;

	y = -1;
	while (y <= 1)
	{
		x = -1;
		while (x <= 1)
		{
			ni = i + x;
			nj = j + y;
			if (nj < 0 || nj >= map_height || ni < 0
				|| ni >= ft_strlen(map[nj]) || !map[nj][ni]
				|| map[nj][ni] == ' ')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

static void	check_map_closed(t_cub_data *cub_data, char **map)
{
	int	i;
	int	j;
	int	map_height;

	i = 0;
	j = 0;
	map_height = double_array_len(map);
	while (j < map_height)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != ' '
				&& !is_player_spawn_pos(map[j][i]))
				cub_exit(MAP_WRONG_CHARACTER, cub_data);
			if (map[j][i] == '0' || is_player_spawn_pos(map[j][i]))
			{
				if (!check_neighbours(map, i, j, map_height))
					cub_exit(MAP_UNCLOSED, cub_data);
			}
			i++;
		}
		j++;
	}
}

void	check_map_validity(t_cub_data *cub_data)
{
	if (!cub_data->settings.map)
		cub_exit(MAP_MISSING, cub_data);
	check_map_closed(cub_data, cub_data->settings.map);
}
