/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:08:27 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/15 18:19:08 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_file_ro(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "error: %s: %s\n", path, strerror(errno));
		errno = 0;
		return (-1);
	}
	return (fd);
}

int	open_file_wa(const char *path)
{
	int	fd;

	fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		ft_dprintf(2, "error: %s: %s\n", path, strerror(errno));
		errno = 0;
		return (-1);
	}
	return (fd);
}

int	open_file_wo(const char *path)
{
	int	fd;

	fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_dprintf(2, "error: %s: %s\n", path, strerror(errno));
		errno = 0;
		return (-1);
	}
	return (fd);
}
