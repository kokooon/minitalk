/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:16:51 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/01 13:30:20 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		i;
	size_t		j;

	if (ft_strlen((char *) s1) + ft_strlen((char *) s2) == 0)
	{
		s3 = malloc(sizeof(char));
		*s3 = 0;
		return (s3);
	}
	s3 = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (s3 == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}
