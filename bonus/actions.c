/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:20:50 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/24 20:40:57 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	empty_tile(t_global *global, int y, int x)
{
	int			c_y;
	int			c_x;
	int			next_y;
	int			next_x;

	c_y = global->map->p_y;
	c_x = global->map->p_x;
	next_y = global->map->p_y + y;
	next_x = global->map->p_x + x;
	global->map->p_y = next_y;
	global->map->p_x = next_x;
	if (global->map->map_array[next_y][next_x] == 'C')
		disable_object(global);
	global->map->map_array[c_y][c_x] = '0';
	global->map->map_array[next_y][next_x] = 'P';
	global->map->p_x = next_x;
	ft_printf_move(global);
}

void	ft_printf_move(t_global *global)
{
	static int			i;
	char				*string;
	static mlx_image_t	*counter;

	i++;
	if (counter)
		mlx_delete_image(global->mlx, counter);
	string = ft_itoa(i);
	counter = mlx_put_string(global->mlx, string, 16, 0);
	ft_printf("%d\n", i);
}
