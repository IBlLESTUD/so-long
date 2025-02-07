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

void	exit_error(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	check_fd(t_map *map, char *filename)
{
	int fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (exit_error("can't open this file"));
	line = get_next_line(fd);
	if (!line)
		return (exit_error("file is empty"));
	map->countcolone = 0;
	while (line)
	{
		map->countcolone++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	mapcpy(t_map *cpy, char *filname)
{
	int	fd;
	int	j;
	char	*line;

	j = 0;
	fd = open(filname, O_RDONLY);
	cpy->map = malloc(sizeof(char *) * (cpy->countcolone + 1));
	if (!cpy->map)
		return(exit_error("memory allocation failed\n"));
	line = get_next_line(fd);
	while (line)
	{
		cpy->map[j] = ft_strdup(line);
		//ft_printf("%s\n", cpy->map[j]);
		j++;
		free(line);
		line = get_next_line(fd);
	}
	cpy->map[j] = NULL;
}

void	check_element(t_map *map)
{
	int	i;
	int	j;
	int e;

	i = 0;
	j = 0;
	e = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] != '1' && map->map[j][i] != '0' && map->map[j][i] != 'E' && map->map[j][i] != 'P' && map->map[j][i] !='C' && map->map[j][i] != '\n')
				return (exit_error("invalid map"));
			i++;
		if (map->map[j][i] == 'E')
				e++;
		}
		j++;
	}
	if (e != 1)
		return (exit_error("invlid Map"));
}

void	check_element2(t_map *map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] == 'C')
				c++;
			i++;
		}
		j++;
	}
	if (c < 1)
		return (exit_error("invalin map"));
}
