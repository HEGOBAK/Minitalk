/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:15:38 by jchu              #+#    #+#             */
/*   Updated: 2023/02/16 16:50:09 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *client, void *context)
{
	static int	c;
	static int	shift;

	(void)context;
	if (signal == SIGUSR1)
		c += 1;
	shift++;
	if (shift == 8)
	{
		if (c == 0)
		{
			kill(client->si_pid, SIGUSR2);
			ft_putchar_fd('\n', 1);
		}
		else
			write (1, &c, 1);
		shift = 0;
		c = 0;
	}
	else
		c <<= 1;
	usleep(20);
}

// void	handler(int sig, siginfo_t *info, void *context)
// {
// 	static int	msg;
// 	static int	count;

// 	(void)context;
// 	if (sig == SIGUSR1)
// 		msg += 1;
// 	if (++count == 8)
// 	{
// 		if (msg == 0)
// 			kill(info->si_pid, SIGUSR2);
// 		else
// 			write(1, &msg, 1);
// 		msg = 0;
// 		count = 0;
// 	}
// 	else
// 		msg <<= 1;
// 	usleep(20);
// }

int	main(void)
{
	struct sigaction	sig;

	ft_putnbr_fd(getpid(), 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
