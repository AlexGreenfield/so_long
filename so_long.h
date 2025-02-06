/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:42:07 by acastrov          #+#    #+#             */
/*   Updated: 2025/02/06 20:55:20 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// User libraries
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

// X11 libraries
# include <X11/keysym.h>

// System libraries
# include <stdio.h>

// Macros
# define MALLOC_ERROR -1
# define X_ERROR -2
// System libraries
//#include <X11/Xlib.h>

// MLX struct
typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

#endif
