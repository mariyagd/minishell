/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_hd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:15:49 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/24 23:18:48 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_create_pipe(int fds[])
{
	if (pipe(fds) == -1)
		fatal("pipe", strerror(errno));
}

static int	_error(int fds[])
{
	errno = 0;
	fd_close(&fds[0]);
	fd_close(&fds[1]);
	return (-1);
}

static char	*_gnl(char **line)
{
	assert(errno == 0);
	*line = ft_getnextline(STDIN_FILENO);
	return (*line);
}

static void	_ctrl_d(char **line)
{
	if (!ft_append(line, "\n"))
		enomem();
	ft_putchar('\n', STDOUT_FILENO);
}

//	signal interrupts cause read to fail (errno is then set).
//	ctrl-d flushes the stream, so the line isnt always terminated by \n

int	open_file_hd(const char *eof)
{
	char	*line;
	int		fds[2];

	_create_pipe(fds);
	while (1)
	{
		ft_putstr("> ", STDOUT_FILENO);
		if (!_gnl(&line))
		{
			ft_putchar('\n', STDOUT_FILENO);
			if (errno)
				return (_error(fds));
			break ;
		}
		if (compare_hd(line, eof))
			break ;
		if (!ft_endswith(line, "\n"))
			_ctrl_d(&line);
		ft_putstr(expand_str(line), fds[1]);
		ft_del(&line);
	}
	if (line)
		ft_free(line);
	fd_close(&fds[1]);
	return (fds[0]);
}
