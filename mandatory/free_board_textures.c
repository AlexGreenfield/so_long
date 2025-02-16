/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_board_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:22:04 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/16 19:14:38 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	delete_textures(mlx_t *mlx, t_textures *textures, int flag)
{
	clean_board_textures(textures);
	clean_board_images(mlx, textures);
	clean_pieces_textures_images(mlx, textures);
	free(textures);
	return (flag);
}

int	clean_board_textures(t_textures *textures)
{
	if (textures->b_top_t)
		mlx_delete_texture(textures->b_top_t);
	if (textures->b_bot_t)
		mlx_delete_texture(textures->b_bot_t);
	if (textures->b_left_t)
		mlx_delete_texture(textures->b_left_t);
	if (textures->b_right_t)
		mlx_delete_texture(textures->b_right_t);
	if (textures->c_top_l_t)
		mlx_delete_texture(textures->c_top_l_t);
	if (textures->c_top_r_t)
		mlx_delete_texture(textures->c_top_r_t);
	if (textures->c_bot_l_t)
		mlx_delete_texture(textures->c_bot_l_t);
	if (textures->c_bot_r_t)
		mlx_delete_texture(textures->c_bot_r_t);
	if (textures->b_tile_t)
		mlx_delete_texture(textures->b_tile_t);
	if (textures->w_tile_t)
		mlx_delete_texture(textures->w_tile_t);
	return (SUCCESS);
}

int	clean_board_images(mlx_t *mlx, t_textures *textures)
{
	if (textures->b_top_i)
		mlx_delete_image(mlx, textures->b_top_i);
	if (textures->b_bot_i)
		mlx_delete_image(mlx, textures->b_bot_i);
	if (textures->b_left_i)
		mlx_delete_image(mlx, textures->b_left_i);
	if (textures->b_right_i)
		mlx_delete_image(mlx, textures->b_right_i);
	if (textures->c_top_l_i)
		mlx_delete_image(mlx, textures->c_top_l_i);
	if (textures->c_top_r_i)
		mlx_delete_image(mlx, textures->c_top_r_i);
	if (textures->c_bot_l_i)
		mlx_delete_image(mlx, textures->c_bot_l_i);
	if (textures->c_bot_r_i)
		mlx_delete_image(mlx, textures->c_bot_r_i);
	if (textures->b_tile_i)
		mlx_delete_image(mlx, textures->b_tile_i);
	if (textures->w_tile_i)
		mlx_delete_image(mlx, textures->w_tile_i);
	return (SUCCESS);
}

int	clean_pieces_textures_images(mlx_t *mlx, t_textures *textures)
{
	if (textures->b_tile_t)
		mlx_delete_texture(textures->b_tile_t);
	if (textures->w_tile_t)
		mlx_delete_texture(textures->w_tile_t);
	if (textures->b_king_t)
		mlx_delete_texture(textures->b_king_t);
	if (textures->w_king_t)
		mlx_delete_texture(textures->w_king_t);
	if (textures->b_tower_t)
		mlx_delete_texture(textures->b_tower_t);
	if (textures->w_pawn_t)
		mlx_delete_texture(textures->w_pawn_t);
	if (textures->b_tile_i)
		mlx_delete_image(mlx, textures->b_tile_i);
	if (textures->w_tile_i)
		mlx_delete_image(mlx, textures->w_tile_i);
	if (textures->b_king_i)
		mlx_delete_image(mlx, textures->b_king_i);
	if (textures->w_king_i)
		mlx_delete_image(mlx, textures->w_king_i);
	if (textures->b_tower_i)
		mlx_delete_image(mlx, textures->b_tower_i);
	if (textures->w_pawn_i)
		mlx_delete_image(mlx, textures->w_pawn_i);
	return (SUCCESS);
}
