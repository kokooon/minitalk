/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:26:24 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/02 12:12:25 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbmot(char const *str, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
		{
			i++;
			if (str[i] == '\0')
				return (nb);
		}
		while (str[i] && str[i] != c)
			i++;
		nb++;
	}
	return (nb);
}

static int	ft_lenmot(char const *str, char c, int *index)
{
	int	i;

	i = *index;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*ft_petitmalloc(const char *str, char c, int *index)
{
	int		j;
	char	*tab;

	j = 0;
	while (str[*index] && str[*index] == c)
		(*index)++;
	tab = (char *) malloc(sizeof(char) * (ft_lenmot(str, c, index) + 1));
	if (tab == 0x0)
		return (0x0);
	while (str[*index] && str[*index] != c)
	{
		tab[j] = str[*index];
		(*index)++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	int		n;
	int		nb;
	char	**tab;
	int		index;

	index = 0;
	nb = ft_nbmot(s, c);
	tab = malloc(sizeof(*tab) * (nb + 1));
	if (!tab)
		return (NULL);
	n = 0;
	while (n < nb)
	{
		tab[n] = ft_petitmalloc(s, c, &index);
		n++;
	}
	tab[n] = (NULL);
	return (tab);
}
