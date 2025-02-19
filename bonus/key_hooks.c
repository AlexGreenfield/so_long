/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:03:45 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/19 19:54:12 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		mov_hook(global, -1, 0);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		mov_hook(global, -1, 0);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		mov_hook(global, 0, -1);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		mov_hook(global, 0, -1);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		mov_hook(global, 1, 0);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		mov_hook(global, 1, 0);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		mov_hook(global, 0, 1);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		mov_hook(global, 0, 1);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(global->mlx);
}

void	mov_hook(t_global *global, int y, int x)
{
	char		next_char;
	int			next_y;
	int			next_x;

	next_y = global->map->p_y + y;
	next_x = global->map->p_x + x;
	next_char = global->map->map_array[next_y][next_x];
	if (next_char == '1')
		return ;
	if (next_char == '0')
		empty_tile(global, y, x);
	if (next_char == 'C')
	{
		empty_tile(global, y, x);
		global->map->c--;
	}
	if (next_char == 'E')
	{
		if (global->map->c == 0)
			mlx_close_window(global->mlx);
		else
			return ;
	}
}
