/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_borders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:45:39 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/15 17:38:31 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_borders(t_textures *textures)
{
	textures->border_top_t = NULL;
	textures->border_top_i = NULL;
	textures->border_bottom_t = NULL;
	textures->border_bottom_i = NULL;
	textures->border_left_t = NULL;
	textures->border_left_i = NULL;
	textures->border_right_t = NULL;
	textures->border_right_i = NULL;
	textures->corner_top_left_t = NULL;
	textures->corner_top_left_i = NULL;
	textures->corner_top_right_t = NULL;
	textures->corner_top_right_i = NULL;
	textures->corner_bottom_left_t = NULL;
	textures->corner_bottom_left_i = NULL;
	textures->corner_bottom_right_t = NULL;
	textures->corner_bottom_right_i = NULL;
	return (SUCCESS);
}

int	assign_sides(mlx_t *mlx, t_textures *textures)
{
	textures->border_top_t = mlx_load_png("./textures/borders/top_32.png");
	if (!textures->border_top_t)
		return (X_ERROR);
	textures->border_top_i = mlx_texture_to_image(mlx, textures->border_top_t);
	if (!textures->border_top_i)
		return (X_ERROR);
	textures->border_bottom_t = mlx_load_png("./textures/borders/bot_32.png");
	if (!textures->border_bottom_t)
		return (X_ERROR);
	textures->border_bottom_i = mlx_texture_to_image(mlx, textures->border_bottom_t);
	if (!textures->border_bottom_i)
		return (X_ERROR);
	textures->border_left_t = mlx_load_png("./textures/borders/left_32.png");
	if (!textures->border_left_t)
		return (X_ERROR);
	textures->border_left_i = mlx_texture_to_image(mlx, textures->border_left_t);
	if (!textures->border_left_i)
		return (X_ERROR);
	textures->border_right_t = mlx_load_png("./textures/borders/right_32.png");
	if (!textures->border_right_t)
		return (X_ERROR);
	textures->border_right_i = mlx_texture_to_image(mlx, textures->border_right_t);
	if (!textures->border_right_i)
		return (X_ERROR);
	return (SUCCESS);
}

int	assign_corners(mlx_t *mlx, t_textures *textures)
{
	textures->corner_top_left_t = mlx_load_png("./textures/borders/t_l_32.png");
	if (!textures->corner_top_left_t)
		return (X_ERROR);
	textures->corner_top_left_i = mlx_texture_to_image(mlx, textures->corner_top_left_t);
	if (!textures->corner_top_left_i)
		return (X_ERROR);
	textures->corner_top_right_t = mlx_load_png("./textures/borders/t_r_32.png");
	if (!textures->corner_top_right_t)
		return (X_ERROR);
	textures->corner_top_right_i = mlx_texture_to_image(mlx, textures->corner_top_right_t);
	if (!textures->corner_top_right_i)
		return (X_ERROR);
	textures->corner_bottom_left_t = mlx_load_png("./textures/borders/b_l_32.png");
	if (!textures->corner_bottom_left_t)
		return (X_ERROR);
	textures->corner_bottom_left_i = mlx_texture_to_image(mlx, textures->corner_bottom_left_t);
	if (!textures->corner_bottom_left_i)
		return (X_ERROR);
	textures->corner_bottom_right_t = mlx_load_png("./textures/borders/b_r_32.png");
	if (!textures->corner_bottom_right_t)
		return (X_ERROR);
	textures->corner_bottom_right_i = mlx_texture_to_image(mlx, textures->corner_bottom_right_t);
	if (!textures->corner_bottom_right_i)
		return (X_ERROR);
	return (SUCCESS);
}

int	render_borders(t_map *map, mlx_t *mlx, t_textures *textures)
{
	int	x;
	int	y;

	y = -1;
	while (y++ < map->y_size)
	{
		x = -1;
		while (x++ < map->x_size)
		{
			if (put_border(y, x, mlx, map, textures) != SUCCESS)
				return (X_ERROR);

		}
	}
	return (SUCCESS);
}

int	put_border(int y, int x, mlx_t *mlx, t_map *map, t_textures *textures)
{
	int	i;

	i = SUCCESS;
	if (y == 0 && x == 0)
		i = mlx_image_to_window(mlx, textures->corner_top_left_i, (WIDTH * x), (HEIGHT * y));
	else if (y == 0 && x == map->x_size - 1)
		i = mlx_image_to_window(mlx, textures->corner_top_right_i, (WIDTH * x), (HEIGHT * y));
	else if (y == map->y_size - 1 && x == 0)
		i = mlx_image_to_window(mlx, textures->corner_bottom_left_i, (WIDTH * x), (HEIGHT * y));
	else if (y == map->y_size - 1 && x == map->x_size - 1)
		i = mlx_image_to_window(mlx, textures->corner_bottom_right_i, (WIDTH * x), (HEIGHT * y));
	else if (y == 0)
		i = mlx_image_to_window(mlx, textures->border_top_i, (WIDTH * x), (HEIGHT * y));
	else if (y == map->y_size - 1)
		i = mlx_image_to_window(mlx, textures->border_bottom_i, (WIDTH * x), (HEIGHT * y));
	else if (x == 0)
		i = mlx_image_to_window(mlx, textures->border_left_i, (WIDTH * x), (HEIGHT * y));
	else if (x == map->x_size - 1)
		i = mlx_image_to_window(mlx, textures->border_right_i, (WIDTH * x), (HEIGHT * y));
	if (i < 0)
		return (X_ERROR);
	return (SUCCESS);
}
