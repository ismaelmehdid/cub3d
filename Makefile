NAME = cub3D

SRCS =  src/cub3D.c \
        src/parsing/parsing.c \
        src/parsing/check_map_validity.c \
        src/parsing/extract_settings.c \
        src/utils/exit/exit.c \
        src/utils/exit/exit_messages/exit_messages1.c \
        src/utils/exit/exit_messages/exit_messages2.c \
        src/utils/exit/exit_messages/exit_messages3.c \
        src/utils/exit/exit_messages/exit_messages4.c \
		src/utils/exit/exit_messages/exit_messages5.c \
        src/utils/other/utils.c \
		src/utils/other/utils2.c \
        src/utils/exit/free_all.c \
        src/parsing/store_settings/store_base_settings.c \
        src/parsing/store_settings/store_player_pos.c \
        src/parsing/store_settings/store_colors.c \
        src/parsing/store_settings/store_map.c \
        src/parsing/store_settings/store_textures.c \
        src/game/render.c \
        src/game/game_algorithm.c \
        src/game/graphics/floor_and_ceiling.c \
		src/game/graphics/minimap.c \
		src/game/graphics/raycasting.c \
		src/game/graphics/walls_textures.c \
        src/game/graphics/weapon.c \
        src/game/utils/put_pixels.c \
		src/game/utils/load_mlx.c \
		src/game/utils/utils.c \
        src/game/keys/key_controls.c \
        src/game/keys/process_motion.c \
        src/game/keys/process_turn.c \
        src/game/keys/mouse.c \
        include/get_next_line/get_next_line.c \
        include/get_next_line/get_next_line_utils.c \

OBJS_DIR = ./objs/
OBJS = $(patsubst src/%.c,$(OBJS_DIR)%.o,$(SRCS))

CC = cc -g

LIBFT_DIR = include/libft/libft.a

MLX_DIR = include/minilibx-linux

MLX_LINK = -L$(MLX_DIR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm

RM = rm -rf

CLEAR = clear

CFLAGS = -Wall -Wextra -Werror -Iinclude

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LINK) $(LIBFT_DIR) -o $(NAME)
	$(CLEAR)
	@printf "\033[1;32m$(NAME) built successfully\033[0m\n"

$(OBJS_DIR)%.o: src/%.c
	@mkdir -p $(dir $@)
	@printf "\033[1;36mCompiling $<\033[0m\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR):
	$(MAKE) -sC include/libft

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) clean -sC include/libft
	$(RM) $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -sC include/libft
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
