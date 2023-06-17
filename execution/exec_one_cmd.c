/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:08:47 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/17 10:57:17 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	print_signal_message(int sig_code)
{
	if (sig_code == SIGTERM)
		ft_printf("Terminated: 15\n");
	else if (sig_code == SIGQUIT)
		ft_printf("QUIT: 3\n");
	else if (sig_code == SIGINT)
		ft_printf("\n");
	else if (sig_code == SIGKILL)
		ft_printf("Killed: 9 \n");
}

static void	execute_one_bin_helper(t_cmd *cmd)
{
	signal(SIGINT, SIG_IGN);
	waitpid(cmd->pid, &cmd->status, 0);
	if (WIFSIGNALED(cmd->status))
	{
		print_signal_message(WTERMSIG(cmd->status));
		g_shell->exit_status = WTERMSIG(cmd->status) + 128;
	}
	else if (WIFEXITED(cmd->status))
	{
		g_shell->exit_status = WEXITSTATUS(cmd->status);
	}
}

static void	execute_one_bin(t_cmd *cmd)
{
	int	res;

	cmd->pid = fork();
	if (cmd->pid < 0)
	{
		error_message2("fork:", strerror(errno));
		return ;
	}
	if (cmd->pid == 0)
	{
		child_signal_handler();
		res = make_redirections(cmd, 0);
		if (!res)
			exit(1);
		execute_bin(cmd);
		exit(g_shell->exit_status);
	}
	else
		execute_one_bin_helper(cmd);
}

void	one_cmd(t_cmd *cmd)
{
	int	res;

	if (!cmd->cmd || cmd_is_builtin(cmd->cmd[0]))
	{
		res = make_redirections(cmd, 0);
		if (!res || !cmd->cmd)
		{
			restaure_fds(cmd, 0);
			return ;
		}
		execute_builtin(cmd);
		restaure_fds(cmd, 0);
	}
	else
	{
		execute_one_bin(cmd);
		delete_here_doc(0);
	}
}
