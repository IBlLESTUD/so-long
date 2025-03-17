/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:09:33 by nglaizau          #+#    #+#             */
/*   Updated: 2025/03/06 16:30:20 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ESC_KEY 65307

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "include/header/get_next_line.h"
# include "include/header/libft.h"
# include "include/header/ft_printf.h"
# include <mlx.h>

typedef struct s_map
{
	char	**map;
	char	**map_temp;
	int		countcolone;
	int		start_i;
	int		start_j;
}	t_map;
typedef struct s_game
{
	int 	height;
	int		width;
	void	*mlx;
	char	**map;
	void	*window;
}	t_game;
void		exit_error(char *str);
void		check_fd(t_map *map, char *filename);
void		check_element(t_map *map);
void		mapcpy(t_map *cpy, char *filname);
void		check_element2(t_map *map);
void		check_element3(t_map *map);
void		check_wall(t_map *map);
void		check_wall2(t_map *map);
void		ft_is_a_rectangle(t_map *map);
void		check_starting_point(t_map *cpy);
void		temp_map(t_map *cpy, char *filname);
void		flood_fil(t_map *cpy, int i, int j);
void		check_flood(t_map *cpy);
void		mlx_window(t_game *game, char **map);
//int			handle_keypress(int keycode);
//void		all_collectible(t_map *cpy);

#endif