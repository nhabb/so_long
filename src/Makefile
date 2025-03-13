# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-unused-variable

# Directories
LIBFT_DIR = ../libft
GNL_DIR = ../getnextline
PRINTF_DIR = ../printf
MLX_DIR = ../minilibx-linux

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a

# Source files
SRCS = parsing.c so_long.c map.c window.c loadimages.c check_map.c game_movement.c helpers.c keypress.c  $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
NAME = so_long

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME) -lmlx -L$(MLX_DIR) -lX11 -lXext
	@echo "$(NAME) created"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "libft.a created"

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR) > /dev/null
	@echo "libftprintf.a created"

$(MLX):
	@$(MAKE) -C $(MLX_DIR) > /dev/null
	@echo "libmlx.a created"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@$(MAKE) -C $(PRINTF_DIR) clean > /dev/null
	@if [ -f "$(MLX_DIR)/Makefile" ]; then $(MAKE) -C $(MLX_DIR) clean > /dev/null; fi
	@echo "Cleaned up object files"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@$(MAKE) -C $(PRINTF_DIR) fclean > /dev/null
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null
	@echo "Cleaned up executable and libraries"

re: fclean all

.PHONY: all clean fclean re
