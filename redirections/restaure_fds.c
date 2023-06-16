/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restaure_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:22:32 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/16 14:01:31 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	delete_here_doc(int i)
{
	char	*file;
	char	*nb;

	nb = ft_itoa(i);
	if (!nb)
		ft_dprintf(2, "minishell: ft_itoa failed\n");
	file = ft_strjoin(".here_doc", nb);
	if (!file)
		ft_dprintf(2, "minishell: ft_strjoin failed\n");
	if (!file || !nb)
	{
		if (file)
			free(file);
		if (nb)
			free(nb);
		return ;
	}
	if (access(file, F_OK) == 0)
		unlink(file);
	free(file);
	free(nb);
}

void	restaure_fds(t_cmd *cmd, int i)
{
	if (!cmd)
		return ;
	if (cmd->save_fdout != -1)
	{
		dup2(cmd->save_fdout, STDOUT_FILENO);
		close(cmd->save_fdout);
		cmd->save_fdout = -1;
	}
	if (cmd->save_fdin != -1)
	{
		dup2(cmd->save_fdin, STDIN_FILENO);
		close(cmd->save_fdin);
		cmd->save_fdin = -1;
	}
	delete_here_doc(i);
}

void	restaure_fdin(t_cmd *cmd)
{
	if (cmd->save_fdin != -1)
	{
		dup2(cmd->save_fdin, STDIN_FILENO);
		close(cmd->save_fdin);
		cmd->save_fdin = -1;
	}
}

void	restaure_fdout(t_cmd *cmd)
{
	if (cmd->save_fdout != -1)
	{
		dup2(cmd->save_fdout, STDOUT_FILENO);
		close(cmd->save_fdout);
		cmd->save_fdout = -1;
	}
}
