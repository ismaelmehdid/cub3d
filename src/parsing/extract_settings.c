/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:56:17 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/02 23:18:59 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	handle_line(struct s_cub_data *cub_data, char *line)
{
		(void)cub_data;
		(void)line;
		//TODO:
}

void	extract_settings(struct s_cub_data *cub_data)
{
	int		fd;
	char	*line;

	fd = open(cub_data->utils.map_path, O_RDONLY);
	if (fd == -1)
	{
		cub_exit(OTHER, cub_data);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		free (line);
		line = NULL;
	}
}