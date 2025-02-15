/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:42:07 by acastrov          #+#    #+#             */
/*   Updated: 2025/02/15 13:22:22y alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// User libraries
# include "../lib/libft/libft.h"

// MLX_42
#include "../lib/MLX42/include/MLX42/MLX42.h"

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
	mlx_texture_t	*b_king_t;
	mlx_image_t		*b_king_i;
	mlx_texture_t	*board_t;
	mlx_image_t		*board_i;
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
int	init_board(t_map *map, mlx_t *mlx, t_textures *textures);
int	delete_textures(mlx_t *mlx, t_textures *textures, int flag);
int	init_textures(mlx_t *mlx, t_textures *textures);
int	render_board(t_map *map, mlx_t *mlx, t_textures *textures);

// Init so_long_utils

#endif
