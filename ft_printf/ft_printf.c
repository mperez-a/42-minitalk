/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:52:31 by mperez-a          #+#    #+#             */
/*   Updated: 2022/10/28 15:07:00 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_check_format(va_list args, const char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (str == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (str == 'p')
	{
		len += write(1, "0x", 2);
		if (len < 2)
			return (-1);
		len += ft_putptr(va_arg(args, unsigned long long));
	}
	else if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(args, int), len);
	else if (str == 'u')
		len += ft_putnbr(va_arg(args, unsigned int), len);
	else if (str == 'x' || str == 'X')
		len += ft_putnbr_hex(va_arg(args, unsigned int), str, len);
	else if (str == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_str_iter(char const *str, va_list args, int len, int auxlen)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			auxlen = ft_check_format(args, str[i + 1]);
			if (auxlen == -1)
				return (-1);
			len = len + auxlen;
			i++;
		}
		else
		{
			auxlen = ft_putchar(str[i]);
			if (auxlen == -1)
				return (-1);
			len = len + auxlen;
		}
		i++;
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;
	int		auxlen;

	len = 0;
	auxlen = 0;
	va_start(args, str);
	len = ft_str_iter(str, args, len, auxlen);
	va_end(args);
	return (len);
}
