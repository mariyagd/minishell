/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fildes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:24:44 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/24 23:48:05 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_close_fildes(t_cmd *cmd)
{
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

static int	_stdin(t_cmd *cmd, t_cmd *prev)
{
	if (prev)
		fd_close(&prev->_pipe[1]);
	if (cmd->_input_or_heredoc)
	{
		if (prev)
			fd_close(&prev->_pipe[0]);
		if (cmd->_input_or_heredoc == redir_input)
		{
			assert(cmd->_input_fd != -1);
			return (cmd->_input_fd);
		}
		else
		{
			assert(cmd->_heredoc_fd != -1);
			return (cmd->_heredoc_fd);
		}
	}
	else if (prev)
		return (prev->_pipe[0]);
	else
	{
		if (prev)
			fd_close(&prev->_pipe[0]);
		return (-1);
	}
}

static int	_stdout(t_cmd *cmd, int final)
{
	fd_close(&cmd->_pipe[0]);
	if (cmd->_output_or_append)
	{
		fd_close(&cmd->_pipe[1]);
		if (cmd->_output_or_append == redir_output)
		{
			assert(cmd->_output_fd != -1);
			return (cmd->_output_fd);
		}
		else
		{
			assert(cmd->_append_fd != -1);
			return (cmd->_append_fd);
		}
	}
	else if (!final)
		return (cmd->_pipe[1]);
	else
	{
		fd_close(&cmd->_pipe[1]);
		return (-1);
	}
}

//	put in command->_io the fildes we will dup2 later; close the rest

static int	_cmd_fildes(t_cmdgrp *cgrp, t_cmd *command, size_t num)
{
	int		i;
	t_cmd	*cmd;
	t_cmd	*prev;

	prev = 0;
	i = (int) cgrp->cmds.nelem;
	while (--i >= 0)
	{
		cmd = *(t_cmd **) ft_arr_get(&cgrp->cmds, i);
		if (i > (int) num)
			_close_fildes(cmd);
		else if (i == (int) num)
		{
			cmd->_io[1] = _stdout(cmd, i == (int) cgrp->cmds.nelem - 1);
			if (i == 0)
				cmd->_io[0] = _stdin(cmd, 0);
		}
		else if (i + 1 == (int) num)
			prev->_io[0] = _stdin(prev, cmd);
		else
			_close_fildes(cmd);
		prev = cmd;
	}
	return (cmd_link(command));
}

/*
 *	1) treat all redirections
 *	2) close and keep relevant FDs
 *	3) link commands with their pipes or redirections
 *	in case of error, exit status is put in g_shell->_status
 */

int	cmd_fildes(t_cmdgrp *cgrp, t_cmd *command, size_t num)
{
	make_redirs(command);
	if (!cmd_redir(command))
		return (0);
	return (_cmd_fildes(cgrp, command, num));
}
