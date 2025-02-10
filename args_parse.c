/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:56:57 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/10 21:05:34 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bad_ber(char *arg);
int	bad_size(t_map *map, char *arg);
int	allocate_map(t_map *map, char *arg);

int	check_ber(char *arg, t_map *map)
{
	if (!arg)
		return (FILE_ERROR);
	if (bad_ber(arg))
		return (FILE_ERROR);
	if (bad_size(map, arg) || map->y_size < 3 || map->x_size < 3)
		return (FILE_ERROR);
	ft_printf("X is %d\nY is %d\n", map->x_size, map->y_size);
	if (allocate_map(map, arg) != SUCCESS)
		return (FILE_ERROR);
	int	i;
	i = 0;
	while (map->map_array[i])
	{
		printf("%s", map->map_array[i]);
		i++;
	}
	return (free_map_array(map, SUCCESS));
	//return (SUCCESS);
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
	int	i;

	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	map->map_array = malloc ((map->y_size + 1) * sizeof(char *));
	if (!map->map_array)
		return (MALLOC_ERROR);
	i = -1;
	while (i++ < map->y_size)
	{
		map->map_array[i] = get_next_line(map->fd); // Alloc of x size for each i to avoid \n jump?
		if (!map->map_array)
			return (free_map_array(map, MALLOC_ERROR));
	}
	//map->map_array[i] = NULL;
	close(map->fd);
	return (SUCCESS);
}
