/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdgrp_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:46:32 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 19:17:47 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_cmdgrp_add_pipe(t_cmdgrp *cgrp)
{
	t_cmd	*cmd;

	if (cgrp->cmds.nelem == 0)
		return (0);
	else
	{
		cmd = *(t_cmd **) ft_arr_get(&cgrp->cmds, cgrp->cmds.nelem - 1);
		if (cmd->_expect || cmd->args.nelem == 0)
			return (0);
	}
	cmd = cmd_new();
	if (!cmd || !ft_arr_append(&cgrp->cmds, &cmd, 0))
		return (enomem());
	return (1);
}

static int	_redir_add(t_cmd *cmd, char *data)
{
	t_redir	redir;

	assert(cmd->_expect);
	redir.tp = cmd->_expect;
	redir.str = data;
	if (!ft_arr_append(&cmd->redirs, &redir, 0))
		return (enomem());
	if (redir.tp == redir_input)
		cmd->_input_or_heredoc = redir_input;
	else if (redir.tp == redir_heredoc)
		cmd->_input_or_heredoc = redir_heredoc;
	else if (redir.tp == redir_output)
		cmd->_output_or_append = redir_output;
	else if (redir.tp == redir_append)
		cmd->_output_or_append = redir_append;
	else
		assert(0);
	return (1);
}

static int	_cmdgrp_add_var(t_cmdgrp *cgrp, t_token *tok)
{
	t_cmd	*cmd;

	cmd = cmdgrp_cmd(cgrp);
	if (!cmd)
		return (enomem());
	if (!cmd->_expect)
	{
		if (cgrp->_subshell)
			return (0);
		if (!ft_arr_append(&cmd->args, &tok->data, 0))
			return (enomem());
	}
	else
	{
		if (!_redir_add(cmd, tok->data))
			return (enomem());
		cmd->_expect = 0;
	}
	tok->data = 0;
	return (1);
}

static int	_cmdgrp_add_chevron(t_cmdgrp *cgrp, t_toktype tp)
{
	t_cmd	*cmd;

	assert(tp >= 1 && tp <= 4);
	cmd = cmdgrp_cmd(cgrp);
	if (!cmd || cmd->_expect)
		return (0);
	cmd->_expect = tp;
	return (1);
}

int	cmdgrp_add(t_cmdgrp *cgrp, t_token *tok)
{
	assert(cgrp);
	assert(tok->tp <= 5);
	if (tok->tp == tok_pipe)
		return (_cmdgrp_add_pipe(cgrp));
	if (tok->tp == tok_var)
		return (_cmdgrp_add_var(cgrp, tok));
	return (_cmdgrp_add_chevron(cgrp, tok->tp));
}
