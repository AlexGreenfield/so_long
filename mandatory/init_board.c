/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:54:43 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/15 14:32:15 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_board(t_map *map, mlx_t *mlx, t_textures *textures)
{
	if (init_textures (mlx, textures) != SUCCESS)
		return (X_ERROR);
	if (render_board (map, mlx, textures) != SUCCESS)
		return (X_ERROR);
	return (SUCCESS);
}

int	delete_textures(mlx_t *mlx, t_textures *textures, int flag)
{
	if (textures->b_king_t)
		mlx_delete_texture(textures->b_king_t);
	if (textures->b_king_i)
		mlx_delete_image(mlx, textures->b_king_i);
	if (textures->board_t)
		mlx_delete_texture(textures->board_t);
	if (textures->board_i)
		mlx_delete_image(mlx, textures->board_i);
	if (textures->icon)
		mlx_delete_image(mlx, textures->icon);
	free (textures);
	return (flag);
}

int	init_textures(mlx_t *mlx, t_textures *textures)
{
	textures->b_king_t = NULL;
	textures->b_king_i = NULL;
	textures->board_t = NULL;
	textures->board_i = NULL;
	textures->icon = NULL;

	textures->b_king_t = mlx_load_png("./textures/16x32 pieces/B_King.png");
	if (!textures->b_king_t)
		return (X_ERROR);
	mlx_set_icon(mlx, textures->b_king_t);
	textures->b_king_i = mlx_texture_to_image(mlx, textures->b_king_t);
	if (!textures->b_king_i)
		return (X_ERROR);
	textures->board_t = mlx_load_png("./textures/renders/border_32.png");
	if (!textures->board_t)
		return (X_ERROR);
	textures->board_i = mlx_texture_to_image(mlx, textures->board_t);
	if (!textures->board_i)
		return (X_ERROR);
	return (SUCCESS);
}

int	render_board(t_map *map, mlx_t *mlx, t_textures *textures)
{
	int	x;
	int	y;

	y = -1;
	while (y++ < map->y_size)
	{
		x = -1;
		while (x++ < map->x_size)
		{
			if (y == 0 || y == map->y_size - 1 || x == 0 || x == map->x_size -1)
			{
				if (mlx_image_to_window(mlx, textures->board_i,(WIDTH * x), (HEIGHT * y)) < 0)
					return (X_ERROR);
			}
		}
	}
	return (SUCCESS);
}
