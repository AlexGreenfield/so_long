/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:06:12 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/15 17:28:10 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

	mlx = mlx_init((WIDTH * map->x_size), (HEIGHT * map->y_size),
			"King's Pawns", false);
	if (!mlx)
		return (X_ERROR);
	textures = malloc (sizeof(t_textures));
	if (!textures)
		return (MALLOC_ERROR);
	if (init_board(map, mlx, textures) != SUCCESS)
		return (delete_textures(mlx, textures, X_ERROR));
	//if (mlx_image_to_window(mlx, textures->b_king_i, WIDTH * 1, 
			//HEIGHT * 1) < 0)
		//return (delete_textures(textures, X_ERROR));
	mlx_loop(mlx);
	delete_textures(mlx, textures, SUCCESS);
	mlx_terminate(mlx);
	ft_free_array(map->map_array);
	return (SUCCESS);
}

//void my_keyhook(mlx_key_data_t keydata, void* param)
//{
	//param = NULL;
	//// If we PRESS the 'J' key, print "Hello".
	//if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		//puts("Hello ");

	//// If we RELEASE the 'K' key, print "World".
	//if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		//puts("World");

	//// If we HOLD the 'L' key, print "!".
	//if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		//puts("!");
//}
