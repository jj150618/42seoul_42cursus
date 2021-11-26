/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:28:38 by junghkim          #+#    #+#             */
/*   Updated: 2021/11/18 21:28:39 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_cmd(t_info *data, int code)
{
	char	*temp_string;

	if (code == 0)
	{
		temp_string = ft_strtjoin(ft_strjoin(data->j.shell, ": "),
				data->j.cmd_1[0], CMDERROR);
		ft_putstr_fd(temp_string, 2);
		free(temp_string);
		exit(127);
	}
	if (code == 1)
	{
		temp_string = ft_strtjoin(ft_strjoin(data->j.shell, ": "),
				data->j.cmd_2[0], CMDERROR);
		ft_putstr_fd(temp_string, 2);
		free(temp_string);
		exit(127);
	}
	return ;
}

void	error_exit(char *message, int code)
{
	if (code == 1)
	{
		write(STDERR_FILENO, ARGERROR, ft_strlen(ARGERROR));
		exit(1);
	}
	if (code == 127)
	{
		write(STDERR_FILENO, ARGERROR, ft_strlen(ARGERROR));
		exit(127);
	}
	return ;
}

void	ps_error(char *errno)
{
	perror(strerror(errno));
	exit(EXIT_FAILURE);
}

char	*ft_strtjoin(char *string0, char *string1, char *string2)
{
	char	*str;
	char	*temp_string;

	if (!string0 | !string1 | !string2)
		return (NULL);
	temp_string = ft_strjoin(string0, string1);
	str = ft_strjoin(temp_string, string2);
	free(temp_string);
	temp_string = NULL;
	return (str);
}
