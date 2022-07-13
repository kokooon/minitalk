/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:49:30 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/01 18:39:51 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_clear(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newelem;

	if (!lst || !f)
		return (NULL);
	newelem = ft_lstnew(f(lst->content));
	if (!newelem)
		return (ft_clear(&lst, del));
	newlist = newelem;
	lst = lst->next;
	while (lst)
	{
		newelem = ft_lstnew(f(lst->content));
		if (!newelem)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&newlist, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&newlist, newelem);
	}
	return (newlist);
}
