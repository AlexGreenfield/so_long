/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:04:29 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/09 23:53:24by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_ber(char *arg);
int	find_size(t_map *map);

int	check_ber(char *arg, t_map *map)
{
	//char	*split;

	if (!arg)
		return (FILE_ERROR);
	if (end_ber(arg))
		return (FILE_ERROR);
	map->map_array = NULL;
	map->fd = open(arg, O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	if (find_size(map) != SUCCESS || map->y_size < 3 || map->x_size < 3)
		return (FILE_ERROR);
	ft_printf("map y size is %d\nand x is %d\n", map->y_size, map->x_size);
	close (map->fd);
	return (SUCCESS);
}

int	end_ber(char *arg)
{
	size_t	arg_len;

	arg_len = ft_strlen(arg);
	if (arg_len < 4)
		return (FILE_ERROR);
	return (ft_strncmp (arg + arg_len - 4, ".ber", 4));
}

int	find_size(t_map *map)
{
	char	*temp;

	temp = get_next_line(map->fd);
	if (temp == NULL)
		return (FILE_ERROR);
	map->y_size = 1;
	map->x_size = ft_strlen(temp);
	while (temp)
	{
		if (temp)
			free (temp);
		temp = get_next_line(map->fd);
		if (temp != NULL && ft_strlen(temp) != (size_t)(map->x_size))
		{
			if (temp)
				free (temp);
			return (FILE_ERROR);
		}
		map->y_size++;
	}
	if (temp)
		free (temp);
	map->x_size--;
	map->y_size--;
	return (SUCCESS);
}
