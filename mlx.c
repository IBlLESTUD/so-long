/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:02:42 by nglaizau          #+#    #+#             */
/*   Updated: 2025/03/17 11:57:35 by nglaizau         ###   ########.fr       */
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
	mlx_key_hook(game->window, handle_keypress, game);
	mlx_hook(game->window, 17, 0, exit_game, game);
	
}
int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		exit_game(game, 0);
	else if (keycode == W_KEY && game->player_y > 0)
		moove(game, game->player_x, game->player_y -1);
	else if (keycode == A_KEY && game->player_x > 0)
		moove(game, game->player_y, game->player_x -1);
	else if (keycode == S_KEY && game->player_y < game->height)
		moove(game, game->player_x, game->player_y + 1);
	else if (keycode == D_KEY && game->player_x < game->width)
		moove(game, game->player_y, game->player_x + 1);
	return (0);
}
void	moove(t_game *g, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= g->width || new_y vois< 0 || new_y > g->height)
		return ;
	if (g->map[new_y][new_x] == '1')
		return ;
	ft_printf("moove player : %d\n", g->count);
	if (g->map[new_y][new_x] == 'C')
	{
		g->map[new_y][new_x] = '0';
		g->collected++;
	}
	if (g->map[new_y][new_x] == 'E')
	{
		if (g->collected == g->total_collected)
		{
			ft_printf("YOU WIN");
			exit_game(g, 0);
		}
		return ;
	}
	g->map[g->player_y][g->player_x] = '0';
	g->map[new_y][new_x] = 'P';
	g->player_y = new_y;
	g->player_x = new_x;
	g->count++;
}
int exit_game(t_game *game, int flag)
{
	ft_printf("ggg");
	// if (game->floor)
	// 	mlx_destroy_image(game->mlx, game->floor);
	// if (game->wall)
	// 	mlx_destroy_image(game->mlx, game->wall);
	// if (game->player)
	// 	mlx_destroy_image(game->mlx, game->player);
	// if (game->col)
	// 	mlx_destroy_image(game->mlx, game->col);
	// if (game->exit)
	// 	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(flag);
	return (0);
}
