/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abspath_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:43:09 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 00:43:51 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*abspath_find(const char *cmd)
{
	char	*path;
	char	**dirs;
	char	*res;

	path = ft_env_var("PATH", g_shell->env.data);
	if (!path)
		return (0);
	dirs = ft_split(path, ':');
	if (!dirs)
		enomem();
	res = ft_abspath_of_cmd(cmd, dirs);
	ft_del_arr(&dirs);
	return (res);
}
