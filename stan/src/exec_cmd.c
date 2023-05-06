/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:33:07 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/26 00:26:38 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_treat_arg0_cont(const char *arg0, char **abspath, t_cmd *cmd)
{
	*abspath = abspath_find(arg0);
	if (!*abspath)
	{
		ft_dprintf(2, "error: %s: command not found\n", arg0);
		cmd->_status = 127;
	}
}

static void	_treat_arg0(const char *arg0, char **abspath, t_cmd *cmd)
{
	if (ft_strchr(arg0, '/'))
	{
		if (!ft_file_exists(arg0))
			ft_dprintf(2, "error: %s: no such file or directory\n", arg0);
		else if (!ft_file_executable(arg0))
		{
			ft_dprintf(2, "error: %s: permission denied\n", arg0);
			cmd->_status = 2;
		}
		else if (ft_file_directory(arg0))
		{
			ft_dprintf(2, "error: %s: is a directory\n", arg0);
			cmd->_status = 2;
		}
		else
			*abspath = (char *) arg0;
	}
	else
		_treat_arg0_cont(arg0, abspath, cmd);
}

static void	_make_args(char *abspath, t_cmd *cmd)
{
	if (abspath && !make_args(cmd))
		ft_del(&abspath);
	if (!abspath)
		exit(cmd->_status);
}

/*
 *	1) open all fildes
 *	2) if ok, make arg0, exit success if there is none
 *	3) check arg0
 *	4) if ok, make args
 *	returned value is ignored
 */

int	exec_cmd(t_cmdgrp *cgrp, t_cmd *cmd, size_t num)
{
	char	*arg0;
	char	*abspath;

	abspath = 0;
	cmd->_pid = ft_fork(0);
	if (cmd->_pid == 0)
	{
		sig_subshell();
		if (!cmd_fildes(cgrp, cmd, num))
			exit(cmd->_status);
		arg0 = make_arg0(cmd);
		if (!arg0)
			exit(0);
		if (cmd_builtin(arg0))
			exit(exec_builtin(cgrp, cmd));
		cmd->_status = 1;
		_treat_arg0(arg0, &abspath, cmd);
		_make_args(abspath, cmd);
		sig_remove();
		execve(abspath, cmd->args.data, g_shell->env.data);
		ft_dprintf(2, "error: %s: %s\n", abspath, strerror(errno));
		exit(1);
	}
	return (1);
}
