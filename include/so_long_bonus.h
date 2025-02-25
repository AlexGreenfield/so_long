/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:27:06 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/25 17:18:49 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// User libraries
# include "../lib/libft/libft.h"

// MLX_42
# include "../lib/MLX42/include/MLX42/MLX42.h"

// System libraries
# include <X11/Xlib.h>
// Macros error
# define SUCCESS 0
# define MALLOC_ERROR -1
# define X_ERROR -2
# define FILE_ERROR -3

// Macros size
# define WIDTH 32
# define HEIGHT 32

// Map struct

typedef struct s_map
{
	char	**map_array;
	int		fd;
	int		y_size;
	int		x_size;
	int		c;
	int		fill_c;
	int		e;
	int		fill_e;
	int		p;
	int		p_x;
	int		p_y;
	int		int_scale;
}	t_map;

// Textures struct
typedef struct s_textures
{
	// Pieces
	mlx_texture_t	*b_king_t;
	mlx_image_t		*b_king_i;
	mlx_texture_t	*w_king_t;
	mlx_image_t		*w_king_i;
	mlx_texture_t	*b_tower_t;
	mlx_image_t		*b_tower_i;
	mlx_texture_t	*w_pawn_t;
	mlx_image_t		*w_pawn_i;
	// Borders
	mlx_texture_t	*b_top_t;
	mlx_image_t		*b_top_i;
	mlx_texture_t	*b_bot_t;
	mlx_image_t		*b_bot_i;
	mlx_texture_t	*b_left_t;
	mlx_image_t		*b_left_i;
	mlx_texture_t	*b_right_t;
	mlx_image_t		*b_right_i;
	mlx_texture_t	*c_top_l_t;
	mlx_image_t		*c_top_l_i;
	mlx_texture_t	*c_top_r_t;
	mlx_image_t		*c_top_r_i;
	mlx_texture_t	*c_bot_l_t;
	mlx_image_t		*c_bot_l_i;
	mlx_texture_t	*c_bot_r_t;
	mlx_image_t		*c_bot_r_i;
	// Tiles
	mlx_texture_t	*b_tile_t;
	mlx_image_t		*b_tile_i;
	mlx_texture_t	*w_tile_t;
	mlx_image_t		*w_tile_i;
	// Bonus pieces
	mlx_texture_t	*w_horse_t;
	mlx_image_t		*w_horse_i;
	mlx_texture_t	*b_kingb_t;
	mlx_image_t		*b_kingb_i;
}	t_textures;

typedef struct s_global
{
	t_map		*map;
	t_textures	*textures;
	mlx_t		*mlx;
}	t_global;

// Main
int			init_so_long(t_map *map);
int			end_game(t_map *map, mlx_t *mlx, t_textures *textures, int flag);
t_global	*init_global(t_map *map, mlx_t *mlx, t_textures *t_textures);


// Parse args
int			check_ber(char *arg, t_map *map);
int			allocate_map(t_map *map, char *arg);
int			bad_walls(t_map *map);
int			bad_items(t_map *map);
int			bad_flood(t_map *map);

// Ags utils
int			len_set_char(char	*line);
int			bad_ber(char *arg);
int			bad_size(t_map *map, char *arg);
void		fill(t_map *map, char **map_array, int y, int x);

// Free map
int			free_main_map(t_map *map, int flag);
int			free_map_array(t_map *map, int flag);

// Init Board
int			init_board(t_map *map, mlx_t *mlx, t_textures *textures);
int			init_walls(t_map *map, mlx_t *mlx, t_textures *textures);
int			init_floor(t_map *map, mlx_t *mlx, t_textures *textures);
int			init_objects(t_map *map, mlx_t *mlx, t_textures *textures);

// Init borders
int			init_borders(t_textures *textures);
int			assign_sides(mlx_t *mlx, t_textures *textures);
int			assign_corners(mlx_t *mlx, t_textures *textures);
mlx_image_t	*select_borders(int y, int x, t_map *map, t_textures *textures);
int			render_borders(t_map *map, mlx_t *mlx, t_textures *textures);

// Init tiles
void		init_tiles(t_textures *textures);
int			assign_tiles(mlx_t *mlx, t_textures *textures);
int			render_tiles(t_map *map, mlx_t *mlx, t_textures *textures);
mlx_image_t	*select_tile(int y, int x, t_textures *textures);

// Init pieces
void		init_pieces(t_textures *textures);
int			assign_pieces(mlx_t *mlx, t_textures *textures);
int			assign_bonus_pieces(mlx_t *mlx, t_textures *textures);
int			render_pieces(t_map *map, mlx_t *mlx, t_textures *textures);
mlx_image_t	*select_piece(int y, int x, t_map *map, t_textures *textures);

// Free board textures
int			delete_textures(mlx_t *mlx, t_textures *textures, int flag);
int			clean_board_textures(t_textures *textures);
int			clean_board_images(mlx_t *mlx, t_textures *textures);
int			clean_pieces_textures_images(mlx_t *mlx, t_textures *textures);
int			clean_bonus_pieces(mlx_t *mlx, t_textures *textures);


// Key hooks
void		key_hooks(mlx_key_data_t keydata, void *param);
void		mov_hook(t_global *global, int y, int x);

// Actions
void		empty_tile(t_global *global, int y, int x);
void	ft_printf_move(t_global *global);


// Bonus ft
void		idle(void *param);
void		disable_object(t_global *global);
int			my_abs(int n);
int			get_window_size(t_map *map);

// Resize bonus
void	resize_borders(t_textures *textures, int scale);
void	resize_pieces(t_textures *textures, int scale);
void	resize_tiles(t_textures *textures, int scale);



#endif
