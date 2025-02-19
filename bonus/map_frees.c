/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_frees.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:51:26 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/19 21:08:11 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	free_main_map(t_map *map, int flag);
int	free_map_array(t_map *map, int flag);

int	free_main_map(t_map *map, int flag)
{
	free (map);
	if (flag == X_ERROR)
		write (2, "Error\nBad call to X\n", 21);
	if (flag != SUCCESS)
		write (2, "Error\nBad Map\n", 15);
	return (flag);
}

int	free_map_array(t_map *map, int flag)
{
	int	i;

	if (!map || !map->map_array)
		return (flag);
	i = 0;
	while (map->map_array[i])
	{
		free(map->map_array[i]);
		i++;
	}
	free(map->map_array);
	map->map_array = NULL;
	if (map->fd)
		close(map->fd);
	return (flag);
}
