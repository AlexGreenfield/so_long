/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:28:30 by acastrov          #+#    #+#             */
/*   Updated: 2025/02/13 17:19:01 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	allocate_map(t_map *map, char *arg);
int	bad_walls(t_map *map);
int	bad_items(t_map *map);
int	bad_flood(t_map *map);

int	check_ber(char *arg, t_map *map)
{
	if (!arg)
		return (FILE_ERROR);
	if (bad_ber(arg))
		return (FILE_ERROR);
	if (bad_size(map, arg) || map->y_size < 3 || map->x_size < 3)
		return (FILE_ERROR);
	if (allocate_map(map, arg) != SUCCESS)
		return (FILE_ERROR);
	if (bad_walls(map))
		return (free_map_array(map, FILE_ERROR));
	if (bad_items(map))
		return (free_map_array(map, FILE_ERROR));
	if (bad_flood(map))
		return (free_map_array(map, FILE_ERROR));
	//return (free_map_array(map, SUCCESS)); // Maybe we need to not destroy the map until exit
	return (SUCCESS); // Maybe we need to not destroy the map until exit
}

int	allocate_map(t_map *map, char *arg)
{
	int		i;
	char	*temp;

	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	map->map_array = malloc((map->y_size + 1) * sizeof(char *));
	if (!map->map_array)
		return (MALLOC_ERROR);
	i = -1;
	while (i++ < map->y_size)
		map->map_array[i] = NULL;
	i = -1;
	while (i++ < map->y_size - 1)
	{
		temp = get_next_line(map->fd);
		map->map_array[i] = ft_substr(temp, 0, map->x_size);
		free(temp);
		temp = NULL;
		if (!map->map_array[i])
			return (free_map_array(map, MALLOC_ERROR));
	}
	close(map->fd);
	return (SUCCESS);
}

int	bad_walls(t_map *map)
{
	int	i;

	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->p_x = 0;
	map->p_y = 0;
	i = -1;
	while (map->map_array[0][++i])
		if (map->map_array[0][i] != '1')
			return (FILE_ERROR);
	i = -1;
	while (map->map_array[map->y_size - 1][++i])
		if (map->map_array[map->y_size - 1][i] != '1')
			return (FILE_ERROR);
	i = -1;
	while (++i < map->y_size)
		if (map->map_array[i][0] != '1')
			return (FILE_ERROR);
	i = -1;
	while (++i < map->y_size)
		if (map->map_array[i][map->x_size - 1] != '1')
			return (FILE_ERROR);
	return (SUCCESS);
}

int	bad_items(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->y_size)
	{
		x = -1;
		while (++x < map->x_size)
		{
			if (map->map_array[y][x] == 'C')
				map->c++;
			if (map->map_array[y][x] == 'E')
				map->e++;
			if (map->map_array[y][x] == 'P')
			{
				map->p++;
				map->p_y = y;
				map->p_x = x;
			}
		}
	}
	if (map->p != 1 || map->e != 1 || map->c == 0)
		return (FILE_ERROR);
	return (SUCCESS);
}

int	bad_flood(t_map *map)
{
	char	**map_copy;

	map_copy = ft_arraydup(map->map_array);
	map->fill_c = 0;
	map->fill_e = 0;
	fill(map, map_copy, map->p_y, map->p_x);
	ft_free_argv_split(map_copy);
	if (map->fill_c != map->c)
		return (FILE_ERROR);
	if (map->fill_e != map->e)
		return (FILE_ERROR);
	return (SUCCESS);
}
