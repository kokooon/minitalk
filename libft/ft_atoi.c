/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:13:01 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/01 14:42:03 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		r;
	int		n;

	s = (char *)str;
	n = 1;
	i = 0;
	r = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (s[i] == '-')
	{
		n = -n;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] > 47 && s[i] < 58)
	{
		r = 10 * r + s[i] - '0';
		i++;
	}
	return (r * n);
}
