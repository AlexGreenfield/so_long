/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:06:12 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/09 23:07:49 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		map = malloc(sizeof(t_map));
		if (!map)
			return (MALLOC_ERROR);
		if (check_ber(argv[1], map) != SUCCESS)
			return (free_main_map(map, FILE_ERROR));
		return (free_main_map(map, SUCCESS));
	}
	else
		write (2, "Error\n", 7);
	return (SUCCESS);
}
