/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:18:26 by jchu              #+#    #+#             */
/*   Updated: 2023/02/15 23:38:27 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

/* Utils */
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);

/* Client */
int		ft_atoi(const char *str);
void	send_char_to_server(int pid, char c);
void	send_string_to_server(int pid, char *str);
void	com(int sig);

/* Server */
void	handler(int signal, siginfo_t *client, void *context);

#endif