/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:40:33 by wmadison          #+#    #+#             */
/*   Updated: 2021/06/29 22:20:42 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(errno);
}

void	free_mass(char **mass)
{
	int	i;

	i = 0;
	while (mass[i])
	{
		free(mass[i]);
		i++;
	}
	free(mass);
}

char	*find_path(char **env)
{
	char	*tmp_path;
	int		i;

	i = 0;
	tmp_path = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
		{
			tmp_path = ft_substr(env[i], 5, ft_strlen(env[i]));
			return (tmp_path);
		}
		i++;
	}
	if (tmp_path == NULL)
		error_msg ("You don't have command.\n");
	return (0);
}

int	create_path_all_2(char **path_all, char **path, char *com, int i)
{
	int		fd;
	char	*tmp;

	tmp = ft_strjoin(path_all[i], "/");
	*path = ft_strjoin(tmp, com);
	free(tmp);
	fd = open(*path, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (fd);
	}
	else
	{
		free(*path);
		*path = NULL;
		close(fd);
	}
	return (fd);
}

char	*create_path_all(char **env, char *com)
{
	char	*path;
	char	**path_all;
	int		fd;
	int		i;

	i = 0;
	path = find_path(env);
	path_all = ft_split(path, ':');
	free(path);
	path = NULL;
	fd = create_path_all_2(path_all, &path, com, i);
	while (path_all[i])
	{
		if (fd > 0)
			break ;
		else
		{
			fd = create_path_all_2(path_all, &path, com, i);
			i++;
		}
	}
	free_mass(path_all);
	if (fd <= 0)
		error_msg("Command not found.\n");
	return (path);
}
