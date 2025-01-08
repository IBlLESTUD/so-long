/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:35:11 by nglaizau          #+#    #+#             */
/*   Updated: 2025/01/08 10:39:11 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_puthex_upp(unsigned int n)
{
	char	*hexa;
	int		len;

	len = 0;
	hexa = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_puthex_upp(n / 16);
	ft_putchar(hexa[n % 16]);
	len++;
	return (len);
}
