/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:02:42 by nglaizau          #+#    #+#             */
/*   Updated: 2025/03/06 17:18:39 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_window(t_game *game, char **map)
{
 	game->mlx = mlx_init();
	if (!game->mlx)
		return (exit_error("failure"));
	gameNathan Glaizaud
ight = 0;
	while (map[game->height])
		game->height++;
	game->width = ft_strlen(map[0]);
	game->window = mlx_new_window(game->mlx, game->width * 64,
								game->height * 64, "so_long");
}
int	handle_keypress(int keycode, )
{
	if (keycode == ESC_KEY)
		exit(0);
	return (0);
}
