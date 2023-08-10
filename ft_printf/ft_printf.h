/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:34:46 by mperez-a          #+#    #+#             */
/*   Updated: 2022/10/24 11:26:26 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_putchar(int c);
int		ft_check_format(va_list args, const char str);
int		ft_put_percent(void);
int		ft_print_str(char *str);
int		ft_putnbr(long long int n, int len);
int		ft_putnbr_hex(unsigned int n, const char str, int len);
int		ft_putptr(unsigned long long n);

#endif
