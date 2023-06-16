/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:34:45 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/27 15:27:08 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	check_env(t_cmd *cmd)
{
	int	size;

	size = size_tab2d(cmd->cmd);
	if (size == 1)
		return (1);
	ft_dprintf(2, "env: %s: ", cmd->cmd[1]);
	ft_dprintf(2, "No such file or directory\n");
	g_shell->exit_status = 127;
	return (0);
}

void	_env(t_cmd *cmd, t_env *env)
{
	int	res;

	res = check_env(cmd);
	if (!res)
		return ;
	if (!env)
	{
		g_shell->exit_status = 0;
		return ;
	}
	while (env != NULL)
	{
		if (env->var_value)
		{
			ft_printf("%s=", env->var_name);
			if (env->var_value)
				ft_printf("%s\n", env->var_value);
		}
		env = env->next;
	}
	g_shell->exit_status = 0;
	return ;
}
