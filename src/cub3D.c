/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:12:46 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/07 16:02:38 by asyvash          ###   ########.fr       */
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

static void	game_loop(t_cub_data *data)
{
	game_algorithm(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->mlx.img, 0, 0);
	mlx_hook(data->mlx.win_ptr, 2, 1L << 0, (void *)key_hook, &data);
	mlx_hook(data->mlx.win_ptr, 17, 1L << 17, (void *)free_everything, &(*data));
	mlx_loop(data->mlx.mlx_ptr);
}

static void	load_mlx(t_cub_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		cub_exit(MLX_ERROR, data);
	mlx_get_screen_size(data->mlx.mlx_ptr,
		&data->mlx.width, &data->mlx.height);
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
		data->mlx.width, data->mlx.height, "cub3D");
	if (!data->mlx.win_ptr)
	{
		free(data->mlx.mlx_ptr);
		cub_exit(MLX_ERROR, data);
	}
	data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, data->mlx.width,
		data->mlx.height);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, 
		&data->mlx.bits, &data->mlx.line_len, &data->mlx.edian);
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