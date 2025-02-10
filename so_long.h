/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:42:07 by acastrov          #+#    #+#             */
/*   Updated: 2025/02/10 22:52:46 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// User libraries
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"

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
}	t_map;

// Parse args
int	check_ber(char *arg, t_map *map);
int	bad_ber(char *arg);
int	bad_size(t_map *map, char *arg);
int	allocate_map(t_map *map, char *arg);
int	bad_walls(t_map *map);

// Ags utils
int	len_set_char(char	*line);

// Free map
int	free_main_map(t_map *map, int flag);
int	free_map_array(t_map *map, int flag);

#endif
