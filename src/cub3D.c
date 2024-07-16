/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:12:46 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/16 16:49:41 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_cub_data	cub_data;

	cub_data.utils.argc = argc;
	cub_data.utils.argv = argv;
	parsing(&cub_data);
	load_mlx(&cub_data);
	game_loop(&cub_data);
	return (0);
}
