/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpids.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:28:44 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/16 19:29:36 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_close_all_fildes(const t_arr *cmds)
{
	size_t	i;
	t_cmd	*cmd;

	i = -1;
	while (++i < cmds->nelem)
	{
		cmd = *(t_cmd **) ft_arr_get(cmds, i);
		fd_close(&cmd->_pipe[0]);
		fd_close(&cmd->_pipe[1]);
		if (cmd->_input_or_heredoc == redir_input)
			fd_close(&cmd->_input_fd);
		else if (cmd->_input_or_heredoc == redir_heredoc)
			fd_close(&cmd->_heredoc_fd);
		if (cmd->_output_or_append == redir_output)
			fd_close(&cmd->_output_fd);
		else if (cmd->_output_or_append == redir_append)
			fd_close(&cmd->_append_fd);
	}
}

//	wait for any of child process to terminate
//	signal interrupts cause waitpid to fail; sigaction SA_RESTART handles that

static int	_wait(pid_t *pid)
{
	int	stat;

	*pid = waitpid(-1, &stat, WUNTRACED);
	if (WIFSTOPPED(stat))
		return (WSTOPSIG(stat));
	if (WIFSIGNALED(stat))
		return (WTERMSIG(stat));
	if (WIFEXITED(stat))
		return (WEXITSTATUS(stat));
	assert(0);
	return (0);
}

static void	_clearpid(const t_arr *cmds, pid_t pid)
{
	size_t	i;
	t_cmd	*cmd;

	i = -1;
	while (++i < cmds->nelem)
	{
		cmd = *(t_cmd **) ft_arr_get(cmds, i);
		if (cmd->_pid == pid)
		{
			cmd->_pid = -1;
			return ;
		}
	}
	assert(0);
}

//	returned value is ignored

int	waitpids(const t_arr *cmds)
{
	size_t	i;
	int		res;
	pid_t	pid;

	_close_all_fildes(cmds);
	res = 1;
	i = -1;
	while (++i < cmds->nelem)
	{
		res = _wait(&pid);
		_clearpid(cmds, pid);
	}
	termios_bs(0);
	g_shell->retval = res;
	g_shell->_cmdgrp = 0;
	return (res);
}
