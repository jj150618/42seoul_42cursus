/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:28:53 by junghkim          #+#    #+#             */
/*   Updated: 2021/11/18 21:29:50 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

static void	free_pointer_array(char	**array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	return ;
}

void	free_path(t_info *data)
{
	free_pointer_array(data->j.cmd_1);
	free_pointer_array(data->j.cmd_2);
	free_pointer_array(data->split_path);
	free(data->j.temp_string);
	free(data->j.shell);
	if (data->cmd_1 == 1)
		free(data->j.path_cmd_1);
	if (data->cmd_2 == 1)
		free(data->j.path_cmd_2);
	return ;
}

void	child_1(t_info *data)
{
	dup2(data->i.pipefd[1], STDOUT_FILENO);
	dup2(data->i.fd_infile, STDIN_FILENO);
	close(data->i.fd_infile);
	close(data->i.pipefd[0]);
	if (data->cmd_1 == 1)
		execve(data->j.path_cmd_1, data->j.cmd_1, data->j.env);
	error_cmd(data, 0);
	exit(EXIT_FAILURE);
}

void	child_2(t_info *data)
{
	dup2(data->i.fd_outfile, STDOUT_FILENO);
	dup2(data->i.pipefd[0], STDIN_FILENO);
	close(data->i.pipefd[1]);
	close(data->i.fd_outfile);
	if (data->cmd_2 == 1)
		execve(data->j.path_cmd_2, data->j.cmd_2, data->j.env);
	error_cmd(data, 1);
}

void	init_pipe(t_info *data)
{
	pipe(data->i.pipefd);
	data->child1 = fork();
	if (data->child1 < 0)
		return (perror("Fork: "));
	if (data->child1 == 0)
		child_1(data);
	data->child2 = fork();
	if (data->child2 < 0)
		return (perror("Fork: "));
	if (data->child2 == 0)
		child_2(data);
	close(data->i.pipefd[0]);
	close(data->i.pipefd[1]);
	waitpid(data->child1, NULL, 0);
	waitpid(data->child2, NULL, 0);
	return ;
}
