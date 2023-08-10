/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:43:06 by mperez-a          #+#    #+#             */
/*   Updated: 2023/08/10 18:12:01 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lens;
	size_t	lend;

	lend = ft_strlen(dst);
	lens = 0;
	while (dstsize > lend && src[lens] != '\0' && lens < (dstsize - lend - 1))
	{
		dst[lend + lens] = src[lens];
		lens++;
	}
	dst[lend + lens] = '\0';
	lens = ft_strlen(src);
	if (lend >= dstsize)
		return (dstsize + lens);
	else
		return (lend + lens);
}
