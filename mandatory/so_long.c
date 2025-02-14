/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:06:12 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/14 21:10:58 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_so_long(t_map *map);
void my_keyhook(mlx_key_data_t keydata, void* param);


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
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	mlx = mlx_init(1920, 1080, "test", true);
	if (!mlx)
		return (X_ERROR);
	texture = mlx_load_png("./textures/renders/board_1136.png");
	if (!texture)
	{
		printf("fail to open texture");
		return (X_ERROR);
	}
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
	{
		printf("fail to texture to img");
		return (X_ERROR);
	}
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		return (X_ERROR);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	ft_free_array(map->map_array);
	return (SUCCESS);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	param = NULL;
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}

