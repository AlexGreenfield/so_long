/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:03:45 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/17 22:35:05 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	static int	i;
	t_global	*global;

	global = (t_global *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		ft_printf("W %d\n", ++i);
		mov_hook(global, -1, 0);
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		ft_printf("A %d\n", ++i);
		mov_hook(global, 0, -1);
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		ft_printf("S %d\n", ++i);
		mov_hook(global, 1, 0);
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		ft_printf("D %d\n", ++i);
		mov_hook(global, 0, 1);
	}
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(global->mlx);
}


void	mov_hook(t_global *global, int y, int x)
{
	char		next_char;
	int			next_y;
	int			next_x;
	//int			current_y;
	//int			current_x;
	//mlx_image_t	*image;

	next_y = global->map->p_y + y;
	next_x = global->map->p_x + x;
	next_char = global->map->map_array[next_y][next_x];
	//current_y = global->map->p_y;
	//current_x = global->map->p_x;
	////global->map->map_array[global->map->p_x][global->map->p_x];
;
	if (next_char == '1')
		return ;
	if (next_char == '0')
		empty_tile(global, y, x);
	if (next_char == 'C')
		object_tile(global, y, x);
	if (next_char == 'E')
	{
		if (global->map->c == 0)
			mlx_close_window(global->mlx);
		else
			return ;
	}
}
