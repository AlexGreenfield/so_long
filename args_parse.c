/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:44:14 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/10 23:07:45y alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bad_ber(char *arg);
int	bad_size(t_map *map, char *arg);
int	allocate_map(t_map *map, char *arg);
int	bad_walls(t_map *map);

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

	ft_printf("X is %d\nY is %d\n", map->x_size, map->y_size);
	int	i;
	i = 0;
	while (map->map_array[i])
	{
		printf("%s\n", map->map_array[i]);
		i++;
	}
	return (free_map_array(map, SUCCESS));
}

int	bad_ber(char *arg)
{
	size_t	arg_len;

	arg_len = ft_strlen(arg);
	if (arg_len < 4)
		return (FILE_ERROR);
	return (ft_strncmp (arg + arg_len - 4, ".ber", 4));
}

int	bad_size(t_map *map, char *arg)
{
	char	*temp;
	int		flag;

	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	flag = SUCCESS;
	temp = get_next_line(map->fd);
	if (temp == NULL)
		flag = FILE_ERROR;
	map->y_size = 1;
	map->x_size = len_set_char(temp);
	while (temp)
	{
		if (temp)
			free (temp);
		temp = get_next_line(map->fd);
		if (temp != NULL && (len_set_char(temp) != map->x_size))
			flag = FILE_ERROR;
		map->y_size++;
	}
	close(map->fd);
	map->y_size--;
	return (flag);
}

int	allocate_map(t_map *map, char *arg)
{
	int		i;
	char	*temp;

	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	map->map_array = malloc ((map->y_size + 1) * sizeof(char *));
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
		free (temp);
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
