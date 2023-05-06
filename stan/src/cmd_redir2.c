/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redir2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:36:23 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/11 19:15:49 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_redir_input(t_cmd *cmd, t_redir *redir)
{
	assert(redir->tp == redir_input);
	if (cmd->_input_fd != -1)
		fd_close(&cmd->_input_fd);
	cmd->_input_fd = open_file_ro(redir->str);
	if (cmd->_input_fd < 0)
		return (0);
	return (1);
}

int	cmd_redir_output(t_cmd *cmd, t_redir *redir)
{
	assert(redir->tp == redir_output);
	if (cmd->_output_fd != -1)
		fd_close(&cmd->_output_fd);
	cmd->_output_fd = open_file_wo(redir->str);
	if (cmd->_output_fd < 0)
		return (0);
	return (1);
}

int	cmd_redir_append(t_cmd *cmd, t_redir *redir)
{
	assert(redir->tp == redir_append);
	if (cmd->_append_fd != -1)
		fd_close(&cmd->_append_fd);
	cmd->_append_fd = open_file_wa(redir->str);
	if (cmd->_append_fd < 0)
		return (0);
	return (1);
}
