/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:01:11 by csaunier          #+#    #+#             */
/*   Updated: 2023/04/13 18:22:10 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*int	main(int ac, char **av, char **env)
{
	int		pipefd[2];
	int		status;
	pid_t	pid;

	if (ac != 5)
	{
		ft_putendl_fd("fonctionnement : infile cmd1 cmd2 outfile", 1);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) == -1)
		error_handling("pipe");
	pid = fork();
	if (pid == -1)
		error_handling("fork");
	if (pid == 0)
		first_born(pipefd, av, env);
	wait(&status);
	if (pid != 0)
		parent(pipefd, av, env);
	exit(EXIT_SUCCESS);
}*/

void	ft_close(int *pipefd)
{
	close(pipefd[1]);
	close(pipefd[0]);
}

int	main(int ac, char **av, char **env)
{
	int		pipefd[2];
	int		status;
	pid_t	pid;

	if (ac != 5)
	{
		ft_putendl_fd("fonctionnement : infile cmd1 cmd2 outfile", 1);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) == -1)
		error_handling("pipe");
	pid = fork();
	if (pid == -1)
		error_handling("fork");
	if (pid == 0)
		first_born(pipefd, av, env);
	pid = fork();
	if (pid == -1)
		error_handling("fork");
	if (pid == 0)
		last_born(pipefd, av, env);
	ft_close(pipefd);
	wait(&status);
	wait(&status);
	exit(EXIT_SUCCESS);
}
