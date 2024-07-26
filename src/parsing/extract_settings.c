/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:56:17 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/26 16:25:57 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	handle_error_and_exit(
	char **line_elements,
	int fd,
	t_cub_data *cub_data)
{
	free_double_array(&line_elements);
	reach_eof_to_avoid_leaks(NULL, fd);
	close(fd);
	cub_exit(BAD_SETTING_FORMAT, cub_data);
}

static void	handle_line(
	struct s_cub_data *cub_data,
	char *line,
	int fd,
	int line_length)
{
	char	**elements;
	char	*last_element;

	elements = ft_split(line, ' ');
	free(line);
	if (!elements)
		handle_error_and_exit(elements, fd, cub_data);
	line_length = double_array_len(elements);
	last_element = elements[line_length - 1];
	elements[line_length - 1] = ft_strtrim(elements[line_length - 1], "\n");
	if (!elements[line_length - 1])
	{
		free(last_element);
		handle_error_and_exit(elements, fd, cub_data);
	}
	free(last_element);
	if (cub_data->utils.settings_already_set != BASE_SETTINGS_REQUIRED)
	{
		if (line_length != EXPECTED_SETTING_PARTS)
			handle_error_and_exit(elements, fd, cub_data);
		store_setting(cub_data, elements, fd);
	}
}

void	extract_settings(struct s_cub_data *cub_data)
{
	int		fd;
	char	*line;

	fd = open(cub_data->utils.map_path, O_RDONLY);
	if (fd == -1)
		cub_exit(OTHER, cub_data);
	line = get_next_line(fd);
	while (line
		&& cub_data->utils.settings_already_set != BASE_SETTINGS_REQUIRED)
	{
		if (!is_only_spaces(line))
			handle_line(cub_data, line, fd, 0);
		else
			free(line);
		line = get_next_line(fd);
	}
	if (!line && cub_data->utils.settings_already_set != BASE_SETTINGS_REQUIRED)
	{
		close (fd);
		cub_exit(MISSING_SETTING, cub_data);
	}
	store_map(cub_data, line, fd);
	close(fd);
}
