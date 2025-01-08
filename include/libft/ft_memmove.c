/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:44:21 by nglaizau          #+#    #+#             */
/*   Updated: 2025/01/08 10:38:12 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptrr;

	if (!dest && !src)
		return (NULL);
	ptr = dest;
	ptrr = src;
	if (ptr < ptrr)
	{
		while (n--)
			*ptr++ = *ptrr++;
	}
	else
	{
		while (n--)
			ptr[n] = ptrr[n];
	}
	return (dest);
}
