/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:09:33 by mperez-a          #+#    #+#             */
/*   Updated: 2022/09/29 11:42:45 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;

	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n)
	{
		if (*ptrs1 == *ptrs2)
		{
			n--;
			ptrs1++;
			ptrs2++;
		}
		else if (*ptrs1 > *ptrs2 || *ptrs1 < *ptrs2)
			return (*ptrs1 - *ptrs2);
	}
	return (0);
}
