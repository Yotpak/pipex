/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:47:31 by tbalci            #+#    #+#             */
/*   Updated: 2023/09/24 13:32:02 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	exit (0);
}

char	*ft_getcmdpath(char *cmd, char **env)
{
	int		i;
	char	**all_path;
	char	*control;
	char	*cmd_path;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	all_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (all_path[i])
	{
		control = ft_strjoin(all_path[i], "/");
		cmd_path = ft_strjoin(control, cmd);
		if (!cmd_path)
			free(cmd_path);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		i++;
	}
	i = -1;
	while (all_path[++i])
		free(all_path[i]);
	free(all_path);
	return (0);
}

void	ft_execute(char *av, char **env)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(av, ' ');
	cmd_path = ft_getcmdpath(cmd[0], env);
	execve(cmd_path, cmd, env);
}
