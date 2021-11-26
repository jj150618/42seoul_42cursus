/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:29:14 by junghkim          #+#    #+#             */
/*   Updated: 2021/11/01 00:54:48 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_error(char *s);
void	ft_binary_send(int s_id, char msg);
void	ft_send_message(int s_id, char *msgs);
void	ft_handler_ack(int signo, siginfo_t *siginfo, void *context);
void	ft_handler(int signo, siginfo_t *siginfo, void *context);

#endif
