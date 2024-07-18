/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imehdid <ismaelmehdid@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:12:22 by imehdid           #+#    #+#             */
/*   Updated: 2024/07/18 21:07:02 by imehdid          ###   ########.fr       */
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
# define NBR_OF_ERRORS 20

//=== Keys ----------------------------------------------------------------===//

# define KEY_COUNT 6
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define E 101

//=== Colors --------------------------------------------------------------===//

# define WHITE 0xffffff
# define GREY 0x808080
# define RED 0xff0000
# define BLACK 0x000000

//=== Minimap -------------------------------------------------------------===//

# define PLAYER_DOT_SIZE 4.0f
# define MINIMAP_SIZE 200.0f
# define RANGE 5.0f

//=== Player Settings -----------------------------------------------------===//

# define FOV 60.0f
# define SENSITIVITY 5
# define MOUSE_SENSITIVITY 0.015f
# define TRESHOLD 10
# define STRAFE_SPEED 0.1f
# define PLAYER_SPEED 0.2f
# define HIT_BOX 0.2f
# define MAX_DOOR_INTERACT_DISTANCE 1.7f

//=== Textures ------------------------------------------------------------===//

# define GUN_IMG_1 "./game_data/textures/std1.xpm"
# define GUN_IMG_2 "./game_data/textures/std2.xpm"
# define GUN_IMG_3 "./game_data/textures/std3.xpm"
# define GUN_IMG_4 "./game_data/textures/std4.xpm"
# define SHOOT_IMG_1 "./game_data/textures/shoot.xpm"
# define SHOOT_IMG_2 "./game_data/textures/shoot2.xpm"
# define SHOOT_IMG_3 "./game_data/textures/shoot3.xpm"
# define FRAME "./game_data/textures/minimap_frame.xpm"
# define DOOR "./game_data/textures/door.xpm"

//=== Data structures -----------------------------------------------------===//

// If you add an error code, make sure you update the array of pointers to the
// exit functions in 'init_exit_functions_array' function in the parsing.c file
// as well as updating the NBR_OF_ERRORS macro up in the .h file.

typedef void	(*t_exit_func_ptr)(void);

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
	NO_MAP_IN_FILE,
	OTHER
}	t_errors;

typedef enum e_key
{
	KEY_W,
	KEY_A,
	KEY_S,
	KEY_D,
	KEY_LEFT,
	KEY_RIGHT
}	t_key;

typedef struct s_keys
{
	bool	keys[KEY_COUNT];
}	t_keys;

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
	t_img	frame;
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
	t_exit_func_ptr			exit_funcs[NBR_OF_ERRORS];
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

typedef struct s_walls
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	t_img	door;
}	t_walls;

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
	int		side; // side of the wall hit 0 = vertical line, 1 = horizontal line
	float	perp_wall_dist;
	int		line_draw_start;
	int		line_draw_end;
	int		texture_x;
	int		texture_y;
	int		line_height;
	bool	door_hit;
	bool	player_facing_door;
	int		x_faced_door;
	int		y_faced_door;
	bool	hit;
}	t_ray_cast;

typedef struct s_cub_data
{
	struct s_cub_settings	settings;
	struct s_cub_utils		utils;
	struct s_mlx			mlx;
	struct s_player_data	player_data;
	struct s_ray_cast		ray;
	struct s_gun			gun;
	struct s_walls			walls;
	struct s_keys			keys;
}	t_cub_data;

typedef struct s_map_params // Specific struct helping for map parsing
{
	char		**old_map;
	char		*line;
	int			fd;
	t_cub_data	*cub_data;
}	t_map_params;

typedef struct s_bresenham
{
	int	dx_dy[2];
	int	sx_sy[2];
	int	err;
	int	e2;
}	t_bresenham;

//=== Parsing -------------------------------------------------------------===//

void	parsing(t_cub_data *cub_data);
void	extract_settings(t_cub_data *cub_data);
void	store_setting(t_cub_data *cub_data, char **elements, int fd);
int		store_texture_path(t_cub_data *cub_data, char **line_elements, int fd);
int		store_colors(
			t_cub_data *cub_data,
			char **line_elements,
			int fd,
			char id);
void	store_map(t_cub_data *cub_data, char *line, int fd);
void	store_player_pos(t_cub_data *cub_data);
void	check_map_validity(t_cub_data *cub_data);

//=== Game ----------------------------------------------------------------===//

void	game_loop(t_cub_data *data);
void	fill_background(t_cub_data *data, int x, int y);
void	draw_minimap(t_cub_data *data, int x, int y);
int		render(t_cub_data *cub_data);
void	raycasting(t_cub_data *data);
void	put_wall_texture(t_cub_data *data, t_ray_cast *ray);
void	weapon_logic(t_cub_data *data, int gun_frame);
void	get_looking_door_values(t_ray_cast *ray, char map_value);
void	minimap_frame(t_cub_data *data);
void	move_forward(t_cub_data *data);
void	move_backward(t_cub_data *data);
void	move_left(t_cub_data *data);
void	move_right(t_cub_data *data);
void	turn_left(t_cub_data *data);
void	turn_right(t_cub_data *data);
void	handle_keys(t_cub_data *data);
void	open_or_close_door(t_cub_data *data);

//=== Utils ---------------------------------------------------------------===//

void	cub_exit(t_errors code, t_cub_data *cub_data);
void	free_everything(t_cub_data *cub_data);
int		ft_strcmp(const char *first, const char *second);
bool	is_only_spaces(char *line);
bool	is_space(char check);
int		double_array_len(char **array);
void	free_double_array(char ***array);
bool	is_player_spawn_pos(char c);
void	reach_eof_to_avoid_leaks(char *line, int fd);
void	load_mlx(t_cub_data *data);
void	load_door_img(t_cub_data *data);
void	set_null_to_ptrs(t_cub_data *data);
int		scale_player_pos(float pos);
void	ft_mlx_pixel_put(t_cub_data *data, int x, int y, int color);
void	bresenham_line_draw(t_cub_data *data, int x0_y0[2], int x1_y1[2]);
long	get_current_time_in_ms(void);
float	deg_to_rad(int a);
int		key_press(int keycode, t_cub_data *data);
int		key_release(int keycode, t_cub_data *data);
int		mouse_hook_shoot(int button, int x, int y, t_cub_data *data);
int		mouse_hook_turn(int x, int y, t_cub_data *data);
float	ft_fabs(float value);
int		ft_abs(int value);

//=== Exit messages -------------------------------------------------------===//

void	bad_setting_format_error(void);
void	other_msg(void);
void	bad_file_extention_msg(void);
void	bad_arguments_msg(void);
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
void	map_missing(void);
void	cub_exit_success(void);

#endif