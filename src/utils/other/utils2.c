/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:34:06 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/16 16:45:47 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

bool	is_player_spawn_pos(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	reach_eof_to_avoid_leaks(char *line, int fd)
{
	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			return ;
		free(line);
		line = get_next_line(fd);
	}
}
