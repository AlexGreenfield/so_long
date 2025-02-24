/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:13:52 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/24 22:08:04 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	idle(void *param)
{
	t_global	*global;
	static int	frames;
	int			s;

	global = (t_global *)param;
	s = global->map->int_scale;
	global->textures->b_king_i->instances[0].x = global->map->p_x * WIDTH * s;
	global->textures->b_king_i->instances[0].y = global->map->p_y * HEIGHT * s;
	global->textures->b_kingb_i->instances[0].x = global->map->p_x * WIDTH * s;
	global->textures->b_kingb_i->instances[0].y = global->map->p_y * HEIGHT * s;
	if (frames % (30 * 2) < 30)
	{
		global->textures->b_king_i->enabled = true;
		global->textures->b_kingb_i->enabled = false;
		if (global->map->c == 0)
			global->textures->w_king_i->enabled = false;
	}
	else
	{
		global->textures->b_king_i->enabled = false;
		global->textures->b_kingb_i->enabled = true;
		global->textures->w_king_i->enabled = true;
	}
	frames++;
}

int	my_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	disable_object(t_global *global)
{
	int	king_x;
	int	king_y;
	int	pawn_x;
	int	pawn_y;
	int	i;

	i = 0;
	king_x = global->textures->b_king_i->instances[0].x;
	king_y = global->textures->b_king_i->instances[0].y;
	while (i < global->map->fill_c)
	{
		pawn_x = global->textures->w_pawn_i->instances[i].x;
		pawn_y = global->textures->w_pawn_i->instances[i].y;
		if (my_abs(pawn_x - king_x) <= WIDTH * global->map->int_scale)
		{
			if (my_abs(pawn_y - king_y) <= HEIGHT * global->map->int_scale)
			{
				ft_printf("Disabling pawn at (%d, %d), King at (%d, %d)\n",
					pawn_x, pawn_y, king_x, king_y);
				global->textures->w_pawn_i->instances[i].enabled = false;
			}
		}
		i++;
	}
	ft_printf("Pawn at (%d, %d), King at (%d, %d)\n",
		pawn_x, pawn_y, king_x, king_y);
	ft_printf("No matching pawn found within ±32 range.\n");
}

int	get_window_size(t_map *map)
{
	mlx_t	*temp;
	int32_t	width;
	int32_t	height;
	int		width_factor;
	int		height_factor;

	mlx_set_setting(MLX_HEADLESS, true);
	temp = mlx_init(1, 1, "", false);
	if (!temp)
	{
		mlx_terminate(temp);
		return (X_ERROR);
	}
	mlx_get_monitor_size(0, &width, &height);
	mlx_terminate(temp);
	mlx_set_setting(MLX_HEADLESS, false);
	ft_printf("In ft, width is %d\n", width);
	ft_printf("In ft, height is %d\n", height);
	width_factor = width / (map->x_size * WIDTH);
	height_factor = height / (map->y_size * HEIGHT);
	if (width_factor < height_factor)
		map->int_scale = width_factor;
	else
		map->int_scale = height_factor;
	ft_printf("In ft, scale is %d\n", map->int_scale);
	return (SUCCESS);
}
