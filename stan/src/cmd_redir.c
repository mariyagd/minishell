/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:24:16 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/28 14:54:14 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_clean_redirect(char **str)
{
	int		i;
	t_arr	new_arg;
	char	*tmp;
	t_scan	scan;

	ft_memset(&scan, 0, sizeof(t_scan));
	if (!ft_arr_init(&new_arg, 4, sizeof(char)))
		enomem();
	i = -1;
	while ((*str)[++i])
	{
		if (scan_quotes((*str)[i], &scan))
			;
		else if (!ft_arr_append(&new_arg, &(*str)[i], 0))
			enomem();
	}
	if (!ft_strdup2(new_arg.data, &tmp))
		enomem();
	ft_arr_fini(&new_arg, 0);
	ft_free(*str);
	*str = tmp;
}

static int	_treat_heredocs(t_cmd *cmd)
{
	size_t	i;
	t_redir	*redir;

	i = -1;
	while (++i < cmd->redirs.nelem)
	{
		redir = (t_redir *) ft_arr_get(&cmd->redirs, i);
		if (redir->tp == redir_heredoc)
		{
			if (cmd->_heredoc_fd != -1)
				fd_close(&cmd->_heredoc_fd);
			cmd->_heredoc_fd = open_file_hd(redir->str);
			if (cmd->_heredoc_fd == -1)
				return (0);
		}
	}
	return (1);
}

static int	_treat_others_cont(t_cmd *cmd, t_redir *redir)
{
	if (redir->tp == redir_input)
	{
		if (!cmd_redir_input(cmd, redir))
			return (0);
	}
	else if (redir->tp == redir_output)
	{
		if (!cmd_redir_output(cmd, redir))
			return (0);
	}
	else if (redir->tp == redir_append)
	{
		if (!cmd_redir_append(cmd, redir))
			return (0);
	}
	return (1);
}

static int	_treat_others(t_cmd *cmd)
{
	size_t	i;
	t_redir	*redir;

	i = -1;
	while (++i < cmd->redirs.nelem)
	{
		redir = (t_redir *) ft_arr_get(&cmd->redirs, i);
		if (redir_ambiguous(redir->str))
			return (0);
		_clean_redirect(&redir->str);
		if (!_treat_others_cont(cmd, redir))
			return (0);
	}
	return (1);
}

/*
 *	Treat redirections (read heredocs, open input files, open output files)
 *	Of each, the last FD opened is kept,
 *	and the FDs not used are immediately closed
 */

int	cmd_redir(t_cmd *cmd)
{
	if (!_treat_heredocs(cmd))
	{
		cmd->_status = 2;
		return (0);
	}
	if (!_treat_others(cmd))
	{
		cmd->_status = 1;
		return (0);
	}
	if (cmd->_input_or_heredoc)
	{
		if (cmd->_input_or_heredoc == redir_input)
			fd_close(&cmd->_heredoc_fd);
		else
			fd_close(&cmd->_input_fd);
	}
	if (cmd->_output_or_append)
	{
		if (cmd->_output_or_append == redir_output)
			fd_close(&cmd->_append_fd);
		else
			fd_close(&cmd->_output_fd);
	}
	return (1);
}
