/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:19:00 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/17 10:18:08 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	make_redirections_helper(t_cmd *cmd, int j, int i)
{
	if (ft_strncmp(cmd->redir[i], ">", 2) == 0 || \
		ft_strncmp(cmd->redir[i], ">>", 3) == 0)
	{
		if (!redir_fdout(cmd, cmd->redir[i], cmd->redir[i + 1]))
			return (-1);
		i++;
	}
	else if (ft_strncmp(cmd->redir[i], "<", 2) == 0)
	{
		if (!redir_fdin(cmd, cmd->redir[i], cmd->redir[i + 1], j))
			return (-1);
		i++;
	}
	else if (ft_strncmp(cmd->redir[i], "<<", 3) == 0)
	{
		if (!redir_fdin(cmd, cmd->redir[i], NULL, j))
			return (-1);
		if (cmd->redir[i + 1])
			i++;
		i++;
	}
	return (i);
}

int	ambiguous_redirections(t_cmd *cmd, int i)
{
	if ((ft_strncmp(cmd->redir[i], ">", 2) == 0 || \
		ft_strncmp(cmd->redir[i], ">>", 3) == 0 || \
		ft_strncmp(cmd->redir[i], "<", 2) == 0) && \
			!cmd->redir[i + 1])
	{
		ft_dprintf(2, "minishell: ambiguous redirect\n");
		g_shell->exit_status = 1;
		return (1);
	}
	return (0);
}

int	make_redirections(t_cmd *cmd, int j)
{
	int	i;

	i = 0;
	if (!cmd->redir)
		return (1);
	while (cmd->redir[i])
	{
		if (ambiguous_redirections(cmd, i))
			return (0);
		if (ft_strncmp(cmd->redir[i], ">", 2) == 0 || \
			ft_strncmp(cmd->redir[i], ">>", 3) == 0 || \
			ft_strncmp(cmd->redir[i], "<", 2) == 0 || \
			ft_strncmp(cmd->redir[i], "<<", 3) == 0)
		{
			i = make_redirections_helper(cmd, j, i);
			if (i == -1)
				return (0);
		}
		else
			i++;
	}
	return (1);
}
