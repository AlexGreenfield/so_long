/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:06:12 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/09 16:16:39 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{

	if (argc == 2)
	{
		char	*split;
		int		fd;
		int		i;

		i = 0;
		fd =	open(argv[1], O_RDONLY);
		while (i < 8)
		{
		split = get_next_line(fd);
		ft_printf("string is %s\n", split);
		free (split);
		i++;
		}
		close (fd);
	}
	else
		write (2, "Please, just load one .ber map\n", 32);
	return (SUCCESS);
}