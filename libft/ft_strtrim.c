/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:22:46 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/02 12:13:11 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_begin(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			return (i);
		i++;
		j = 0;
	}
	return (0);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	j = 0;
	while (i < len)
	{
		while (set[j])
		{
			if (s1[len - i] == set[j])
				break ;
			j++;
		}
		if (s1[len - i] != set[j])
			return (len - i + 1);
		i++;
		j = 0;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_end(s1, set) - ft_begin(s1, set);
	s = malloc(sizeof(char) * (size + 1));
	if (s == 0x0)
		return (0x0);
	while (i < size)
	{
		s[i] = s1[ft_begin(s1, set) + i];
		i++;
	}
	s[i] = 0;
	return (s);
}
