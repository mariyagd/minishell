/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arg0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:53:46 by srapopor          #+#    #+#             */
/*   Updated: 2023/02/26 00:28:18 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*_ret_arg0(t_cmd *cmd)
{
	assert(cmd->_arg0);
	if (!*cmd->_arg0)
		return (0);
	return (cmd->_arg0);
}

//	find the 'real' command; return null if there are only redirs
//	result is stored so that we dont compute it two times

char	*make_arg0(t_cmd *cmd)
{
	char	*full_cmd;
	t_scan	scan;
	char	*p;

	if (cmd->_arg0)
		return (_ret_arg0(cmd));
	full_cmd = make_cmd(cmd);
	if (!*full_cmd)
	{
		cmd->_arg0 = full_cmd;
		return (0);
	}
	p = full_cmd;
	while (ft_isspace(*p))
		++p;
	ft_memset(&scan, 0, sizeof(t_scan));
	cmd->_arg0 = scan_cmd_arg(&p, &scan);
	unbs(&cmd->_arg0);
	if (!*cmd->_arg0)
		return (0);
	return (cmd->_arg0);
}
