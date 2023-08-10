/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:59:06 by mperez-a          #+#    #+#             */
/*   Updated: 2023/08/10 18:11:13 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long int n, int len)
{
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n *= -1;
		len++;
	}
	if (n >= 10)
	{
		len = ft_putnbr((n / 10), len);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_putnbr_hex(unsigned int n, const char str, int len)
{
	char	hex;

	if (str == 'X')
		hex = 'A';
	else
		hex = 'a';
	if (n >= 16)
	{
		len = ft_putnbr_hex((n / 16), str, len);
		if (len == -1)
			return (-1);
	}
	if (n % 16 <= 9)
	{
		if (ft_putchar((n % 16) + '0') == -1)
			return (-1);
		len++;
	}
	else
	{
		if (ft_putchar(((n % 16) - 10) + hex) == -1)
			return (-1);
		len++;
	}
	return (len);
}
