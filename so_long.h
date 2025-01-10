/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:09:33 by nglaizau          #+#    #+#             */
/*   Updated: 2025/01/10 14:08:36 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "include/header/get_next_line.h"
# include "include/header/libft.h"
# include "include/header/ft_printf.h"

typedef struct	s_map 
{
	char	**map;
	char	*line;
	int		countcolone;
}	t_map;
int		exit_error(char *str);
int		check_fd(t_map *map, char *filename);
int		check_element(t_map *map);
int		mapcpy(t_map *cpy, char *filname);

#endif