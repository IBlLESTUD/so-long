/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:18:47 by nglaizau          #+#    #+#             */
/*   Updated: 2025/01/08 12:31:02 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_before(stash);
	stash = ft_after(stash);
	if (line[0] == '\0')
	{
		ft_free(line, stash);
		return (NULL);
	}
	return (line);
}

char	*ft_read(int fd, char *stash)
{
	char	*line;
	int		vals;
	char	*temp;

	if (!stash)
		stash = ft_strdup("");
	vals = 1;
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (!ft_strchr(stash, '\n') && vals != 0)
	{
		vals = read(fd, line, BUFFER_SIZE);
		if (vals == -1)
			return (ft_free(line, stash));
		line[vals] = '\0';
		temp = ft_strjoin(stash, line);
		free(stash);
		stash = temp;
	}
	free(line);
	return (stash);
}

void	*ft_free(char *stash, char *line)
{
	free(stash);
	free(line);
	return (NULL);
}

char	*ft_before(char *stash)
{
	char	*temp;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		temp[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		temp[i] = '\n';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_after(char *stash)
{
	char	*newstash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	newstash = malloc(sizeof(char) * ft_strlen(stash) - i + 1);
	i++;
	j = 0;
	while (stash[i])
	{
		newstash[j] = stash[i];
		j++;
		i++;
	}
	free(stash);
	newstash[j] = '\0';
	return (newstash);
}
// int	main()
// {
// 	int	fd;
// 	char	*line;
// 	fd = open("get_next_line.c", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }