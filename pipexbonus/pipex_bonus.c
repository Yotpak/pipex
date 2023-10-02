/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:37:40 by tbalci            #+#    #+#             */
/*   Updated: 2023/09/25 20:41:55 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_firstchild(int *fd, char **av, char **env)
{
	int	file1;

	file1 = open(av[1], O_RDONLY, 0777);
	close(fd[0]);
	dup2(file1, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	ft_execute(av[2], env);
}

void	ft_whilechild(int *fd, int i, char **av, char **env)
{
	dup2(fd[0], 0);
	dup2(fd[1], 1);
	ft_execute(av[i], env);
}

void	ft_lastchild(int *fd, int ac, char **av, char **env)
{
	int	file2;

	file2 = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(file2, 1);
	close(fd[0]);
	ft_execute(av[ac - 2], env);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	pid;
	int	i;

	pipe(fd);
	pid = fork();
	if (pid == 0)
		ft_firstchild(fd, av, env);
	i = 2;
	pid = fork();
	while (ac - 2 > ++i && pid == 0)
	{
		pid = fork();
		ft_whilechild(fd, i, av, env);
	}
	pid = fork();
	if (pid == 0)
		ft_lastchild(fd, ac, av, env);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}
