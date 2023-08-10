/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:55:41 by mperez-a          #+#    #+#             */
/*   Updated: 2023/03/09 17:02:35 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*elem;
	void	*ptr;

	new_list = 0;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		ptr = (f)(lst->content);
		elem = ft_lstnew(ptr);
		if (!elem)
		{
			ft_lstclear(&new_list, del);
			free(ptr);
			return (NULL);
		}
		ft_lstadd_back(&new_list, elem);
		lst = lst->next;
	}
	return (new_list);
}
