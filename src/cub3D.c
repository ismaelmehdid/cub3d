/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:12:46 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/08 17:58:17 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	debug_print_settings(t_cub_data	*cub_data)
{
	printf("Settings:\n");
	printf("East texture path: |%s|\n", cub_data->settings.e_texture_path);
	printf("North texture path: |%s|\n", cub_data->settings.n_texture_path);
	printf("South texture path: |%s|\n", cub_data->settings.s_texture_path);
	printf("West texture path: |%s|\n", cub_data->settings.w_texture_path);
	printf("Ceiling color: %u, %u, %u\n", cub_data->settings.ceiling_color->r, cub_data->settings.ceiling_color->g, cub_data->settings.ceiling_color->b);
	printf("Floor color: %u, %u, %u\n", cub_data->settings.floor_color->r, cub_data->settings.floor_color->g, cub_data->settings.floor_color->b);
	printf("===-----MAP-----===\n");
	int i = 0;
	while (cub_data->settings.map[i] != NULL)
	{
		printf("%s\n", cub_data->settings.map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_cub_data	cub_data;

	cub_data.utils.argc = argc;
	cub_data.utils.argv = argv;
	parsing(&cub_data);
	debug_print_settings(&cub_data);
	load_mlx(&cub_data);
	game_loop(&cub_data);
	return (0);
}