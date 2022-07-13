/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:09:47 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/01 14:08:52 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*t;

	if (start > ft_strlen(s))
	{
		t = malloc(sizeof(char) * 1);
		if (t == NULL)
			return (NULL);
		t[0] = '\0';
		return (t);
	}
	t = malloc(sizeof(char) * (len + 1));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{	
		t[i] = s[start + i];
		i++;
	}
	t[i] = '\0';
	while (i++ < len)
		t[i] = '\0';
	return (t);
}
