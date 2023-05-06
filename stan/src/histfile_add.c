/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histfile_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:05:30 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/15 16:47:47 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	histfile_add(const char *line)
{
	int	fd;

	add_history(line);
	fd = histfile_open(1);
	if (fd == -1)
		return ;
	ft_putstr(line, fd);
	ft_putstr("\n", fd);
	fd_close(&fd);
}
