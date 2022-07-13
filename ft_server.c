/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:18:07 by gmarzull          #+#    #+#             */
/*   Updated: 2022/07/12 18:09:55 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_handler(int signum, siginfo_t *info, void *nullpointer)
{
	static int				i = 0;
	static unsigned char	buffer = 0;
	static pid_t			pid = 0;

	(void)nullpointer;
	pid = info->si_pid;
	buffer = buffer | (signum == SIGUSR1);
	if (++i == 8)
	{
		if (buffer != 0)
			ft_putchar_fd(buffer, 1);
		else
		{
			kill(pid, SIGUSR2);
			write(1, "\n", 1);
		}
		buffer = 0;
		i = 0;
	}
	else
		buffer <<= 1;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	pid = getpid();
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = server_handler;
	write(1, "Starting Server...\n", 19);
	write (1, "PID = ", 7);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &sig, NULL) != 0
		|| sigaction(SIGUSR2, &sig, NULL) != 0)
	{
		write(1, "Error.\n", 7);
		return (1);
	}
	while (1)
		pause();
	return (0);
}
