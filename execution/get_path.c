/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:03:32 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/05 19:07:50 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	is_dir(char *path, t_cmd *cmd)
{
	struct stat	buf;

	if (stat(path, &buf) == 0)
	{
		if (S_ISDIR(buf.st_mode))
		{
			free_tab2d(cmd->cmd);
			cmd->cmd = NULL;
			return (1);
		}
	}
	return (0);
}

static int	extract_cmd_path(char *path, t_cmd *cmd)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	if (is_dir(path, cmd))
		return (1);
	while (path[end])
		end++;
	start = end--;
	while (path[start] != '/')
		start--;
	free(cmd->cmd[0]);
	cmd->cmd[0] = NULL;
	cmd->cmd[0] = ft_substr(path, start + 1, end - start);
	if (!cmd->cmd[0])
	{
		malloc_error_print_message("ft_substr failed");
		return (0);
	}
	return (1);
}

int	get_path(t_cmd *cmd)
{
	if (ft_strchr(cmd->cmd[0], '/'))
	{
		cmd->path = ft_strdup(cmd->cmd[0]);
		if (!cmd->path)
		{
			malloc_error_print_message("ft_strdup failed");
			return (0);
		}
		if (!extract_cmd_path(cmd->path, cmd))
			return (0);
	}
	else
		if (!search_path(cmd, g_shell->save_env))
			return (0);
	return (1);
}
