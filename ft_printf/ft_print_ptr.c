/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:50:46 by mperez-a          #+#    #+#             */
/*   Updated: 2022/10/24 11:54:45 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += (write(1, "0", 1));
	else
	{
		if (ptr >= 16)
		{
			len += ft_putptr(ptr / 16);
			len += ft_putptr(ptr % 16);
		}
		else
		{
			if (ptr < 10)
				len += ft_putchar(ptr + '0');
			else
				len += ft_putchar((ptr - 10) + 'a');
		}
	}
	return (len);
}
