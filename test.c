/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:00:26 by acastrov          #+#    #+#             */
/*   Updated: 2025/02/05 19:05 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx_data	mlx;
	int			i;

	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (X_ERROR);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 600, 600, "so_long");
	if (mlx.win_ptr == NULL)
	{
		mlx_destroy_display(mlx.mlx_ptr);
		free(mlx.mlx_ptr);
		return (X_ERROR);
	}
	i = 0;
	while (i++ < 100)
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, 250 + i, 250, 0x00ff00);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	return (0);
}
