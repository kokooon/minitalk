/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:06:12 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/02 14:39:31 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbchar(int n, int i)
{
	if (n == -2147483648)
		n += 1;
	if (n < 0)
		return (ft_nbchar(-n, i) + 1);
	if (n > 9)
		return (ft_nbchar(n / 10, i + 1));
	if (n <= 9 && n >= 0)
		return (i + 1);
	return (0);
}

static char	*ft_2itoa(int n)
{
	char	*s;
	int		k;
	int		i;

	i = 0;
	k = ft_nbchar(n, 0) - 1;
	s = (char *) malloc(sizeof(char) * (k + 2));
	if (s == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		i = 1;
		n = -2147483647;
	}
	s [ft_nbchar(n, 0)] = '\0';
	n = -n;
	while (k)
	{
		s[k] = 48 + n % 10 + i;
		k--;
		n /= 10;
		i = 0;
	}
	s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		k;
	int		i;

	if (n < 0)
	{
		s = ft_2itoa(n);
		return (s);
	}
	i = 0;
	k = ft_nbchar(n, 0) - 1;
	s = (char *) malloc(sizeof(char) * (k + 2));
	if (s == NULL)
		return (NULL);
	s[ft_nbchar(n, 0)] = '\0';
	while (k >= 0)
	{
		s[k] = 48 + n % 10;
		k--;
		n /= 10;
	}
	return (s);
}
