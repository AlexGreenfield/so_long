/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:28:38 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/24 21:35:06 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	resize_borders(t_textures *textures, int scale)
{
	mlx_resize_image(textures->b_top_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->b_bot_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->b_left_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->b_right_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->c_top_l_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->c_top_r_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->c_bot_l_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->c_bot_r_i, WIDTH * scale, HEIGHT * scale);
}

void	resize_pieces(t_textures *textures, int scale)
{
	mlx_resize_image(textures->b_king_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->w_king_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->b_tower_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->w_pawn_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->w_horse_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->b_kingb_i, WIDTH * scale, HEIGHT * scale);
}

void	resize_tiles(t_textures *textures, int scale)
{
	mlx_resize_image(textures->b_tile_i, WIDTH * scale, HEIGHT * scale);
	mlx_resize_image(textures->w_tile_i, WIDTH * scale, HEIGHT * scale);
}
