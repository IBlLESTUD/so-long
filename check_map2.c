/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:35:44 by nglaizau          #+#    #+#             */
/*   Updated: 2025/01/27 16:14:46 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_element3(t_map *map)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] == 'P')
				p++;
			i++;
		}
		j++;
	}
	if (p !=  1)
		return (exit_error("invalid map"));
}
void	checkWall(t_map *map)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (map->map[j][i])
	{
		if (map->map[j][i] != '1' && map->map[j][i] != '\n')
			return exit_error("lack of wall");
		i++;
	}
	i = 0;
	while (map->map[j])
		j++;
	j--;
	//ft_printf("%d\n", j);
	while (map->map[j][i])
	{	
		if (map->map[j][i] != '1' && map->map[j][i] != '\n')
			return exit_error("lack of Wall");
		i++;
	}
}
void	checkWall2(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (map->map[j])
	{
		if ((map->map[j][i] != '1'))
			return (exit_error("lack of Wall"));
		j++;
	}
	j = 0;
	while (map->map[j][i] != '\n')
	{
		i++;
	}
	 i--;
	while (map->map[j])
	{
		if ((map->map[j][i] != '1'))
			return (exit_error("lack of Wwall"));
		j++;
		//ft_printf("%d\n", i);
		//printf("%d\n", j);
	}
}
void	ft_is_a_recantgle(t_map *map)
{
	int	i;
	int	j;
	int	t;
	
	i = 0;
	j = 0;
	t = 0;
	while (map->map[j][i] != '\n')
		i++;
	j = 1;
	while (map->map[j][t])
	{
		t++;
		if (map->map[j][t] == '\n' || map->map[j][t] == '\0')
		{	
			// ft_printf("%d\n", t);
			// ft_printf("%d pour i \n", i);
			if (t != i)
				return (exit_error("is not a rectangle"));
			j++;
			t = 0;
			//ft_printf("%d", j);
		}
	}
}

