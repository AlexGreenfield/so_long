/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:41:48 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/16 18:44:16 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
