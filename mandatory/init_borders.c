/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_borders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:45:39 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/24 21:39:03 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_borders(t_textures *textures)
{
	textures->b_top_t = NULL;
	textures->b_top_i = NULL;
	textures->b_bot_t = NULL;
	textures->b_bot_i = NULL;
	textures->b_left_t = NULL;
	textures->b_left_i = NULL;
	textures->b_right_t = NULL;
	textures->b_right_i = NULL;
	textures->c_top_l_t = NULL;
	textures->c_top_l_i = NULL;
	textures->c_top_r_t = NULL;
	textures->c_top_r_i = NULL;
	textures->c_bot_l_t = NULL;
	textures->c_bot_l_i = NULL;
	textures->c_bot_r_t = NULL;
	textures->c_bot_r_i = NULL;
	return (SUCCESS);
}

int	assign_sides(mlx_t *mlx, t_textures *textures)
{
	textures->b_top_t = mlx_load_png("./textures/borders/top_32.png");
	if (!textures->b_top_t)
		return (X_ERROR);
	textures->b_top_i = mlx_texture_to_image(mlx, textures->b_top_t);
	if (!textures->b_top_i)
		return (X_ERROR);
	textures->b_bot_t = mlx_load_png("./textures/borders/bot_32.png");
	if (!textures->b_bot_t)
		return (X_ERROR);
	textures->b_bot_i = mlx_texture_to_image(mlx, textures->b_bot_t);
	if (!textures->b_bot_i)
		return (X_ERROR);
	textures->b_left_t = mlx_load_png("./textures/borders/left_32.png");
	if (!textures->b_left_t)
		return (X_ERROR);
	textures->b_left_i = mlx_texture_to_image(mlx, textures->b_left_t);
	if (!textures->b_left_i)
		return (X_ERROR);
	textures->b_right_t = mlx_load_png("./textures/borders/right_32.png");
	if (!textures->b_right_t)
		return (X_ERROR);
	textures->b_right_i = mlx_texture_to_image(mlx, textures->b_right_t);
	if (!textures->b_right_i)
		return (X_ERROR);
	return (SUCCESS);
}

int	assign_corners(mlx_t *mlx, t_textures *textures)
{
	textures->c_top_l_t = mlx_load_png("./textures/borders/t_l_32.png");
	if (!textures->c_top_l_t)
		return (X_ERROR);
	textures->c_top_l_i = mlx_texture_to_image(mlx, textures->c_top_l_t);
	if (!textures->c_top_l_i)
		return (X_ERROR);
	textures->c_top_r_t = mlx_load_png("./textures/borders/t_r_32.png");
	if (!textures->c_top_r_t)
		return (X_ERROR);
	textures->c_top_r_i = mlx_texture_to_image(mlx, textures->c_top_r_t);
	if (!textures->c_top_r_i)
		return (X_ERROR);
	textures->c_bot_l_t = mlx_load_png("./textures/borders/b_l_32.png");
	if (!textures->c_bot_l_t)
		return (X_ERROR);
	textures->c_bot_l_i = mlx_texture_to_image(mlx, textures->c_bot_l_t);
	if (!textures->c_bot_l_i)
		return (X_ERROR);
	textures->c_bot_r_t = mlx_load_png("./textures/borders/b_r_32.png");
	if (!textures->c_bot_r_t)
		return (X_ERROR);
	textures->c_bot_r_i = mlx_texture_to_image(mlx, textures->c_bot_r_t);
	if (!textures->c_bot_r_i)
		return (X_ERROR);
	return (SUCCESS);
}

mlx_image_t	*select_borders(int y, int x, t_map *map, t_textures *textures)
{
	if (y == 0 && x == 0)
		return (textures->c_top_l_i);
	if (y == 0 && x == map->x_size - 1)
		return (textures->c_top_r_i);
	if (y == map->y_size - 1 && x == 0)
		return (textures->c_bot_l_i);
	if (y == map->y_size - 1 && x == map->x_size - 1)
		return (textures->c_bot_r_i);
	if (y == 0)
		return (textures->b_top_i);
	if (y == map->y_size - 1)
		return (textures->b_bot_i);
	if (x == 0)
		return (textures->b_left_i);
	if (x == map->x_size - 1)
		return (textures->b_right_i);
	return (NULL);
}

int	render_borders(t_map *map, mlx_t *mlx, t_textures *textures)
{
	int			x;
	int			y;
	int			check;
	mlx_image_t	*image;

	y = 0;
	while (y < map->y_size)
	{
		x = 0;
		while (x < map->x_size)
		{
			image = select_borders(y, x, map, textures);
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
