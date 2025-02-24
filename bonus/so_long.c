/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:06:12 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/24 21:27:05 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int		init_so_long(t_map *map);
void	my_keyhook(mlx_key_data_t keydata, void *param);

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		map = malloc(sizeof(t_map));
		if (!map)
			return (MALLOC_ERROR);
		if (check_ber(argv[1], map) != SUCCESS)
			return (free_main_map(map, FILE_ERROR));
		if (get_window_size(map) != SUCCESS)
		{
			ft_printf("bad window\n");
			return (free_main_map(map, FILE_ERROR));
		}
		if (init_so_long(map) != SUCCESS)
			return (free_main_map(map, X_ERROR));
		return (free_main_map(map, SUCCESS));
	}
	else
		write (2, "Error\n", 7);
	return (SUCCESS);
}

int	init_so_long(t_map *map)
{
	mlx_t			*mlx;
	t_textures		*textures;
	t_global		*global;
	int				scale;

	scale = map->int_scale;
	ft_printf("Scale is %d\n", scale);
	mlx = mlx_init(((WIDTH * scale) * map->x_size),
			((HEIGHT * scale) * map->y_size), "King's Pawn", false);
	if (!mlx)
		return (X_ERROR);
	textures = malloc (sizeof(t_textures));
	if (!textures)
		return (MALLOC_ERROR);
	if (init_board(map, mlx, textures) != SUCCESS)
		return (end_game(map, mlx, textures, X_ERROR));
	global = malloc (sizeof(t_global));
	if (!global)
		return (end_game(map, mlx, textures, X_ERROR));
	global->map = map;
	global->textures = textures;
	global->mlx = mlx;
	mlx_key_hook(mlx, key_hooks, global);
	mlx_loop_hook(mlx, idle, global);
	mlx_loop(mlx);
	free(global);
	global = NULL;
	return (end_game(map, mlx, textures, SUCCESS));
}

int	end_game(t_map *map, mlx_t *mlx, t_textures *textures, int flag)
{
	delete_textures(mlx, textures, flag);
	mlx_terminate(mlx);
	ft_free_array(map->map_array);
	return (flag);
}
