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

int	button_press(int button, int x, int y, t_mlx_data *mlx);
int	handle_input(int keysym, t_mlx_data *mlx);
int	close_window(t_mlx_data *mlx);

int	main(void)
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
	mlx_key_hook(mlx.win_ptr, handle_input, &mlx);
	mlx_hook(mlx.win_ptr, ButtonPress, ButtonPressMask, &button_press, &mlx);
	mlx_hook(mlx.win_ptr, DestroyNotify, 0, close_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	return (0);
}

int	handle_input(int keysym, t_mlx_data *mlx)
{
	static int	i;

	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(1);
	}
	else
		printf("Move is :%d\n", ++i);
	return (0);
}

int	button_press(int button, int x, int y, t_mlx_data *mlx)
{
	void *win_copy;

	win_copy = mlx->win_ptr;
	if (button == 1)
		printf("Left mouse button pressed at (%d, %d)!\n", x, y);
	if (button == 3)
		printf("Right mouse button pressed at (%d, %d)!\n", x, y);
	return (0);
}

int	close_window(t_mlx_data *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(1);
}
