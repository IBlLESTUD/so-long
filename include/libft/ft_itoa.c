/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:52:38 by nglaizau          #+#    #+#             */
/*   Updated: 2025/01/08 10:38:12 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	count_len(int nb)
{
	int	res;

	res = 0;
	if (nb <= 0)
	{
		nb = -nb;
		res++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	ncopy;
	int		len;

	len = count_len(n);
	ncopy = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (ncopy < 0)
	{
		ncopy = -ncopy;
		str[0] = '-';
	}
	str[len--] = '\0';
	if (n == 0)
		str[len] = '0';
	while (ncopy > 0)
	{
		str[len] = (ncopy % 10) + '0';
		ncopy /= 10;
		len--;
	}
	return (str);
}
