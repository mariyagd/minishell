/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:42:03 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 00:42:47 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_close(int *fd)
{
	int	i;

	i = 0;
	if (*fd != -1)
	{
		i = close(*fd);
		if (i == -1)
			error("close", strerror(errno));
		*fd = -1;
	}
	return (i);
}
