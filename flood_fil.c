/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:18:14 by nglaizau          #+#    #+#             */
/*   Updated: 2025/02/27 19:17:09 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		check_starting_point(t_map *cpy)
{
	int	i;
	int	j;
	
	cpy->start_i = 0;
	cpy->start_j = 0;
	j = 0;
	while (cpy->map[j])
	{
		i = 0;
		while (cpy->map[j][i])
		{
			if (cpy->map[j][i] == 'P')
			{
				cpy->start_i = i;
				cpy->start_j = j;
				break;
			}
			i++;
		}
		j++;
	}
	if (cpy->start_i == 0 && cpy->start_j == 0)
		return (exit_error("starting point doses not exist"));

}
void	temp_map(t_map *cpy, char *filname)
{
	int	fd;
	int	j;
	char	*line;

	j = 0;
	fd = open(filname, O_RDONLY);
	cpy->map_temp = malloc(sizeof(char *) * (cpy->countcolone + 1));
	if (!cpy->map_temp)
		return(exit_error("memory allocation failed\n"));
	line = get_next_line(fd);
	while (line)
	{
		cpy->map_temp[j] = ft_strdup(line);
		//ft_printf("%s\n", cpy->map_temp[j]);
		j++;
		free(line);
		line = get_next_line(fd);
	}
	cpy->map_temp[j] = NULL;
}
void	flood_fil(t_map *cpy, int i, int j)
{
	if (j < 0 || i < 0 || j >= cpy->countcolone || 
			i >= (int)ft_strlen(cpy->map_temp[j]) ||
			cpy->map_temp[j][i] == '1'|| 
			cpy->map_temp[j][i] == 'V')
			return ;
	cpy->map_temp[j][i] = 'V';
	flood_fil(cpy, i + 1, j);
	flood_fil(cpy, i - 1, j);
	flood_fil(cpy, i, j + 1);
	flood_fil(cpy, i, j - 1);
}
void	check_flood(t_map *cpy)
{
	int	i;
	int	j;

	j = 0;
	while (cpy->map_temp[j])
	{
		i = 0;
		while (cpy->map_temp[j][i])
		{	
			if (cpy->map_temp[j][i] == 'C')
				return (exit_error("not all collectibles can be collected"));
			//  if (cpy->map[j][i] == 'E')
			// 	return (exit_error("the exit is not reachable"));
			i++;
		}
		j++;
	}
}
