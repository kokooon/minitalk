/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:43:56 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/02 12:13:00 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while (haystack[i] && i < len)
	{
		k = 0;
		while (needle[k] && i + k < len)
		{
			if (haystack[i + k] != needle[k])
				break ;
			k++;
			if (needle[k] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0x0);
}
