/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:26:24 by nglaizau          #+#    #+#             */
/*   Updated: 2025/01/20 11:31:38 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map map;

	// map = malloc(sizeof(t_map));
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
}