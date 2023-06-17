/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:35:31 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 08:53:47 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	print_echo(char **s, int i)
{
	int	size;

	size = i;
	while (s[size])
		size++;
	if (size == i)
		return ;
	while (s[i])
	{
		ft_printf("%s", s[i]);
		if (i != size - 1)
			ft_printf(" ");
		i++;
	}
}

static int	size_echo_cmd(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	_echo(t_cmd *cmd)
{
	int	i;

	i = 1;
	if (size_echo_cmd(cmd->cmd) == 1)
	{
		ft_printf("\n");
		g_shell->exit_status = 0;
		return (1);
	}
	if (ft_strncmp(cmd->cmd[i], "-n", 3) != 0)
	{
		print_echo(cmd->cmd, 1);
		ft_printf("\n");
	}
	else
	{
		while (cmd->cmd[i] && ft_strncmp(cmd->cmd[i], "-n", 3) == 0)
			i++;
		if (cmd->cmd[i])
			print_echo(cmd->cmd, i);
	}
	g_shell->exit_status = 0;
	return (1);
}
