/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:47:27 by tbalci            #+#    #+#             */
/*   Updated: 2023/09/17 18:27:26 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

void	ft_child1(int *fd, char **av, char **env) //(fd, av[2], env);
{
	int	file1;

	file1 = open(av[1], O_RDONLY, 0777);
	close(fd[0]);
	dup2(file1, 0);
	dup2(fd[1], 1);
	ft_execute(av[2], env);
}

void	ft_child2(int *fd, char **av, char **env)
{
	int	file2;

	file2 = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(file2, 1);
	ft_execute(av[3], env);
}


int main(int ac, char *av[], char **env)
{
	if (ac != 5)//leak kontrol yap.
		ft_error("arguments error");
	int		fd[2];
	int		pid;
	pipe(fd);
	pid = fork();
	if (pid == 0)//pid kontrol yap.
	{
		ft_child1(fd, av, env);
	}
	pid = fork();
	if (pid == 0)
	{
		ft_child2(fd, av, env);
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);

	
}