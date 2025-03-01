/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:30:40 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/16 16:45:32 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_exit(t_errors code, t_cub_data *cub_data)
{
	if (code < sizeof(cub_data->utils.exit_funcs)
		/ sizeof(cub_data->utils.exit_funcs[0]))
	{
		cub_data->utils.exit_funcs[code]();
	}
	free_everything(cub_data);
	if (code == SUCCESS)
		exit(SUCCESS);
	exit(EXIT_FAILURE);
}
