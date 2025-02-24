/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:12:47 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/24 21:43:59 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_tiles(t_textures *textures)
{
	textures->b_tile_t = NULL;
	textures->b_tile_i = NULL;
	textures->w_tile_t = NULL;
	textures->w_tile_i = NULL;
}

int	assign_tiles(mlx_t *mlx, t_textures *textures)
{
	textures->b_tile_t = mlx_load_png("./textures/tiles/b_t_32.png");
	if (!textures->b_tile_t)
		return (X_ERROR);
	textures->b_tile_i = mlx_texture_to_image(mlx, textures->b_tile_t);
	if (!textures->b_tile_i)
		return (X_ERROR);
	textures->w_tile_t = mlx_load_png("./textures/tiles/w_t_32.png");
	if (!textures->w_tile_t)
		return (X_ERROR);
	textures->w_tile_i = mlx_texture_to_image(mlx, textures->w_tile_t);
	if (!textures->w_tile_i)
		return (X_ERROR);
	return (SUCCESS);
}

int	render_tiles(t_map *map, mlx_t *mlx, t_textures *textures)
{
	int			x;
	int			y;
	int			check;
	mlx_image_t	*image;
	int			s;

	s = map->int_scale;
	y = 0;
	while (++y < map->y_size - 1)
	{
		x = 0;
		while (++x < map->x_size - 1)
		{
			image = select_tile(y, x, textures);
			if (image)
			{
				check = mlx_image_to_window(mlx, image, (WIDTH * s) * x,
						(HEIGHT * s) * y);
				if (check < 0)
					return (X_ERROR);
			}
		}
	}
	return (SUCCESS);
}

mlx_image_t	*select_tile(int y, int x, t_textures *textures)
{
	if (y % 2 != 0 && x % 2 != 0)
		return (textures->w_tile_i);
	if (y % 2 != 0 && x % 2 == 0)
		return (textures->b_tile_i);
	if (y % 2 == 0 && x % 2 != 0)
		return (textures->b_tile_i);
	if (y % 2 == 0 && x % 2 == 0)
		return (textures->w_tile_i);
	return (NULL);
}
