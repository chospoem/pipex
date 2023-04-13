/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:31:59 by csaunier          #+#    #+#             */
/*   Updated: 2023/04/13 18:22:20 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_born(int *pipefd, char **av, char **env)
{
	int		fd_in;
	char	**cmd;
	char	*cmd_path;

	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
		error_handling("open");
	close(pipefd[0]);
	if (dup2(fd_in, 0) == -1)
		error_handling("dup2");
	if (dup2(pipefd[1], 1) == -1)
		error_handling("dup2");
	cmd = ft_split(av[2], ' ');
	cmd_path = get_path(env, cmd);
	if (cmd_path == NULL)
		error_free(cmd);
	if (execve(cmd_path, cmd, env) == -1)
	{
		free(cmd_path);
		free_tab(cmd);
		error_handling("execve");
	}
	free(cmd_path);
	free(cmd);
	close(fd_in);
}

void	last_born(int *pipefd, char **av, char **env)
{
	int		fd_out;
	char	**cmd;
	char	*cmd_path;

	fd_out = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_out == -1)
		error_handling("open");
	close(pipefd[1]);
	if (dup2(pipefd[0], 0) == -1)
		error_handling("dup2");
	if (dup2(fd_out, 1) == -1)
		error_handling("dup2");
	cmd = ft_split(av[3], ' ');
	cmd_path = get_path(env, cmd);
	if (cmd_path == NULL)
		error_free(cmd);
	if (execve(cmd_path, cmd, env) == -1)
	{
		free(cmd_path);
		free_tab(cmd);
		error_handling("execve");
	}
	free(cmd_path);
	free(cmd);
	close(fd_out);
}

void	error_free(char **tab)
{
	free_tab(tab);
	exit(EXIT_FAILURE);
}

void	error_handling(const char *func)
{
	perror(func);
	exit(EXIT_FAILURE);
}
