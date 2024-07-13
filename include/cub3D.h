/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:12:22 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/13 17:12:58 by imehdid          ###   ########.fr       */
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
# include <sys/time.h>

//=== Macros --------------------------------------------------------------===//

# define EXPECTED_SETTING_PARTS 2 // identifier -> value
# define BASE_SETTINGS_REQUIRED 6 // TEXTURES PATH, FLOOR AND CEILING COLORS
# define ARGUMENTS_REQUIRED 2
# define FILE_EXTENTION ".cub"

//=== Keys ----------------------------------------------------------------===//

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

//=== Colors --------------------------------------------------------------===//

# define WHITE 0xffffff
# define GREY 0x808080
# define RED 0xff0000

//=== Minimap -------------------------------------------------------------===//

# define PLAYER_DOT_SIZE 4
# define MINIMAP_SIZE 200
# define RANGE 5

//=== Player Settings -----------------------------------------------------===//

# define FOV 60.0f
# define SENSITIVITY 5
# define STRAFE_SPEED 0.5f
# define PLAYER_SPEED 0.5f

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

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_gun
{
	t_img	std;
	t_img	std2;
	t_img	std3;
	t_img	std4;
	t_img	shoot1;
	t_img	shoot2;
	t_img	shoot3;
	t_img	*shoot_images[5];
	t_img	*gun_images[2];
	bool	is_shooting;
	int		shoot_frame;
	long	last_shoot_time;
}	t_gun;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_minimap
{
	int		cell_width;
	int		cell_height;
}	t_minimap_data;

typedef struct s_cub_utils
{
	int						argc;
	char					**argv;
	char					*map_path;
	int						settings_already_set;
	int						map_width;
	int						map_height;
	struct s_minimap		minimap;
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
	int		win_height;
	int		win_width;
	int		bits;
	int		line_len;
	int		edian;
}	t_mlx;

typedef struct s_player_data
{
	float			x;
	float			y;
	float			mm_x;
	float			mm_y;
	float			angle;
	char			pole;
}	t_player_data;

typedef struct s_cub_data
{
	struct s_cub_settings	settings;
	struct s_cub_utils		utils;
	struct s_mlx			mlx;
	struct s_player_data	player_data;
	struct s_gun			gun;
}	t_cub_data;

typedef struct s_map_params // Specific struct helping for map parsing
{
	char		**old_map;
	char		*line;
	int			fd;
	t_cub_data	*cub_data;
}	t_map_params;

typedef struct s_ray_cast
{
	int		column; // the pixel column we are casting the ray on	
	float	ray_angle;
	float	ray_dir_x;
	float	ray_dir_y;
	int		map_x;
	int		map_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	int		step_x;
	int		step_y;
	int		side; // which side of the wall has been hit 0 = vertical line, 1 = horizontal line (usefull for shadow)
	float	perp_wall_dist;
	int		line_draw_start;
	int		line_draw_end;
}	t_ray_cast;

typedef struct s_bresenham
{
	int	dx_dy[2];
	int	sx_sy[2];
	int	err;
	int	e2;
}	t_bresenham;

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

void	game_loop(t_cub_data *data);
void	ft_mlx_pixel_put(t_cub_data *data, int x, int y, int color);
void	fill_background(t_cub_data *data, int x, int y);
void	draw_minimap(t_cub_data *data);
int		render(t_cub_data *cub_data);
void	raycasting(t_cub_data *data);
void	weapon_logic(t_cub_data *data, int gun_frame);
void	minimap_frame(t_cub_data *data);

//=== Utils ---------------------------------------------------------------===//

void	cub_exit(t_errors code, t_cub_data *cub_data);
void	free_everything(t_cub_data *cub_data);
int		ft_strcmp(const char *first, const char *second);
bool	is_only_spaces(char *line);
bool	is_space(char check);
int		double_array_len(char **array);
void	free_double_array(char ***array);
bool	is_player_spawn_pos(char c);
void	load_mlx(t_cub_data *data);
void	set_null_to_ptrs(t_cub_data *data);
int		scale_player_pos(float pos);
void	bresenham_line_draw(t_cub_data *data, int x0_y0[2], int x1_y1[2]);
long	get_current_time_in_ms(void);
float	deg_to_rad(int a);
int		key_hook(int keycode, t_cub_data **data);
int		mouse_hook(int button, int x, int y, t_cub_data *data);
float	ft_fabs(float value);

//=== Exit messages -------------------------------------------------------===//

void	bad_setting_format_error(void);
void	other_msg(void);
void	bad_file_extention_msg(void);
void	bad_arguments_msg(t_cub_data *cub_data);
void	duplicated_setting_error(void);
void	east_bad_file_path_error(void);
void	north_bad_file_path_error(void);
void	south_bad_file_path_error(void);
void	west_bad_file_path_error(void);
void	bad_color_code_format_error(void);
void	missing_setting_error(void);
void	bad_identifier_error(void);
void	missing_map_error(void);
void	unclosed_map_error(void);
void	mlx_error(void);
void	map_wrong_character_error(void);
void	map_duplicated_player_spawn_pos(void);
void	map_missing_player_spawn_pos(void);

#endif