/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:09:31 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/09 18:16:22 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	check_access(t_cmd *cmd)
{
	int	res;

	if (!cmd->path)
	{
		ft_dprintf(2, "minishell: %s: command not found\n", cmd->cmd[0]);
		g_shell->exit_status = 127;
		return (0);
	}
	res = access(cmd->path, F_OK & X_OK);
	if (res)
	{
		ft_dprintf(2, "minishell: %s\n", strerror(errno));
		g_shell->exit_status = 127;
		return (0);
	}
	return (1);
}

static void	check_execve(t_cmd *cmd)
{
	if (!cmd->cmd)
	{
		ft_dprintf(2, "minishell: %s: is a directory\n", cmd->path);
		g_shell->exit_status = 126;
		return ;
	}
	cmd->res = execve(cmd->path, cmd->cmd, g_shell->save_env);
	if (cmd->res < 0)
	{
		if (errno == ENOEXEC)
		{
			ft_dprintf(2, "minishell: %s: Permission denied\n", cmd->path);
			g_shell->exit_status = 126;
			return ;
		}
		ft_dprintf(2, "minishell: %s: %s\n", cmd->path, strerror(errno));
		if (errno == EACCES)
		{
			g_shell->exit_status = 126;
			return ;
		}
		g_shell->exit_status = 127;
		return ;
	}
	g_shell->exit_status = 0;
}

void	execute_bin(t_cmd *cmd)
{
	int	res;

	res = 0;
	if (!cmd || !cmd->cmd)
		return ;
	if (!get_path(cmd))
		return ;
	res = check_access(cmd);
	if (res)
		check_execve(cmd);
	if (cmd->path)
		free(cmd->path);
	if (cmd->cmd)
		free_tab2d(cmd->cmd);
	return ;
}
