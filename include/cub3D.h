/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:12:22 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/05 17:30:12 by marvin           ###   ########.fr       */
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

# define BASE_SETTINGS_REQUIRED 6 // TEXTURES PATH, FLOOR AND CEILING COLORS
# define ARGUMENTS_REQUIRED 2
# define FILE_EXTENTION ".cub"

//=== Data structures -----------------------------------------------------===//

typedef enum s_errors
{
	BAD_ARGUMENTS,
	MISSING_SETTING,
	E_BAD_FILE_PATH,
	N_BAD_FILE_PATH,
	S_BAD_FILE_PATH,
	W_BAD_FILE_PATH,
	DUPLICATED_SETTING,
	BAD_SETTING_FORMAT,
	BAD_COLOR_CODE_FORMAT,
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
	char	*map_path; // from argv (don't free!)
	int		settings_already_set;
}	t_cub_utils;

typedef struct s_cub_settings
{
	char			*e_texture_path;
	char			*n_texture_path;
	char			*s_texture_path;
	char			*w_texture_path;
	struct s_color	*ceiling_color;
	struct s_color	*floor_color;
	char			**map;
}	t_cub_settings;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits;
	int		line_len;
	int		edian;
}	t_mlx;

typedef struct s_cub_data
{
	struct s_cub_settings	settings;
	struct s_cub_utils		utils;
	struct s_mlx			mlx;
}	t_cub_data;

//=== Parsing -------------------------------------------------------------===//

void	parsing(struct s_cub_data *cub_data);
void	extract_settings(struct s_cub_data *cub_data);
void	store_setting(struct s_cub_data *cub_data, char **line_elements, int fd);
int		store_texture_path(t_cub_data *cub_data, char **line_elements, int fd);
int		store_colors(t_cub_data *cub_data, char **line_elements, int fd);

//=== Utils -------------------------------------------------------------===//

void	cub_exit(t_errors code, t_cub_data *cub_data);
void	free_everything(t_cub_data *cub_data);
int		ft_strcmp(const char *first, const char *second);
bool	is_only_spaces(char *line);
bool	is_space(char check);
int		double_array_len(char **array);
void	free_double_array(char **array);

#endif