/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:06:24 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/01 12:55:20 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tab;

	tab = (t_list *) malloc(sizeof(t_list));
	if (!tab)
		return (NULL);
	tab ->content = (void *) content;
	tab ->next = NULL;
	return (tab);
}
