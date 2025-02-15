/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:41:51 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/15 17:46:35 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_board(t_map *map, mlx_t *mlx, t_textures *textures)
{
	init_borders (textures);
	//init_tiles (textures);
	//init_pieces (textures);
	if (init_walls(map, mlx, textures) != SUCCESS)
		return (X_ERROR);
	//if (render_floor(map, mlx, textures) != SUCCESS)
		//return (X_ERROR);
	//if (render_pieces(map, mlx, textures) != SUCCESS)
		//return (X_ERROR);
	return (SUCCESS);
}

int	init_walls(t_map *map, mlx_t *mlx, t_textures *textures)
{
	if (assign_sides(mlx, textures) != SUCCESS)
		return (X_ERROR);
	if (assign_corners(mlx, textures) != SUCCESS)
		return (X_ERROR);
	if (render_borders(map, mlx, textures) != SUCCESS)
		return (X_ERROR);
	return (SUCCESS);
}
