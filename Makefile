NAME = cub3D

SRCS =	src/cub3D.c \
		src/parsing/parsing.c \
		src/parsing/extract_settings.c \
		src/utils/exit/exit.c \
		src/utils/other/utils.c \
		include/get_next_line/get_next_line.c \
		include/get_next_line/get_next_line_utils.c \

OBJS_DIR = objs/
OBJS = $(patsubst srcs/%.c,$(OBJS_DIR)%.o,$(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -L include/libft -L include/minilibx-linux

RM = rm -rf

CLEAR = clear

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./include/libft
	@$(MAKE) -C include/minilibx-linux
	@$(CC) $(CFLAGS) $(OBJS) ./include/libft/libft.a -o $(NAME)
	@$(CLEAR)
	@printf "\033[1;32m$(NAME) built successfully\033[0m\n"

$(OBJS_DIR)%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@printf "\033[1;36mCompiling $<\033[0m\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C ./include/libft fclean
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re