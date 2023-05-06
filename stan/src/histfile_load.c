/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histfile_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:00:55 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/16 23:32:01 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_set_last_cmd(char *line)
{
	char	**prev;

	prev = last_command();
	if (*prev)
		ft_free(*prev);
	*prev = line;
}

static void	_load_history(char **lines, size_t cnt)
{
	int		fd;
	int		i;
	char	*line;

	fd = histfile_open(2);
	if (fd == -1)
		return ;
	i = ft_max(-1, ((int) cnt) - 1000);
	while (lines[++i])
	{
		line = lines[i];
		if (ft_strisspace(line))
			continue ;
		ft_putstr(line, fd);
		if (ft_endswith(line, "\n"))
			*ft_strrchr(line, '\n') = 0;
		add_history(line);
		_set_last_cmd(line);
		lines[i] = 0;
	}
	fd_close(&fd);
}

void	histfile_load(void)
{
	int		fd;
	char	**lines;

	fd = histfile_open(0);
	if (fd == -1)
		return ;
	lines = ft_getfile(fd);
	if (!lines)
		enomem();
	fd_close(&fd);
	_load_history(lines, ft_count_arr(lines));
	ft_del_arr(&lines);
}
