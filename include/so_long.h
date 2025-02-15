/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:27:06 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/15 17:35:04 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
}	t_map;

// Textures struct
typedef struct s_textures
{
	// Pieces
	mlx_texture_t	*b_king_t;
	mlx_image_t		*b_king_i;

	// Borders
	mlx_texture_t	*border_top_t;
	mlx_image_t		*border_top_i;
	mlx_texture_t	*border_bottom_t;
	mlx_image_t		*border_bottom_i;
	mlx_texture_t	*border_left_t;
	mlx_image_t		*border_left_i;
	mlx_texture_t	*border_right_t;
	mlx_image_t		*border_right_i;
	mlx_texture_t	*corner_top_left_t;
	mlx_image_t		*corner_top_left_i;
	mlx_texture_t	*corner_top_right_t;
	mlx_image_t		*corner_top_right_i;
	mlx_texture_t	*corner_bottom_left_t;
	mlx_image_t		*corner_bottom_left_i;
	mlx_texture_t	*corner_bottom_right_t;
	mlx_image_t		*corner_bottom_right_i;
	
	// Tiles
	mlx_texture_t	*b_tile_t;
	mlx_image_t		*b_tile_i;
	mlx_texture_t	*w_tile_t;
	mlx_image_t		*w_tile_i;

	// Icon
	mlx_image_t		*icon;
}	t_textures;

// Main
int		init_so_long(t_map *map);

// Parse args
int		check_ber(char *arg, t_map *map);
int		allocate_map(t_map *map, char *arg);
int		bad_walls(t_map *map);
int		bad_items(t_map *map);
int		bad_flood(t_map *map);

// Ags utils
int		len_set_char(char	*line);
int		bad_ber(char *arg);
int		bad_size(t_map *map, char *arg);
void	fill(t_map *map, char **map_array, int y, int x);

// Free map
int		free_main_map(t_map *map, int flag);
int		free_map_array(t_map *map, int flag);

// Init Board
int		init_board(t_map *map, mlx_t *mlx, t_textures *textures);
int		init_textures(mlx_t *mlx, t_textures *textures);
int		render_board(t_map *map, mlx_t *mlx, t_textures *textures);

// Init borders
int		init_walls(t_map *map, mlx_t *mlx, t_textures *textures);
int		init_borders(t_textures *textures);
int		assign_sides(mlx_t *mlx, t_textures *textures);
int		assign_corners(mlx_t *mlx, t_textures *textures);
int		render_borders(t_map *map, mlx_t *mlx, t_textures *textures);
int		put_border(int y, int x, mlx_t *mlx, t_map *map, t_textures *textures);

// Init tiles
void	init_tiles(t_textures *textures);

// Free board textures
int		delete_textures(mlx_t *mlx, t_textures *textures, int flag);

// Init so_long_utils


#endif
