/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histfile_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:44:28 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 03:08:07 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	mode = 0: read
//	mode = 1: append
//	mode = 2: truncate

int	histfile_open(int mode)
{
	char	*home;
	char	path[PATH_MAX];
	char	*p;
	int		fd;

	home = ft_env_var("HOME", g_shell->env.data);
	if (!home || !ft_file_directory(home))
		return (-1);
	p = ft_stpcpy(path, home);
	ft_strcatchr(p, '/', 1);
	ft_strcat(p, HISTFILE);
	if (mode == 2)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (mode == 1)
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(path, O_RDONLY | O_CREAT, 0644);
	if (fd == -1)
		errno = 0;
	return (fd);
}
