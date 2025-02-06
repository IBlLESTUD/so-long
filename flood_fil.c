/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:18:14 by nglaizau          #+#    #+#             */
/*   Updated: 2025/02/06 18:22:51 by nglaizau         ###   ########.fr       */
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
		if (cpy->map[j][i] == 'P')
		{
			
		}
	}
	
}