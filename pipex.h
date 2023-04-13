/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:08:16 by csaunier          #+#    #+#             */
/*   Updated: 2023/04/13 18:22:29 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/types.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

void	first_born(int *pipefd, char **av, char **env);
void	last_born(int *pipefd, char **av, char **env);
void	error_handling(const char *func);
char	*find_path(char **env);
char	*get_path(char **env, char **cmd);
void	free_tab(char **tab);
char	*find_cmd(char **all_path, char **cmd);
void	error_free(char **tab);

#endif