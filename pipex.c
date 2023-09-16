#include <stdio.h>
#include "pipex.h"

void	ft_child1(int *fd,char **av, char **env)
{
	char	**cmd1;
	char	*path;

	cmd1 = ft_getenv(av[2], env);
	close(fd[0]);
	dup2(fd[1], 1);
	char	*ft_ls[] = {"ls", "-l", NULL};
	execve("/bin/ls", cmd1, env); 
}

void	ft_child2(int *fd, char **env)
{
	dup2(fd[0], 0);
	char	*ft_wc[] = {"wc", "-l", NULL};
	execve("/usr/bin/wc", ft_wc, env);
}


int main(int ac, char *av[], char **env)
{
	//if (ac != 5)
		//ft_error("arguments error");
	int	fd[2];
	int pid;
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		ft_child1(fd, env);
	}
	pid = fork();
	close(fd[1]);
	if (pid == 0)
	{
		ft_child2(fd, env);
	}
}