/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nglaizau <nglaizau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:10:22 by nglaizau          #+#    #+#             */
/*   Updated: 2025/01/08 10:39:11 by nglaizau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	print_verif(const char *str, va_list args, int i)
{
	int	count;

	count = 0;
	if (str[i] == '%')
		return (ft_putchar(str[i]));
	else if (str[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (str[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (str[i] == 'u')
		count += ft_unputnbr(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		count += ft_puthex_low(va_arg(args, unsigned int));
	else if (str[i] == 'X')
		count += ft_puthex_upp(va_arg(args, unsigned int));
	else if (str[i] == 'p')
		count += ft_putptr(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += print_verif(str, args, i);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
