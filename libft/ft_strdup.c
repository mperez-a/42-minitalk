/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:21:08 by mperez-a          #+#    #+#             */
/*   Updated: 2022/10/26 16:18:12 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	ptr1 = (char *)s1;
	ptr2 = (char *)malloc(ft_strlen(ptr1) + 1);
	i = 0;
	if (!ptr2)
		return (NULL);
	while (ptr1[i] != '\0')
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	ptr2[i] = '\0';
	return (ptr2);
}
