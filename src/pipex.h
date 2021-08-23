/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:45:08 by wmadison          #+#    #+#             */
/*   Updated: 2021/06/29 17:45:10 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	"libft/libft.h"
# include	<errno.h>
# include	<sys/wait.h>
# include	<string.h>

void	error_msg(char *msg);
void	free_mass(char **mass);
char	*find_path(char **env);
int		create_path_all_2(char **path_all, char **path, char *com, int i);
char	*create_path_all(char **env, char *com);
void	close_fd_1(int *fd_2);
void	save_com_1(int *fd_2, char **argv, char **env);
void	close_fd_2(int *fd_2, int out_file);
void	save_com_2( int *fd_2, char **argv, char **env);
int		main(int argc, char **argv, char **env);

#endif
