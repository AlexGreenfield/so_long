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
int	find_size(t_map *map, char *arg);

int	check_ber(char *arg, t_map *map)
{

	if (!arg)
		return (FILE_ERROR);
	if (end_ber(arg))
		return (FILE_ERROR);
	if (find_size(map, arg) != SUCCESS || map->y_size < 4 || map->x_size < 4)
		return (FILE_ERROR);
	ft_printf("X is %d\nY is %d\n", map->x_size, map->y_size);
	//if (allocate_map(map) != SUCCESS)
		//return (FILE_ERROR);
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

int	find_size(t_map *map, char *arg)
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
