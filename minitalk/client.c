/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:29:03 by junghkim          #+#    #+#             */
/*   Updated: 2021/11/01 00:54:58 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 1);
	exit(0);
}

void	ft_binary_send(int s_id, char msg)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & msg)
		{
			if (kill(s_id, SIGUSR1) == -1)
				ft_error("klll error\n");
		}
		else
		{
			if (kill(s_id, SIGUSR2) == -1)
				ft_error("kill error\n");
		}
		bit >>= 1;
		usleep(1000);
	}
}

void	ft_send_message(int s_id, char *msgs)
{
	int	i;

	i = -1;
	while (msgs[++i] != '\0')
	{
		ft_binary_send(s_id, msgs[i]);
	}
	ft_binary_send(s_id, '\0');
}

void	ft_handler(int signo, siginfo_t *siginfo, void *context)
{
	(void)signo;
	(void)siginfo;
	(void)context;
}

int	main(int argc, char *argv[])
{
	struct sigaction	sact;
	int					s_id;

	if (argc != 3)
		ft_error("argv error\n");
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_handler;
	sigemptyset(&sact.sa_mask);
	if ((sigaction(SIGUSR1, &sact, 0)) == -1)
		ft_error("sigaction error\n");
	if ((sigaction(SIGUSR2, &sact, 0)) == -1)
		ft_error("sigaction error\n");
	s_id = ft_atoi(argv[1]);
	ft_send_message(s_id, argv[2]);
	while (1)
		pause();
	return (0);
}
