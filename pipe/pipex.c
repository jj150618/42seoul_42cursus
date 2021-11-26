/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:28:26 by junghkim          #+#    #+#             */
/*   Updated: 2021/11/18 21:28:29 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	find_shell(t_info *data)
{
	int	i;

	i = 0;
	while (data->j.env[i])
	{
		if (ft_memcmp(data->j.env[i], "SHELL=", 6) == 0)
		{
			data->j.shell = ft_strdup(ft_strrchr(data->j.env[i], '/') + 1);
			break ;
		}
		i++;
	}
}

static void	find_path(t_info *data, int i)
{
	while (data->split_path[i])
	{
		data->j.path_cmd_1 = ft_strjoin(data->split_path[i], data->j.cmd_1[0]);
		if (access(data->j.path_cmd_1, F_OK) == 0)
		{
			data->cmd_1 = 1;
			break ;
		}
		free(data->j.path_cmd_1);
		i++;
	}
	i = 0;
	while (data->split_path[i])
	{
		data->j.path_cmd_2 = ft_strjoin(data->split_path[i], data->j.cmd_2[0]);
		if (access(data->j.path_cmd_2, F_OK) == 0)
		{
			data->cmd_2 = 1;
			break ;
		}
		free(data->j.path_cmd_2);
		i++;
	}
}

static void	init_path(t_info *data)
{
	int		i;
	char	*temp_string;

	data->split_path = ft_split(data->j.temp_string, ':');
	i = 0;
	while (data->split_path[i])
	{
		temp_string = ft_strdup(data->split_path[i]);
		free(data->split_path[i]);
		data->split_path[i] = ft_strjoin(temp_string, "/");
		free(temp_string);
		i++;
	}
	find_path(data, 0);
	return ;
}

void	init_path_array(t_info *data)
{
	int	i;

	i = 0;
	data->cmd_1 = 0;
	data->cmd_2 = 0;
	find_shell(data);
	while (data->j.env[i])
	{
		if (ft_memcmp(data->j.env[i], "PATH=", 5) == 0)
		{
			data->j.temp_string = ft_strdup(ft_strchr(data->j.env[i], '=') + 1);
			init_path(data);
			break ;
		}
		i++;
	}
	return ;
}

int	main(int argc, char **argv, char *envp[])
{
	t_info	data;

	if (argc != 5)
		error_exit("", 1);
	data.i.fd_infile = open(argv[1], O_RDONLY);
	data.i.fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data.i.fd_infile < 0 || data.i.fd_outfile < 0)
		error_exit("", 1);
	data.j.cmd_1 = ft_split(argv[2], ' ');
	data.j.cmd_2 = ft_split(argv[3], ' ');
	data.j.env = envp;
	init_path_array(&data);
	init_pipe(&data);
	free_path(&data);
	return (0);
}
