/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:09:33 by nglaizau          #+#    #+#             */
/*   Updated: 2025/03/17 11:09:01 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

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
	int		player_x;
	int		player_y;
	int		new_y;
	int		nex_x;
	int		count;
	int		collected;
	int		total_collected;
	void	*floor;
	void	*wall;
	void	*player;
	void	*col;
	void	*exit;
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
int			handle_keypress(int keycode, t_game *game);
//void		all_collectible(t_map *cpy);
void		moove(t_game *g, int new_x, int new_y);
int			exit_game(t_game *game, int flag);

#endif