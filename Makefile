NAME = so_long

LIBFT = libft.a

LIBFTDIR = ./libft

MLX = libmlx.a

MLX_DIR = minilibx-linux/

SRCS = test.c \

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Werror -Wextra -Wall

CC = cc

all: $(NAME)

$(NAME): $(OBJ) $(MLX_DIR)/$(MLX) $(MLX_DIR)/$(MLX)
	cc $(OBJS) -o $(NAME) -L minilibx-linux/ -lmlx -lXext -lX11

$(MLX_DIR)/Makefile:
	git submodule update --init --recursive

$(LIBFT_DIR)/Makefile:
	git submodule update --init --recursive

modules: $(LIBFT_DIR)/Makefile $(MLX_DIR)/Makefile
	git submodule update --init --recursive

$(MLX_DIR)/$(MLX):
	@make -C $(MLX_DIR)

$(LIBFTDIR)/$(LIBFT):
	@make -C $(LIBFTDIR) CFLAGS="$(CFLAGS)"

clean:
	@rm -f $(OBJS)
	@cd $(MLX_DIR) && make clean
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	@cd $(MLX_DIR) && make clean

re: fclean all

.PHONY: all clean fclean re
