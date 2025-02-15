/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:12:47 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/15 17:19:13 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	init_tiles(t_textures *textures)
{
	textures->b_tile_t = NULL;
	textures->b_tile_i = NULL;
	textures->w_tile_t = NULL;
	textures->w_tile_i = NULL;
}