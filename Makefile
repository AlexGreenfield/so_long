NAME = so_long
BONUS_NAME = so_long_bonus

# Libft
LIBFT = libft.a
LIBFT_DIR = ./lib/libft

# libmx
LIBMLX	:= ./lib/MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include

# Compiling libs and flags
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L $(LIBFT_DIR) -lft

# Mandatory sources and objects
SRCS_DIR = ./mandatory/
SRCS = so_long.c \
		args_parse.c \
		map_frees.c \
		args_utils.c \
		init_board.c \
		init_borders.c \
		init_tiles.c \
		init_pieces.c \
		free_board_textures.c \
		key_hooks.c \
		actions.c \

DIR_PREFIX = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(DIR_PREFIX:.c=.o)

# Bonus sources and objects
BONUS_DIR = ./bonus/
BONUS = so_long.c \
		args_parse.c \
		map_frees.c \
		args_utils.c \
		init_board.c \
		init_borders.c \
		init_tiles.c \
		init_pieces.c \
		free_board_textures.c \
		key_hooks.c \
		actions.c \
		bonus_ft.c \
		scale.c \

BONUS_PREFIX = $(addprefix $(BONUS_DIR), $(BONUS))
BONUS_OBJS = $(BONUS_PREFIX:.c=.o)

# Compilation
CC = cc
CFLAGS = -Werror -Wextra -Wall

# Colors for Makefile output
RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
BLUE   = \033[0;34m
RESET  = \033[0m

# Rules

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(LIBMLX)/build/libmlx42.a
	@echo "\n\n$(BLUE)Linking object files and libraries...$(RESET)\n\n"
	cc $(OBJS) -o $(NAME) -g3 $(LIBS)
	@echo "\n\n$(GREEN)Build complete!$(RESET)\n\n"

bonus : $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT_DIR)/$(LIBFT) $(LIBMLX)/build/libmlx42.a
	@echo "\n\n$(BLUE)Linking bonus object files and libraries...$(RESET)\n\n"
	cc $(BONUS_OBJS) -o $(BONUS_NAME) -g3 $(LIBS)
	@echo "\n\n$(GREEN)Build complete!$(RESET)\n\n"

$(LIBMLX)/build/libmlx42.a: $(LIBMLX)/CMakeLists.txt
	@echo "\n\n$(YELLOW)Compiling MinilibX...$(RESET)\n\n"
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4


$(LIBFT_DIR)/$(LIBFT):
	@echo "\n\n$(YELLOW)Compiling Libft...$(RESET)\n\n"
	@make -C $(LIBFT_DIR)

%.o: %.c
	@echo "\n\n$(BLUE)Compiling $<...$(RESET)\n\n"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@echo "\n\n$(RED)Cleaning object files...$(RESET)\n\n"
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -rf $(LIBMLX)/build
	@cd $(LIBFT_DIR) && make clean


fclean: clean
	@echo "\n\n$(RED)Cleaning all...$(RESET)\n\n"
	@rm -f $(NAME) $(BONUS)
	@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re

