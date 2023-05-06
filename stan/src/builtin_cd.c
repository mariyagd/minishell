/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/26 15:23:04 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_set_oldpwd(void)
{
	char	path[PATH_MAX];
	char	*opwd;

	opwd = env_get(&g_shell->env, "PWD");
	if (!opwd)
	{
		if (!getcwd(path, PATH_MAX))
		{
			errno = 0;
			return ;
		}
		opwd = path;
	}
	if (!env_set(&g_shell->env, "OLDPWD", opwd))
		enomem();
}

static void	_set_pwd(const char *pwd)
{
	if (!env_set(&g_shell->env, "PWD", pwd))
		enomem();
}

//	returned string must be ft_free'd

static int	_get_path(const t_cmd *cmd, char **res)
{
	char	**p;
	char	*path;

	p = ft_arr_get(&cmd->args, 1);
	if (!p)
	{
		path = env_get(&g_shell->env, "HOME");
		if (!path)
			return (0);
	}
	else if (**p == '-' && !ft_strcmp(*p, "-"))
	{
		path = env_get(&g_shell->env, "OLDPWD");
		if (!path)
			return (0);
	}
	else
		path = *p;
	if (!ft_strdup2(path, res))
		enomem();
	return (1);
}

int	builtin_cd(t_cmdgrp *cgrp, t_cmd *cmd)
{
	char	*path;

	(void) cgrp;
	if (!_get_path(cmd, &path))
		return (0);
	if (chdir(path) == -1)
	{
		ft_free(path);
		return (1 + error("chdir", strerror(errno)));
	}
	_set_oldpwd();
	_set_pwd(path);
	ft_free(path);
	return (0);
}
