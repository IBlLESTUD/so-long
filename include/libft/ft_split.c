/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:15:38 by nglaizau          #+#    #+#             */
/*   Updated: 2025/01/08 10:38:12 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static	int	ft_count_word(char const *s, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		if (s[i])
			j++;
		while (s[i] != sep && s[i])
			i++;
	}
	return (j);
}

static	char	*ft_cpy(char **res, const char *s, char sep)
{
	int	len;

	while (*s)
	{
		len = 0;
		while (*s == sep && *s)
			s++;
		while (*s != sep && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			*res = malloc(len + 1);
			if (*res == NULL)
				return (NULL);
			ft_strlcpy(*res, s - len, len + 1);
			res++;
		}
	}
	return (*res);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**res;

	if (!s)
		return (NULL);
	word = ft_count_word(s, c);
	res = malloc(sizeof(char *) * (word + 1));
	if (!res)
		return (NULL);
	res[word] = NULL;
	ft_cpy(res, s, c);
	return (res);
}
// int	main()
// {
// 	const char s[] = "ils ont plante happy";
// 	char c = ' ';
// 	char **res = ft_split(s, c);

// 	while (*res)
// 	{
// 		printf("%s\n", *res);
// 		res++;
// 	}
// 	return 0;
// }