/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:18:14 by nglaizau          #+#    #+#             */
/*   Updated: 2025/02/07 15:15:59 by nglaizau         ###   ########.fr       */
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
	int	i;
	char	*line;

	i = 0;
	fd = open(filname, O_RDONLY);
	cpy->map_temp = malloc(sizeof(char *) * (cpy->countcolone + 1));
	if (!cpy->map_temp)
		return(exit_error("memory allocation failed\n"));
	line = get_next_line(fd);
	while (line)
	{
		cpy->map_temp[i] = ft_strdup(line);
		//ft_printf("%s\n", cpy->map_temp[i]);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	cpy->map_temp[i] = NULL;
}
void	flood_fil(t_map *map_temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	 while (map_temp->map_temp[j])
	 {
		
	 }

}