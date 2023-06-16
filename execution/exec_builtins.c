/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:17:01 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 20:36:12 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	cmd_is_builtin(char *s)
{
	if (s)
	{
		if (ft_strncmp(s, "echo", 5) == 0)
			return (1);
		else if (ft_strncmp(s, "cd", 3) == 0)
			return (1);
		else if (ft_strncmp(s, "pwd", 4) == 0)
			return (1);
		else if (ft_strncmp(s, "export", 7) == 0)
			return (1);
		else if (ft_strncmp(s, "unset", 6) == 0)
			return (1);
		else if (ft_strncmp(s, "env", 4) == 0)
			return (1);
		else if (ft_strncmp(s, "exit", 5) == 0)
			return (1);
	}
	return (0);
}

void	execute_builtin(t_cmd *cmd)
{
	if (ft_strncmp(cmd->cmd[0], "exit", 6) == 0)
		ft_exit(cmd);
	else if (ft_strncmp(cmd->cmd[0], "pwd", 4) == 0)
		_pwd();
	else if (ft_strncmp(cmd->cmd[0], "echo", 5) == 0)
		_echo(cmd);
	else if (ft_strncmp(cmd->cmd[0], "env", 4) == 0)
		_env(cmd, g_shell->env);
	else if (ft_strncmp(cmd->cmd[0], "cd", 3) == 0)
		_cd(cmd);
	else if (ft_strncmp(cmd->cmd[0], "export", 7) == 0)
		_export(cmd);
	else if (ft_strncmp(cmd->cmd[0], "unset", 6) == 0)
		_unset(cmd);
	return ;
}
