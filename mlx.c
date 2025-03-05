/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:02:42 by nglaizau          #+#    #+#             */
/*   Updated: 2025/03/05 22:43:27 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_window(t_game *game, char **map)
{
 	game->mlx = mlx_init();
	if (!game->mlx)
		return (exit_error("failure"));
	game->map = map;
	game->height = 0;
	while (map[game->height])
		game->height++;
	game->width = ft_strlen(map[0]);
	game->window = mlx_new_window(game->mlx, game->width * 64,
								game->height * 64, "so_long");
}
//int
