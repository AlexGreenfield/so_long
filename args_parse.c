/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:04:29 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/09 18:04:42 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_ber(char *arg);

int	check_ber(char *arg, t_map *map)
{
	//char	*split;

	if (!arg)
		return (FILE_ERROR);
	if (!end_ber(arg))
		return (FILE_ERROR);
	map->map_array = NULL;
	map->fd = open(arg[1], O_RDONLY);
	if (map->fd < 0)
		return (FILE_ERROR);
	//int	i;
	//i = 0;
	//while (i < 8)
	//{
		//split = get_next_line(map->fd);
		//ft_printf("string is %s\n", split);
		//free (split);
		//i++;
	//}
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
