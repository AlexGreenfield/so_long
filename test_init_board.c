/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:45:39 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/15 17:22:53 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_board(t_map *map, mlx_t *mlx, t_textures *textures)
{
	init_borders (textures);
	if (assign_sides(mlx, textures) != SUCCESS)
		return (X_ERROR);
	if (assign_corners(mlx, textures) != SUCCESS)
		return (X_ERROR);
	if (render_borders(map, mlx, textures) != SUCCESS)
		return (X_ERROR);
	//if (init_textures (mlx, textures) != SUCCESS)
		//return (X_ERROR);
	//if (render_board (map, mlx, textures) != SUCCESS)
		//return (X_ERROR);
	return (SUCCESS);
}

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
	textures->border_top_t = mlx_load_png("./textures/borders/border_top_32.png");
	if (!textures->border_top_t)
		return (X_ERROR);
	textures->border_top_i = mlx_texture_to_image(mlx, textures->border_top_t);
	if (!textures->border_top_i)
		return (X_ERROR);
	textures->border_bottom_t = mlx_load_png("./textures/borders/border_bot_32.png");
	if (!textures->border_bottom_t)
		return (X_ERROR);
	textures->border_bottom_i = mlx_texture_to_image(mlx, textures->border_bottom_t);
	if (!textures->border_bottom_i)
		return (X_ERROR);
	textures->border_left_t = mlx_load_png("./textures/borders/border_left_32.png");
	if (!textures->border_left_t)
		return (X_ERROR);
	textures->border_left_i = mlx_texture_to_image(mlx, textures->border_left_t);
	if (!textures->border_left_i)
		return (X_ERROR);
	textures->border_right_t = mlx_load_png("./textures/borders/border_right_32.png");
	if (!textures->border_right_t)
		return (X_ERROR);
	textures->border_right_i = mlx_texture_to_image(mlx, textures->border_right_t);
	if (!textures->border_right_i)
		return (X_ERROR);
	return (SUCCESS);
}

int assign_corners(mlx_t *mlx, t_textures *textures)
{
	textures->corner_top_left_t = mlx_load_png("./textures/borders/border_top_left_32.png");
	if (!textures->corner_top_left_t)
		return (X_ERROR);
	textures->corner_top_left_i = mlx_texture_to_image(mlx, textures->corner_top_left_t);
	if (!textures->corner_top_left_i)
		return (X_ERROR);
	textures->corner_top_right_t = mlx_load_png("./textures/borders/border_top_right_32.png");
	if (!textures->corner_top_right_t)
		return (X_ERROR);
	textures->corner_top_right_i = mlx_texture_to_image(mlx, textures->corner_top_right_t);
	if (!textures->corner_top_right_i)
		return (X_ERROR);
	textures->corner_bottom_left_t = mlx_load_png("./textures/borders/border_bot_left_32.png");
	if (!textures->corner_bottom_left_t)
		return (X_ERROR);
	textures->corner_bottom_left_i = mlx_texture_to_image(mlx, textures->corner_bottom_left_t);
	if (!textures->corner_bottom_left_i)
		return (X_ERROR);
	textures->corner_bottom_right_t = mlx_load_png("./textures/borders/border_bot_right_32.png");
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
			if (y == 0 && x == 0)
				if (mlx_image_to_window(mlx, textures->corner_top_left_i,(WIDTH * x), (HEIGHT * y)) < 0)
			else if (y == 0 && x == map->x_size - 1)
				if (mlx_image_to_window(mlx, textures->corner_top_right_i,(WIDTH * x), (HEIGHT * y)) < 0)
			else if (y == map->y_size - 1 && x == 0)
				if (mlx_image_to_window(mlx, textures->corner_bottom_left_i,(WIDTH * x), (HEIGHT * y)) < 0)
			else if (y == map->y_size - 1 && x == map->x_size - 1)
				if (mlx_image_to_window(mlx, textures->corner_bottom_right_i,(WIDTH * x), (HEIGHT * y)) < 0)
			else if (y == 0)
				if (mlx_image_to_window(mlx, textures->border_top_i,(WIDTH * x), (HEIGHT * y)) < 0)
			else if (y == map->y_size - 1)
				if (mlx_image_to_window(mlx, textures->border_bottom_i,(WIDTH * x), (HEIGHT * y)) < 0)
			else if (x == 0)
				if (mlx_image_to_window(mlx, textures->border_left_i,(WIDTH * x), (HEIGHT * y)) < 0)
			else if (x == map->x_size - 1)
				if (mlx_image_to_window(mlx, textures->border_right_i,(WIDTH * x), (HEIGHT * y)) < 0)
		}
	}
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

			if (y == 0 && x == 0)
			{
				if (mlx_image_to_window(mlx, textures->corner_top_left_i,(WIDTH * x), (HEIGHT * y)) < 0)
					return (X_ERROR);
			}
			else if (y == 0 && x == map->x_size - 1)
			{
				if (mlx_image_to_window(mlx, textures->corner_top_right_i,(WIDTH * x), (HEIGHT * y)) < 0)
					return (X_ERROR);
			}
			else if (y == map->y_size - 1 && x == 0)
			{
				if (mlx_image_to_window(mlx, textures->corner_bottom_left_i,(WIDTH * x), (HEIGHT * y)) < 0)
					return (X_ERROR);
			}
			else if (y == map->y_size - 1 && x == map->x_size - 1)
			{
				if (mlx_image_to_window(mlx, textures->corner_bottom_right_i,(WIDTH * x), (HEIGHT * y)) < 0)
					return (X_ERROR);
			}
			else if (y == 0)
			{
				if (mlx_image_to_window(mlx, textures->border_top_i,(WIDTH * x), (HEIGHT * y)) < 0)
					return (X_ERROR);
			}
			else if (y == map->y_size - 1)
			{
				if (mlx_image_to_window(mlx, textures->border_bottom_i,(WIDTH * x), (HEIGHT * y)) < 0)
					return (X_ERROR);
			}
			else if (x == 0)
			{
				if (mlx_image_to_window(mlx, textures->border_left_i,(WIDTH * x), (HEIGHT * y)) < 0)
					return (X_ERROR);
			}
			else if (x == map->x_size - 1)
			{
				if (mlx_image_to_window(mlx, textures->border_right_i,(WIDTH * x), (HEIGHT * y)) < 0)
					return (X_ERROR);
			}
		}
	}
	return (SUCCESS);
}



//int	init_textures(mlx_t *mlx, t_textures *textures)
//{
	//textures->b_king_t = NULL;
	//textures->b_king_i = NULL;
	//textures->board_t = NULL;
	//textures->board_i = NULL;
	//textures->icon = NULL;

	//textures->b_king_t = mlx_load_png("./textures/16x32 pieces/B_King.png");
	//if (!textures->b_king_t)
		//return (X_ERROR);
	//mlx_set_icon(mlx, textures->b_king_t);
	//textures->b_king_i = mlx_texture_to_image(mlx, textures->b_king_t);
	//if (!textures->b_king_i)
		//return (X_ERROR);
	//textures->board_t = mlx_load_png("./textures/renders/border_32.png");
	//if (!textures->board_t)
		//return (X_ERROR);
	//textures->board_i = mlx_texture_to_image(mlx, textures->board_t);
	//if (!textures->board_i)
		//return (X_ERROR);
	//return (SUCCESS);
//}

//int	render_board(t_map *map, mlx_t *mlx, t_textures *textures)
//{
	//int	x;
	//int	y;

	//y = -1;
	//while (y++ < map->y_size)
	//{
		//x = -1;
		//while (x++ < map->x_size)
		//{
			//if (y == 0 || y == map->y_size - 1 || x == 0 || x == map->x_size -1)
			//{
				//if (mlx_image_to_window(mlx, textures->board_i,(WIDTH * x), (HEIGHT * y)) < 0)
					//return (X_ERROR);
			//}
		//}
	//}
	//return (SUCCESS);
//}
