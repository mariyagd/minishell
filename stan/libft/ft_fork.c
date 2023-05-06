/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:51:01 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/24 19:54:38 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	a version of fork() that is not broken on MacOS

pid_t	ft_fork(pid_t *ret)
{
	pid_t	pid;

	assert(errno == 0);
	pid = fork();
	if (ret)
		*ret = pid;
	if (pid == -1)
		return (pid);
	if (errno)
		errno = 0;
	return (pid);
}
