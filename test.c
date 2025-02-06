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
	void	*mlx;
	void	*mlx_window;
	int		i;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 600, 600, "so_long");
	i = 0;
	while (i++ < 100)
		mlx_pixel_put(mlx, mlx_window, 250 + i, 250, 0x00ff00);
	mlx_loop(mlx);
	return (0);
}
