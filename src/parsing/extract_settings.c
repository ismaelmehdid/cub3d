/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:56:17 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/07 15:29:41 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void handle_error_and_exit(
	char **line_elements,
	int fd,
	t_cub_data *cub_data)
{
    free_double_array(&line_elements);
    close(fd);
    cub_exit(BAD_SETTING_FORMAT, cub_data);
}

static void handle_line(struct s_cub_data *cub_data, char *line, int fd)
{
	char	**elements;
	char	*last_element;
	int		line_length;

    if (!is_only_spaces(line))
    {
		elements = ft_split(line, ' ');
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
}

static void	handle_line_and_free(t_cub_data *cub_data, char *line, int fd)
{
	handle_line(cub_data, line, fd);
	free(line);
}

void	extract_settings(struct s_cub_data *cub_data)
{
	int		fd;
	char	*line;

	fd = open(cub_data->utils.map_path, O_RDONLY);
	if (fd == -1)
		cub_exit(OTHER, cub_data);
	line = get_next_line(fd);
	while (line && cub_data->utils.settings_already_set != BASE_SETTINGS_REQUIRED)
	{
		handle_line_and_free(cub_data, line, fd);
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
