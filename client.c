/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:15:14 by jchu              #+#    #+#             */
/*   Updated: 2023/02/16 00:14:00 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	com(int sig)
{
	(void)sig;
	ft_putstr_fd("Done", 1);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result += str[i] - '0';
		result *= 10;
		i++;
	}
	result /= 10;
	return (result * sign);
}

void	send_char_to_server(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(50);
	}
}

void	send_string_to_server(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_char_to_server(pid, str[i++]);
	send_char_to_server(pid, 0);
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_putstr_fd("Failure : Wrong amount of inputs\n", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_putstr_fd("Failure : Wrong PID\n", 1);
		return (0);
	}
	signal(SIGUSR2, com);
	send_string_to_server(pid, argv[2]);
	return (0);
}
