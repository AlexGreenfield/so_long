/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:13:52 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/24 20:22:53 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	idle(void *param)
{
	t_global	*global;
	static int	frames;
	static int	count;

	global = (t_global *)param;
	global->textures->b_king_i->instances[0].x = global->map->p_x * WIDTH;
	global->textures->b_king_i->instances[0].y = global->map->p_y * HEIGHT;
	global->textures->b_kingb_i->instances[0].x = global->map->p_x * WIDTH;
	global->textures->b_kingb_i->instances[0].y = global->map->p_y * HEIGHT;
	if (frames % (30 * 2) < 30)
	{
		global->textures->b_king_i->enabled = true;
		global->textures->b_kingb_i->enabled = false;
		if (global->map->c == 0)
			global->textures->w_king_i->enabled = false;
	}
	else
	{
		count++;
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
		if (my_abs(pawn_x - king_x) <= WIDTH)
		{
			if (my_abs(pawn_y - king_y) <= HEIGHT)
			{
				ft_printf("Disabling pawn at (%d, %d), King at (%d, %d)\n",
					pawn_x, pawn_y, king_x, king_y);
				global->textures->w_pawn_i->instances[i].enabled = false;
			}
		}
		i++;
	}
	ft_printf("No matching pawn found within ±32 range.\n");
}
