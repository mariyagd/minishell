/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path_in_env_table.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:00:14 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/10 17:59:21 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	copy_path(int start, int end, char *s, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (start < end)
	{
		cmd->path[i] = s[start];
		i++;
		start++;
	}
	cmd->path[i] = '/';
	i++;
	start = 0;
	while (cmd->cmd[0][start])
	{
		cmd->path[i] = cmd->cmd[0][start];
		i++;
		start++;
	}
	cmd->path[i] = '\0';
}

static int	check_access(int start, int end, char *s, t_cmd *cmd)
{
	int	size;

	size = end - start + ft_strlen(cmd->cmd[0]) + 2;
	cmd->path = malloc(sizeof(char) * size);
	if (!cmd->path)
	{
		malloc_error_print_message("ft_substr failed");
		g_shell->exit_status = 1;
		return (ERROR_EXIT);
	}
	copy_path(start, end, s, cmd);
	if (access(cmd->path, F_OK & X_OK) == 0)
		return (1);
	free(cmd->path);
	cmd->path = NULL;
	return (0);
}

static int	check_each_path(char *s, t_cmd *cmd)
{
	int	i;
	int	start;
	int	res;

	i = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] == ':')
		{
			res = check_access(start, i, s, cmd);
			if (res == 1)
				return (1);
			else if (res == ERROR_EXIT)
				return (0);
			start = i + 1;
		}
		i++;
	}
	res = check_access(start, i, s, cmd);
	if (res == 1 || res == 0)
		return (1);
	return (0);
}

int	search_path(t_cmd *cmd, char **env)
{
	int	i;
	int	res;

	i = 0;
	while (env[i] && ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	if (!env[i])
	{
		ft_dprintf(2, "minishell: %s: No such file or directory\n", cmd->cmd[0]);
		g_shell->exit_status = 127;
		return (0);
	}
	if (cmd->cmd[0][0] == 0)
		return (1);
	res = check_each_path((env[i] + 5), cmd);
	return (res);
}
