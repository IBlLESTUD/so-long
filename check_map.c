/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 02:52:21 by nglaizau          #+#    #+#             */
/*   Updated: 2025/01/08 02:56:14 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_error(char *str)
{
	ft_printf("Error\n%s\n", str);
	return (-1);
}

int	check_fd(t_map *map, char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (!fd)
		return (exit_error("can't open this file"));
	map->line = get_next_line(fd);
	if (!map->line)
		return (exit_error("file is empty"));
	map->countcolone = 0;
	while (map->line)
	{
		free(map->line);
		map->countcolone++;
		map->line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int		mapcpy(t_map *cpy, char *filname)
{
	int	fd;
	int	i;
	char	*line;

	i = 0;
	fd = open(filname, O_RDONLY);
	cpy->map = malloc(sizeof(char *) * cpy->countcolone + 1	);
	line = get_next_line(fd);
	while (line)
	{
		cpy->map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	cpy->map[i] = NULL;
	return (0);


}

int	check_element(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[i])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != 'E' && map->map[i][j] != 'P' && map->map[i][j] !='C') 
				return (exit_error("invalid map"));
			i++;
		}
		j++;
	}
	return(0);
 }