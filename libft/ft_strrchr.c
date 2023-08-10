/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:41:50 by mperez-a          #+#    #+#             */
/*   Updated: 2022/10/01 11:03:43 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	c = (char)c;
	i = ft_strlen(ptr);
	while (i >= 0)
	{
		if (ptr[i] == c)
		{
			return (&ptr[i]);
		}
		i--;
	}
	return (NULL);
}
