/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:18:14 by nglaizau          #+#    #+#             */
/*   Updated: 2025/02/06 19:13:26 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		check_starting_point(t_map *cpy)
{
	int	i;
	int	j;
	
	cpy->start_i = 0;
	cpy->start_j = 0;
	i = 0;
	j = 0;
	while (cpy->map[j])
	{
		i = 0;
		while (cpy->map[j][i])
		{
			if (cpy->map[j][i] == 'P')
			{
				ft_printf("jgd");
				cpy->start_i = i;
				cpy->start_j = j;
				break;
			}
			i++;
		}
		j++;
	}
	ft_printf("%d", j);
	ft_printf("%d", i);
	if (cpy->start_i == 0 && cpy->start_j == 0)
		return (exit_error("starting point doses not exist"));
	
}