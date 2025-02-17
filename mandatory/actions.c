/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:20:50 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/17 22:23:18by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_tile(t_global *global, int y, int x)
{
	int			current_y;
	int			current_x;
	int			next_y;
	int			next_x;
	mlx_image_t	*image;

	current_y = global->map->p_y;
	current_x = global->map->p_x;
	next_y = global->map->p_y + y;
	next_x = global->map->p_x + x;
	global->map->map_array[current_y][current_x] = '0';
	image = select_tile(current_y + 1, current_x + 1, global->textures);
	mlx_image_to_window(global->mlx, image, WIDTH * current_x, HEIGHT * current_y);
	global->map->map_array[next_y][next_x] = 'P';
	global->map->p_y = next_y;
	global->map->p_x = next_x;
	mlx_image_to_window(global->mlx,global->textures->b_king_i, WIDTH * next_x, HEIGHT * next_y);
}
void	object_tile(t_global *global, int y, int x)
{
	int			current_y;
	int			current_x;
	int			next_y;
	int			next_x;
	mlx_image_t	*image;

	current_y = global->map->p_y;
	current_x = global->map->p_x;
	next_y = global->map->p_y + y;
	next_x = global->map->p_x + x;
	global->map->map_array[current_y][current_x] = '0';
	image = select_tile(current_y + 1, current_x + 1, global->textures);
	mlx_image_to_window(global->mlx, image, WIDTH * current_x, HEIGHT * current_y);
	global->map->map_array[next_y][next_x] = 'P';
	global->map->p_y = next_y;
	global->map->p_x = next_x;
	mlx_image_to_window(global->mlx,global->textures->b_king_i, WIDTH * next_x, HEIGHT * next_y);
	global->map->c--;
}
