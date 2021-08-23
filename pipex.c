/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:51:37 by wmadison          #+#    #+#             */
/*   Updated: 2021/06/29 17:51:40 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/pipex.h"

void	close_fd_1(int *fd_2)
{
	close(fd_2[0]);
	dup2(fd_2[1], STDOUT_FILENO);
	close(fd_2[1]);
}

void	save_com_1(int *fd_2, char **argv, char **env)
{
	int		pid_com1;
	int		in_file;
	char	**first_com;
	char	*path_1;

	first_com = ft_split(argv[2], ' ');
	path_1 = create_path_all(env, first_com[0]);
	pid_com1 = fork();
	if (pid_com1 < 0)
		error_msg("Problem with you process.\n");
	if (pid_com1 == 0)
	{
		close_fd_1(fd_2);
		in_file = open(argv[1], O_RDONLY, 0777);
		if (in_file < 0)
			error_msg("We don't have file1.\n");
		dup2(in_file, 0);
		execve(path_1, first_com, env);
		perror(strerror(errno));
		close(in_file);
	}
	waitpid(pid_com1, NULL, 0);
	free_mass(first_com);
	free(path_1);
}

void	close_fd_2(int *fd_2, int out_file)
{
	close(fd_2[1]);
	dup2(out_file, STDOUT_FILENO);
	dup2(fd_2[0], 0);
	close(fd_2[0]);
	close(out_file);
}

void	save_com_2( int *fd_2, char **argv, char **env)
{
	int		pid_com2;
	int		out_file;
	char	*path_2;
	char	**second_com;

	second_com = ft_split(argv[3], ' ');
	path_2 = create_path_all(env, second_com[0]);
	pid_com2 = fork();
	if (pid_com2 < 0)
		error_msg("Problem with you process.\n");
	if (pid_com2 == 0)
	{
		out_file = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (out_file < 0)
			error_msg("We don't have file2.\n");
		close_fd_2(fd_2, out_file);
		execve(path_2, second_com, env);
		perror(strerror(errno));
	}
	close(fd_2[1]);
	waitpid(pid_com2, NULL, 0);
	free_mass(second_com);
	free(path_2);
}

int	main(int argc, char **argv, char **env)
{
	int		fd_2[2];

	if (argc != 5)
		error_msg("Problem with your arguments\n");
	if (pipe(fd_2) == -1)
		error_msg("Problem with your pipe\n");
	save_com_1(fd_2, argv, env);
	save_com_2(fd_2, argv, env);
	return (0);
}
