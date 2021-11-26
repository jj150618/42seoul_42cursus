/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:31:04 by junghkim          #+#    #+#             */
/*   Updated: 2021/11/18 21:31:06 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>

# include "../libft/libft.h"

# define ARGERROR "Should be executed this way: ./pipex file1 cmd1 cmd2 file2\n"
# define CMDERROR ": command not found\n"

typedef struct s_filedes
{
	int	fd_infile;
	int	fd_outfile;
	int	pipefd[2];
	int	pid_1;
	int	pid_2;
}	t_filedes;

typedef struct s_strings
{
	char		**cmd_1;
	char		**cmd_2;
	char		*path_cmd_1;
	char		*path_cmd_2;
	char		*temp_string;
	char		**env;
	char		*shell;
}	t_strings;

typedef struct s_info
{
	t_filedes	i;
	t_strings	j;
	pid_t		child1;
	pid_t		child2;
	char		**split_path;
	int			cmd_1;
	int			cmd_2;
}	t_info;

void	init_path_array(t_info *data);
void	init_pipe(t_info *data);

void	error_exit(char *message, int code);

void	free_path(t_info *data);

void	find_shell(t_info *data);

char	*ft_strtjoin(char *string0, char *string1, char *string2);

void	error_cmd(t_info *data, int code);
#endif
