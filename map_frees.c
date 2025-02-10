/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_frees.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:51:26 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/10 22:45:22 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_main_map(t_map *map, int flag);
int	free_map_array(t_map *map, int flag);

int	free_main_map(t_map *map, int flag)
{
	free (map);
	if (flag != SUCCESS)
		write (2, "Error\n", 7);
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
