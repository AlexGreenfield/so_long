/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_board_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:22:04 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/15 17:33:15 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	delete_textures(mlx_t *mlx, t_textures *textures, int flag)
{
	mlx_delete_texture(textures->border_top_t);
	mlx_delete_image(mlx, textures->border_top_i);
	mlx_delete_texture(textures->border_bottom_t);
	mlx_delete_image(mlx, textures->border_bottom_i);
	mlx_delete_texture(textures->border_left_t);
	mlx_delete_image(mlx, textures->border_left_i);
	mlx_delete_texture(textures->border_right_t);
	mlx_delete_image(mlx, textures->border_right_i);
	mlx_delete_texture(textures->corner_top_left_t);
	mlx_delete_image(mlx, textures->corner_top_left_i);
	mlx_delete_texture(textures->corner_top_right_t);
	mlx_delete_image(mlx, textures->corner_top_right_i);
	mlx_delete_texture(textures->corner_bottom_left_t);
	mlx_delete_image(mlx, textures->corner_bottom_left_i);
	mlx_delete_texture(textures->corner_bottom_right_t);
	mlx_delete_image(mlx, textures->corner_bottom_right_i);
	mlx_delete_texture(textures->b_tile_t);
	mlx_delete_image(mlx, textures->b_tile_i);
	mlx_delete_texture(textures->w_tile_t);
	mlx_delete_image(mlx, textures->w_tile_i);
	free(textures);
	return (flag);
}

