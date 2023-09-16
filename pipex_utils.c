#include "pipex.h"

void	*ft_error(char *errmsg)
{
	int	i;

	i = 0;
	while (errmsg[i] != '\0')
	{
		write(1, &errmsg[i], 1);
		i++;
	}
	return (0);
}

char	**ft_getpath(char *av, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (env[i] == 'PATH=')
		{
			while (env[i][j] != '=')
				j++;
			return ()
		}
		i++;
	}
}

char	**ft_getpath()
