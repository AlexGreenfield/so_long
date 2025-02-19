/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:20:50 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/19 21:03:28 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	empty_tile(t_global *global, int y, int x)
{
	int			c_y;
	int			c_x;
	int			next_y;
	int			next_x;
	mlx_image_t	*image;

	c_y = global->map->p_y;
	c_x = global->map->p_x;
	next_y = global->map->p_y + y;
	next_x = global->map->p_x + x;
	global->map->map_array[c_y][c_x] = '0';
	image = select_tile(c_y + 1, c_x + 1, global->textures);
	mlx_image_to_window(global->mlx, image, WIDTH * c_x, HEIGHT * c_y);
	global->map->map_array[next_y][next_x] = 'P';
	global->map->p_y = next_y;
	global->map->p_x = next_x;
	mlx_image_to_window(global->mlx, global->textures->b_king_i,
		WIDTH * next_x, HEIGHT * next_y);
	ft_printf_move();
}

void	ft_printf_move(void)
{
	static int	i;

	ft_printf("%d\n", ++i);
}
