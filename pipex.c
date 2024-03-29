/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:47:27 by tbalci            #+#    #+#             */
/*   Updated: 2023/09/24 13:40:58 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1(int *fd, char **av, char **env)
{
	int	file1;

	file1 = open(av[1], O_RDONLY, 0777);
	if (file1 == -1)
		ft_error("File1 Open Function Failure");
	close(fd[0]);
	dup2(file1, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	ft_execute(av[2], env);
}

void	ft_child2(int *fd, char **av, char **env)
{
	int	file2;

	file2 = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (file2 == -1)
		ft_error("File2 Open Function Failure");
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(file2, 1);
	close(fd[0]);
	ft_execute(av[3], env);
}

int	main(int ac, char *av[], char **env)
{
	int	fd[2];
	int	pid;

	if ((pipe(fd)) == -1)
		ft_error("Pipe Failure.");
	if (ac == 5)
	{
		pid = fork();
		if (pid == -1)
			ft_error("Fork Failure.\n");
		if (pid == 0)
			ft_child1(fd, av, env);
		pid = fork();
		if (pid == -1)
			ft_error("Fork Failure.\n");
		if (pid == 0)
			ft_child2(fd, av, env);
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		wait(NULL);
	}
	else
		ft_error("Invalid number of arguments.\n");
}
