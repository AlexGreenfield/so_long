/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:06:12 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/13 19:55:07 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_so_long(t_map *map);

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
		//if (init_so_long(map) != SUCCESS)
			//return (free_main_map(map, X_ERROR));
		return (free_main_map(map, SUCCESS));
	}
	else
		write (2, "Error\n", 7);
	return (SUCCESS);
}

//int	init_so_long(t_map *map)
//{
	//t_mlx_data	mlx;
	//int			i;

	//close(map->fd); // Not in use
	//mlx.mlx_ptr = mlx_init();
	//if (mlx.mlx_ptr == NULL)
		//return (X_ERROR);
	//mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 600, 600, "so_long");
	//if (mlx.win_ptr == NULL)
	//{
		//mlx_destroy_display(mlx.mlx_ptr);
		//free(mlx.mlx_ptr);
		//return (X_ERROR);
	//}
	//i = 0;
	//mlx_key_hook(mlx.win_ptr, handle_input, &mlx);
	//mlx_hook(mlx.win_ptr, ButtonPress, ButtonPressMask, &button_press, &mlx);
	//mlx_hook(mlx.win_ptr, DestroyNotify, 0, close_window, &mlx);
	//mlx_loop(mlx.mlx_ptr);
	//mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	//mlx_destroy_display(mlx.mlx_ptr);
	//free(mlx.mlx_ptr);
	//return (SUCCESS);
//}
