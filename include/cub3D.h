/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <asyvash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:12:22 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/07 15:42:56 by asyvash          ###   ########.fr       */
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

# define EXPECTED_SETTING_PARTS 2 // identifier -> value
# define BASE_SETTINGS_REQUIRED 6 // TEXTURES PATH, FLOOR AND CEILING COLORS
# define ARGUMENTS_REQUIRED 2
# define FILE_EXTENTION ".cub"

//=== Keys --------------------------------------------------------------===//

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define left_arrow 65361
# define right_arrow 65363

//=== Data structures -----------------------------------------------------===//

typedef enum s_poles
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_poles;

typedef enum s_errors
{
	SUCCESS,
	MLX_ERROR,
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
	MAP_MISSING,
	MAP_UNCLOSED,
	MAP_WRONG_CHARACTER,
	MAP_MISSING_PLAYER_SPAWN_POS,
	MAP_DUPLICATED_PLAYER_SPAWN_POS,
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

typedef struct s_player_data
{
	int				x;
	int				y;
	char			pole;
}	t_player_data;

typedef struct s_cub_data
{
	struct s_cub_settings	settings;
	struct s_cub_utils		utils;
	struct s_mlx			mlx;
	struct s_player_data	player_data;
}	t_cub_data;

typedef struct s_map_params // Specific struct helping for map parsing
{
	char		**old_map;
	char		*line;
	int			fd;
    t_cub_data	*cub_data;
}               t_map_params;

//=== Parsing -------------------------------------------------------------===//

void	parsing(struct s_cub_data *cub_data);
void	extract_settings(struct s_cub_data *cub_data);
void	store_setting(struct s_cub_data *cub_data, char **elements, int fd);
int		store_texture_path(t_cub_data *cub_data, char **line_elements, int fd);
int		store_colors(t_cub_data *cub_data, char **line_elements, int fd);
void	store_map(t_cub_data *cub_data, char *line, int fd);
void	store_player_pos(t_cub_data *cub_data);
void	check_map_validity(t_cub_data *cub_data);

//=== Game ----------------------------------------------------------------===//

void    ft_mlx_pixel_put(t_cub_data *data, int x, int y, int color);
void	fill_background(t_cub_data *data, int x, int y);
int		key_hook(int keycode, t_cub_data **data);

//=== Utils ---------------------------------------------------------------===//

void	cub_exit(t_errors code, t_cub_data *cub_data);
void	free_everything(t_cub_data *cub_data);
int		ft_strcmp(const char *first, const char *second);
bool	is_only_spaces(char *line);
bool	is_space(char check);
int		double_array_len(char **array);
void	free_double_array(char ***array);

//=== Exit messages -------------------------------------------------------===//

void	bad_setting_format_error();
void	other_msg();
void	bad_file_extention_msg();
void	bad_arguments_msg(t_cub_data *cub_data);
void	duplicated_setting_error();
void	east_bad_file_path_error();
void	north_bad_file_path_error();
void	south_bad_file_path_error();
void	west_bad_file_path_error();
void	bad_color_code_format_error();
void	missing_setting_error();
void	bad_identifier_error();
void	missing_map_error();
void	unclosed_map_error();
void	mlx_error();
void	map_wrong_character_error();
void	map_duplicated_player_spawn_pos();
void	map_missing_player_spawn_pos();

#endif