/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:30:10 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/10 19:38:55 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_set_char(char	*line)
{
	ssize_t	string_size;
	char	*set;

	if (!line)
		return (0);
	string_size = 0;
	set = "10PCE";
	while (*line && *line != '\n')
	{
		if (!ft_strchr(set, *line))
			return (FILE_ERROR);
		string_size++;
		line++;
	}
	return (string_size);
}
