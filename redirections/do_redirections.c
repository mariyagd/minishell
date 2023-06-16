/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:20:24 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 14:04:52 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	redir_stdin(t_cmd *cmd)
{
	cmd->save_fdin = dup(STDIN_FILENO);
	if (cmd->ffd_in < 0)
	{
		error_message(strerror(errno));
		return (0);
	}
	dup2(cmd->ffd_in, STDIN_FILENO);
	close(cmd->ffd_in);
	cmd->ffd_in = -1;
	return (1);
}

static int	redir_heredoc(t_cmd *cmd, int j)
{
	char	*nb;
	char	*here_doc_file;

	nb = ft_itoa(j);
	if (!nb)
		return (0);
	here_doc_file = ft_strjoin(".here_doc", nb);
	if (!here_doc_file)
	{
		error_message("ft_strjoin failed\n");
		free(nb);
		return (0);
	}
	cmd->ffd_in = open(here_doc_file, O_RDONLY);
	free(nb);
	free(here_doc_file);
	if (cmd->ffd_in < 0)
	{
		error_message2("here_doc:", strerror(errno));
		return (0);
	}
	return (1);
}

int	redir_fdin(t_cmd *cmd, char *redir_op, char *file_path, int j)
{
	int		res;

	if (cmd->save_fdin != -1 || cmd->ffd_in != -1)
		restaure_fdin(cmd);
	if (ft_strlen(redir_op) == 1 && file_path)
	{
		cmd->ffd_in = open(file_path, O_RDONLY);
		if (cmd->ffd_in < 0)
		{
			error_message2(file_path, strerror(errno));
			return (0);
		}
	}
	else
	{
		if (!redir_heredoc(cmd, j))
			return (0);
	}
	res = redir_stdin(cmd);
	if (!res)
		return (0);
	return (1);
}

int	redir_fdout(t_cmd *cmd, char *redir_op, char *file_path)
{
	if (cmd->save_fdout != -1 || cmd->ffd_out != -1)
		restaure_fdout(cmd);
	cmd->save_fdout = dup(STDOUT_FILENO);
	if (ft_strlen(redir_op) == 1)
	{
		cmd->ffd_out = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
		cmd->ffd_out = open(file_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd->ffd_out < 0)
	{
		error_message2("open", strerror(errno));
		return (0);
	}
	dup2(cmd->ffd_out, STDOUT_FILENO);
	close(cmd->ffd_out);
	cmd->ffd_out = -1;
	return (1);
}
