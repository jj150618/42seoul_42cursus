/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:29:32 by junghkim          #+#    #+#             */
/*   Updated: 2021/11/01 00:59:57 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 1);
	exit(0);
}

void	ft_handler(int signo, siginfo_t *siginfo, void *context)
{
	static unsigned char	bit = 0b00000000;
	static int				bit_num = 0;

	(void)siginfo;
	(void)context;
	if (signo == SIGUSR1)
		bit += 1 << (7 - bit_num);
	bit_num += 1;
	if (bit_num == 8)
	{
		if (bit == '\0')
			ft_putchar_fd('\n', 1);
		ft_putchar_fd(bit, 1);
		bit_num = 0;
		bit = 0b00000000;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sact;

	if (argc > 1)
		ft_error("argc error\n");
	(void)argv;
	ft_putstr_fd("server id: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_handler;
	sigemptyset(&sact.sa_mask);
	if ((sigaction(SIGUSR1, &sact, 0)) == -1)
		ft_error("sigaction error\n");
	if ((sigaction(SIGUSR2, &sact, 0)) == -1)
		ft_error("sigaction error\n");
	while (1)
		pause();
	return (0);
}
