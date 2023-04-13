/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:28:09 by csaunier          #+#    #+#             */
/*   Updated: 2023/04/08 03:31:30 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

char	*get_path(char **env, char **cmd)
{
	char			*path;
	char			**all_path;
	char			*exec_cmd;

	path = ft_strdup(find_path(env));
	all_path = ft_split(path, ':');
	free(path);
	exec_cmd = find_cmd(all_path, cmd);
	if (exec_cmd != NULL)
		return (exec_cmd);
	free_tab(all_path);
	return (NULL);
}

char	*find_cmd(char **all_path, char **cmd)
{
	unsigned int	i;
	char			*tmp;
	char			*exec_cmd;

	i = 0;
	while (all_path[i])
	{
		tmp = ft_strjoin(all_path[i], "/");
		exec_cmd = ft_strjoin(tmp, cmd[0]);
		if (tmp == NULL || exec_cmd == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		free(tmp);
		if (access(exec_cmd, F_OK) == 0)
		{
			free_tab(all_path);
			return (exec_cmd);
		}
		else
			free(exec_cmd);
		i++;
	}
	return (NULL);
}

void	free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
