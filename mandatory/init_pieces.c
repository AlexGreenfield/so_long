/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:41:48 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/19 21:03:23 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_pieces(t_textures *textures)
{
	textures->b_king_t = NULL;
	textures->b_king_i = NULL;
	textures->w_king_t = NULL;
	textures->w_king_i = NULL;
	textures->b_tower_t = NULL;
	textures->b_tower_i = NULL;
	textures->w_pawn_t = NULL;
	textures->w_pawn_i = NULL;
}

int	assign_pieces(mlx_t *mlx, t_textures *textures)
{
	textures->b_king_t = mlx_load_png("./textures/pieces/b_king_32.png");
	if (!textures->b_king_t)
		return (X_ERROR);
	textures->b_king_i = mlx_texture_to_image(mlx, textures->b_king_t);
	if (!textures->b_king_i)
		return (X_ERROR);
	textures->w_king_t = mlx_load_png("./textures/pieces/w_king_32.png");
	if (!textures->w_king_t)
		return (X_ERROR);
	textures->w_king_i = mlx_texture_to_image(mlx, textures->w_king_t);
	if (!textures->w_king_i)
		return (X_ERROR);
	textures->b_tower_t = mlx_load_png("./textures/pieces/b_tower_32.png");
	if (!textures->b_tower_t)
		return (X_ERROR);
	textures->b_tower_i = mlx_texture_to_image(mlx, textures->b_tower_t);
	if (!textures->b_tower_i)
		return (X_ERROR);
	textures->w_pawn_t = mlx_load_png("./textures/pieces/w_pawn_32.png");
	if (!textures->w_pawn_t)
		return (X_ERROR);
	textures->w_pawn_i = mlx_texture_to_image(mlx, textures->w_pawn_t);
	if (!textures->w_pawn_i)
		return (X_ERROR);
	return (SUCCESS);
}

int	render_pieces(t_map *map, mlx_t *mlx, t_textures *textures)
{
	int			x;
	int			y;
	int			check;
	mlx_image_t	*image;

	y = 1;
	while (y < map->y_size - 1)
	{
		x = 1;
		while (x < map->x_size - 1)
		{
			image = select_piece(y, x, map, textures);
			if (image)
			{
				check = mlx_image_to_window(mlx, image, WIDTH * x, HEIGHT * y);
				if (check < 0)
					return (X_ERROR);
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

mlx_image_t	*select_piece(int y, int x, t_map *map, t_textures *textures)
{
	if (map->map_array[y][x] == 'C')
		return (textures->w_pawn_i);
	if (map->map_array[y][x] == 'E')
		return (textures->w_king_i);
	if (map->map_array[y][x] == 'P')
		return (textures->b_king_i);
	if (map->map_array[y][x] == '1')
		return (textures->b_tower_i);
	return (NULL);
}
