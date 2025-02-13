/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:42:07 by acastrov          #+#    #+#             */
/*   Updated: 2025/02/13 20:17:15 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// User libraries
# include "../lib/libft/libft.h"

// X11 libraries
# include <X11/keysym.h>

// System libraries
# include <stdio.h>

// Macros
# define SUCCESS 0
# define MALLOC_ERROR -1
# define X_ERROR -2
# define FILE_ERROR -3

// System libraries
# include <X11/Xlib.h>

// MLX struct
typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

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

// Main
int	init_so_long(t_map *map);

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

// Init so_long_utils
int		handle_input(int keysym, t_mlx_data *mlx);
int		button_press(int button, int x, int y, t_mlx_data *mlx);
int		close_window(t_mlx_data *mlx);

#endif
