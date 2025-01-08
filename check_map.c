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

void	check_fd(char	*filename)
{
	int fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (!fd)
		return (exit_error("can't open this file"));
	line = get_next_line(fd);
	if (!line)
		return (exit_error("file is empty"));
	close(fd);
}

