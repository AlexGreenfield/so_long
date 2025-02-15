/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:30:10 by alejandro         #+#    #+#             */
/*   Updated: 2025/02/15 16:25:39 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		bad_ber(char *arg);
int		bad_size(t_map *map, char *arg);
void	fill(t_map *map, char **map_array, int y, int x);
char	**ft_arraydup(char **argv);

int	len_set_char(char *line)
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

int	bad_ber(char *arg)
{
	size_t	arg_len;

	arg_len = ft_strlen(arg);
	if (arg_len < 4)
		return (FILE_ERROR);
	return (ft_strncmp(arg + arg_len - 4, ".ber", 4));
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
			free(temp);
		temp = get_next_line(map->fd);
		if (temp != NULL && (len_set_char(temp) != map->x_size))
			flag = FILE_ERROR;
		map->y_size++;
	}
	close(map->fd);
	map->y_size--;
	return (flag);
}

void	fill(t_map *map, char **map_array, int y, int x)
{
	if (x < 0 || y < 0 || x >= map->x_size || y >= map->y_size)
		return ;
	if (map_array[y][x] == '1')
		return ;
	if (map_array[y][x] == 'C')
		map->fill_c++;
	if (map_array[y][x] == 'E')
	{
		map->fill_e++;
		map_array[y][x] = '1';
		return ;
	}
	map_array[y][x] = '1';
	fill(map, map_array, y, x + 1);
	fill(map, map_array, y, x - 1);
	fill(map, map_array, y + 1, x);
	fill(map, map_array, y - 1, x);
}
