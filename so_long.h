/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:09:33 by nglaizau          #+#    #+#             */
/*   Updated: 2025/02/06 18:17:53 by nglaizau         ###   ########.fr       */
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
	int		countcolone;
	int		start_i;
	int		start_j;
}	t_map;

void		exit_error(char *str);
void		check_fd(t_map *map, char *filename);
void		check_element(t_map *map);
void		mapcpy(t_map *cpy, char *filname);
void		check_element2(t_map *map);
void		check_element3(t_map *map);
void		checkWall(t_map *map);
void		checkWall2(t_map *map);
void		ft_is_a_rectangle(t_map *map);
void		check_starting_point(t_map *cpy);
#endif