/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:41:51 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/16 19:17:25by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_board(t_map *map, mlx_t *mlx, t_textures *textures)
{
	init_borders (textures);
	init_tiles (textures);
	init_pieces (textures);
	if (init_walls(map, mlx, textures) != SUCCESS)
		return (X_ERROR);
	if (init_floor(map, mlx, textures) != SUCCESS)
		return (X_ERROR);
	if (init_objects(map, mlx, textures) != SUCCESS)
		return (X_ERROR);
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

int	init_floor(t_map *map, mlx_t *mlx, t_textures *textures)
{
	if (assign_tiles(mlx, textures) != SUCCESS)
		return (X_ERROR);
	if (render_tiles(map, mlx, textures) != SUCCESS)
		return (X_ERROR);
	return (SUCCESS);
}

int	init_objects(t_map *map, mlx_t *mlx, t_textures *textures)
{
	if (assign_pieces(mlx, textures) != SUCCESS)
		return (X_ERROR);
	if (render_pieces(map, mlx, textures) != SUCCESS)
		return (X_ERROR);
	return (SUCCESS);
}