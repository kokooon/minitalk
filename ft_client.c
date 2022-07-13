/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:18:01 by gmarzull          #+#    #+#             */
/*   Updated: 2022/07/12 17:53:11 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_confirmation(pid_t sig)
{
	if (sig == SIGUSR2)
		write(1, "Message send.\n", 14);
}

void	send_char(char c, pid_t pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc != 3)
	{
		if (argc < 3)
			write(1, "Too few arguments.\n", 19);
		else if (argc > 3)
			write(1, "Too many arguments.\n", 20);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR2, client_confirmation);
	while (i < ft_strlen(argv[2]))
	{
		send_char(argv[2][i], pid);
		i++;
	}
	send_char('\0', pid);
	return (0);
}
