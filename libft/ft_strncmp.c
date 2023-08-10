/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:16:05 by mperez-a          #+#    #+#             */
/*   Updated: 2022/09/30 15:48:20 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*sc1;
	unsigned char	*sc2;

	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	while ((*sc1 || *sc2) && n)
	{
		if (*sc1 == *sc2)
		{
			n--;
			sc1++;
			sc2++;
		}
		else if (*sc1 > *sc2 || *sc1 < *sc2)
		{
			return (*sc1 - *sc2);
		}
	}
	return (0);
}
