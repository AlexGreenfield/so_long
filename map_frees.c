/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_frees.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:51:26 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/09 17:58:30 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_main_map(t_map *map, int flag)
{
	free (map);
	if (flag != SUCCESS)
		write (2, "Error\n", 7);
	return (flag);
}
