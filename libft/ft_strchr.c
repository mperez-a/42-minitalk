/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:59:03 by mperez-a          #+#    #+#             */
/*   Updated: 2022/11/01 15:07:15 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	c = (char)c;
	while (*ptr != '\0')
	{
		if (*ptr == c)
		{
			return (&(*ptr));
		}
		ptr++;
	}
	if (*ptr == c)
		return (&(*ptr));
	return (NULL);
}
