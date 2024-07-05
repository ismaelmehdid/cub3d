NAME = cub3D

SRCS =	src/cub3D.c \
		src/parsing/parsing.c \
		src/parsing/extract_settings.c \
		src/utils/exit/exit.c \
		src/utils/exit/exit_messages/exit_messages1.c \
		src/utils/exit/exit_messages/exit_messages2.c \
		src/utils/exit/exit_messages/exit_messages3.c \
		src/utils/other/utils.c \
		src/utils/exit/free_all.c \
		src/parsing/store_settings/store_base_settings.c \
		src/parsing/store_settings/store_colors.c \
		src/parsing/store_settings/store_map.c \
		src/parsing/store_settings/store_textures.c \
		src/game/background.c \
		src/game/ft_pixel_put.c \
		include/get_next_line/get_next_line.c \
		include/get_next_line/get_next_line_utils.c \

OBJS_DIR = ./objs/
OBJS = $(patsubst srcs/%.c,$(OBJS_DIR)%.o,$(SRCS))

CC			= cc

LIBFT_DIR	= include/libft/libft.a

MLX_DIR		= include/minilibx-linux

MLX_LINK	= -L$(MLX_DIR) -Imlx

MATH_FLAG	= -lm

RM			= rm -rf

CLEAR 		= clear

CFLAGS		= -Wall -Wextra -Werror -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -sC include/libft
	@$(CC) $(CFLAGS) $(MATH_FLAG) $(OBJS) $(MLX_LINK) $(LIBFT_DIR) -o $(NAME)
	@$(CLEAR)
	@printf "\033[1;32m$(NAME) built successfully\033[0m\n"

$(OBJS_DIR)%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@printf "\033[1;36mCompiling $<\033[0m\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -sC include/libft
	@$(RM) $(OBJS_DIR)

fclean: clean
	make fclean -sC include/libft
	make clean -C include/minilibx-linux
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re