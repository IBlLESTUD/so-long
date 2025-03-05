/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:26:24 by nglaizau          #+#    #+#             */
/*   Updated: 2025/03/05 22:43:12 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_game	game;

	if (ac != 2)
	{
		ft_printf("ERROR\nits not 2 arguments");
		return (0);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", '0'))
	{
		ft_printf("ERROR\nits not .ber\n");
		return (0);
	}
	check_fd(&map, "map.ber");
	mapcpy(&map, "map.ber");
	check_element(&map);
	check_element2(&map);
	check_element3(&map);
	check_wall(&map);
	ft_is_a_rectangle(&map);
	check_wall2(&map);
	check_starting_point(&map);
	temp_map(&map, "map.ber");
	flood_fil(&map, map.start_i, map.start_j);
	check_flood(&map);
	mlx_window(&game, map.map);
}
//void ()
// 	int	i;

// 	i = 0;
// 	while (map.map_temp[i])
// 	{
// 		ft_printf(map.map_temp[i]);
// 		i++;
// 	}

// }
