/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:12:22 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/02 23:20:26 by imehdid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//=== Includes ------------------------------------------------------------===//

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

//=== Macros --------------------------------------------------------------===//

# define ARGUMENTS_REQUIRED 2
# define FILE_EXTENTION ".cub"

//=== Data structures -----------------------------------------------------===//

typedef enum s_errors
{
	BAD_ARGUMENTS,
	MISSING_SETTING,
	BAD_FILE_EXTENTION,
	BAD_IDENTIFIER,
	MAP_UNCLOSED,
	MAP_WRONG_CHARACTER,
	MAP_MISSING_CHARACTER,
	OTHER
}	t_errors;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_cub_utils
{
	int		argc;
	char	**argv;
	char	*map_path;
}	t_cub_utils;

typedef struct s_cub_settings
{
	int				e_texture_fd;
	int				n_texture_fd;
	int				s_texture_fd;
	int				w_texture_fd;
	struct s_color	ceiling_color;
	struct s_color	floor_color;
	char			**usr_arguments;
	char			**map;
}	t_cub_settings;

typedef struct s_cub_data
{
	struct s_cub_settings	settings;
	struct s_cub_utils		utils;
}	t_cub_data;

//=== Parsing -------------------------------------------------------------===//

void	parsing(struct s_cub_data *cub_data);
void	extract_settings(struct s_cub_data *cub_data);

//=== Utils -------------------------------------------------------------===//

void	cub_exit(t_errors code, t_cub_data *cub_data);
int		ft_strcmp(const char *first, const char *second);
bool	is_only_spaces(char *line);
bool	is_space(char check);

#endif