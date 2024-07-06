/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:31:28 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/06 22:32:27 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static bool	check_neighbour_cases(char **map, int i, int j)
{
	if (j > 0 && map[j - 1][i] != '1' && map[j - 1][i] != ' ')
		return (false);
	if (map[j + 1] && map[j + 1][i] != '1' && map[j + 1][i] != ' ')
		return (false);
	if (i > 0 && map[j][i - 1] != '1' && map[j][i - 1] != ' ')
		return (false);
	if (map[j][i + 1] != '0' && map[j][i + 1] != ' ')
		return (false);
	if (j > 0 && i > 0 && map[j - 1][i - 1] != '1' && map[j - 1][i - 1] != ' ')
		return (false);
	if (j > 0 && map[j - 1][i + 1] != '1' && map[j - 1][i + 1] != ' ')
		return (false);
	if (map[j + 1] && i > 0 && map[j + 1][i - 1] != '1' && map[j + 1][i - 1] != ' ')
		return (false);
	if (map[j + 1] && map[j + 1][i + 1] != '1' && map[j + 1][i + 1] == ' ')
		return (false);
	return (true);
}

static bool	check_void_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == ' ')
				if (!check_neighbour_cases(map, i, j))
					return (false);
			i++;
		}
		i = 0;
		j++;
	}
	return (true);
}

static bool	is_map_closed(char **map)
{
	int	i;
	int	length;

	i = 0;
	length = double_array_len(map);
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			return (false);
		i++;
	}
	i = 0;
	while (map[length - 1][i])
	{
		if (map[length - 1][i] != '1' && map[length - 1][i] != ' ')
			return (false);
		i++;
	}
	return (check_void_spaces(map));
}

void	check_map_validity(t_cub_data *cub_data)
{
	if (!cub_data->settings.map)
		cub_exit(MAP_MISSING, cub_data);
	if (!is_map_closed(cub_data->settings.map))
		cub_exit(MAP_UNCLOSED, cub_data);
}