/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abspath_of_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:17:57 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/23 18:34:20 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// look for executable 'cmd' in given list of directories
// cmd is not a relative path (doesnt contain any slash)
// returned string must be freed

#define MAXPATH	4096

char	*ft_abspath_of_cmd(const char *cmd, char *dirs[])
{
	const size_t	cmdsz = ft_strlen(cmd);
	size_t			dsz;
	char			path[MAXPATH];
	size_t			i;

	if (!cmdsz || ft_strchr(cmd, '/') || !dirs[0])
		return (0);
	i = 0;
	while (dirs[i])
	{
		if (ft_strlen2(dirs[i], &dsz) >= MAXPATH - cmdsz)
			return (0);
		ft_strcpy(path, dirs[i]);
		if (dirs[i][dsz - 1] != '/')
		{
			path[dsz] = '/';
			path[dsz + 1] = 0;
		}
		ft_strcat(path, cmd);
		if (ft_file_executable(path))
			return (ft_strdup(path));
		++i;
	}
	return (0);
}
