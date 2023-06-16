/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:32:22 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 08:49:19 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	first_argument_is_numeric(t_cmd *cmd, int size)
{
	long long	exit_status;

	exit_status = 0;
	if (size == 2)
	{
		printf("exit\n");
		exit_status = ft_atoi(cmd->cmd[1]);
		free_before_exit(&cmd);
		exit (exit_status % 256);
	}
	else if (size > 2)
	{
		ft_dprintf(2, "exit\n");
		ft_dprintf(2, "minishell: exit: too many arguments\n");
		g_shell->exit_status = 1;
	}
}

static int	change_i(t_cmd *cmd, int i)
{
	while (cmd->cmd[1][i] == 32 || \
			(cmd->cmd[1][i] >= 9 && cmd->cmd[1][i] <= 13))
		i++;
	if (cmd->cmd[1][i] == '-')
		i++;
	else if (cmd->cmd[1][i] == '+')
		i++;
	return (i);
}

static int	check_exit_arguments(t_cmd *cmd)
{
	int	size;
	int	i;

	i = 0;
	size = size_tab2d(cmd->cmd);
	if (size == 1)
		return (0);
	i = change_i(cmd, i);
	if (is_numeric(&cmd->cmd[1][i]) && no_int_errors(&cmd->cmd[1][i]))
		first_argument_is_numeric(cmd, size);
	else
	{
		ft_dprintf(2, "exit\n");
		ft_dprintf(2, "minishell: exit: %s: ", cmd->cmd[1]);
		ft_dprintf(2, "numeric argument required\n");
		free_before_exit(&cmd);
		exit (255);
	}
	return (1);
}

void	ft_exit(t_cmd *cmd)
{
	int	res;
	int	exit_status;

	res = check_exit_arguments(cmd);
	if (!res)
	{
		exit_status = g_shell->exit_status;
		free_before_exit(&cmd);
		printf("exit\n");
		exit (exit_status);
	}
}
