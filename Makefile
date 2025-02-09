NAME = so_long

# Libft
LIBFT = libft.a
LIBFT_DIR = libft/

# MLX
MLX = libmlx.a
MLX_DIR = minilibx-linux/

# Sources and objects
SRCS = so_long.c
OBJS = $(SRCS:%.c=%.o)

# Compilation
CC = cc
CFLAGS = -Werror -Wextra -Wall

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(MLX_DIR)/$(MLX) $(LIBFT_DIR)/$(LIBFT)
	cc $(OBJS) -o $(NAME) -L $(MLX_DIR) -lmlx -L $(LIBFT_DIR) -lft -lXext -lX11

$(MLX_DIR)/$(MLX):
	@make -C $(MLX_DIR)

$(LIBFT_DIR)/$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@cd $(MLX_DIR) && make clean
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT_DIR) && make fclean
	@cd $(MLX_DIR) && make clean

re: fclean all

.PHONY: all clean fclean re
