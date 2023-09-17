#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

void	*ft_error(char *errmsg);
char	*ft_getcmdpath(char *cmd, char **env);
void	ft_execute(char *av, char **env);
void	ft_child1(int *fd, char **av, char **env);
void	ft_child2(int *fd, char **av, char **env);

#endif