/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:56:17 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/03 20:17:18 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	handle_line(struct s_cub_data *cub_data, char *line, int fd)
{
	char	**line_elements;
	int		line_length;
	char	*croped;

	line_length = 0;
	if (!is_only_spaces(line)) //TODO: protect
	{
		line_elements = ft_split(line, ' ');
		line_length = double_array_len(line_elements);
		croped = line_elements[line_length - 1];
		line_elements[line_length - 1] = ft_strtrim(line_elements[line_length - 1], "\n");
		free(croped);
		if (cub_data->utils.settings_already_set != BASE_SETTINGS_REQUIRED)
		{
			if (double_array_len(line_elements) != 2)
			{
				free_double_array(line_elements);
				close (fd);
				cub_exit(BAD_SETTING_FORMAT, cub_data);
			}
			store_setting(cub_data, line_elements, fd);
		} // else store map
	}
}

// NEED TO CHECK IF
// 	- Base setting missing before setting the map
//	- If a setting is doubly present
//	- Bad format or can't open file path

void	extract_settings(struct s_cub_data *cub_data) //TODO: check if there is the right amount of settings
{
	int		fd;
	char	*line;

	fd = open(cub_data->utils.map_path, O_RDONLY);
	if (fd == -1)
	{
		cub_exit(OTHER, cub_data);
	}
	line = get_next_line(fd);
	while (line != NULL && cub_data->utils.settings_already_set != BASE_SETTINGS_REQUIRED) //TODO: remove
	{
		handle_line(cub_data, line, fd);
		free (line);
		line = NULL;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
