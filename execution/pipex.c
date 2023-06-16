/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:02:52 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 16:33:05 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	print_signal_message(int sig_code, int *flag)
{
	if (sig_code == SIGTERM)
		ft_printf("Terminated: 15\n");
	else if (sig_code == SIGQUIT)
		ft_printf("Quit: 3\n");
	else if (sig_code == SIGINT)
	{
		*flag = 1;
		ft_printf("\n");
	}
	else if (sig_code == SIGKILL)
		ft_printf("Killed: 9 \n");
}

static void	pipex_get_exit_status(t_cmd **head)
{
	t_cmd	*cmd;
	t_cmd	*last;
	int		flag;

	cmd = *head;
	flag = 0;
	while (cmd)
	{
		waitpid(cmd->pid, &cmd->status, 0);
		last = cmd;
		cmd = cmd->next;
	}
	if (WIFEXITED(last->status))
		g_shell->exit_status = WEXITSTATUS(last->status);
	else if (WIFSIGNALED(last->status))
	{
		print_signal_message(WTERMSIG(last->status), &flag);
		g_shell->exit_status = WTERMSIG(last->status) + 128;
	}
	kill_zombies(head, flag);
}

static void	pipex_helper(int fd_pipe[2], t_cmd *cmd, int i, int *save_fdin)
{
	if (cmd->pid == 0)
	{
		if (cmd->next != NULL)
			dup2(fd_pipe[1], STDOUT_FILENO);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		ft_exe(i, *save_fdin, cmd);
		exit(g_shell->exit_status);
	}
	else
	{
		close(fd_pipe[1]);
		close(*save_fdin);
		*save_fdin = fd_pipe[0];
	}
}

static void	after_fork(t_cmd **head, int i, int save_fdin)
{
	pipex_get_exit_status(head);
	delete_all_heredocs(i);
	close(save_fdin);
}

void	pipex(t_cmd **head)
{
	int		fd_pipe[2];
	int		save_fdin;
	t_cmd	*cmd;
	int		i;

	i = 0;
	if (!head || !*head || g_shell->heredoc_flag == 1)
		return ;
	cmd = *head;
	while (cmd)
	{
		pipe(fd_pipe);
		cmd->pid = fork();
		if (cmd->pid < 0)
		{
			error_message2("fork:", strerror(errno));
			return ;
		}
		pipex_signal_handler();
		pipex_helper(fd_pipe, cmd, i, &save_fdin);
		cmd = cmd->next;
		i++;
	}
	after_fork(head, i, save_fdin);
}
