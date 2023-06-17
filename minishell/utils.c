/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:40:05 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/29 14:44:13 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	free_before_exit(t_cmd **head)
{
	free_shell();
	free_cmd(head);
}

int	size_tab2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_and_exit_prog(t_cmd **head, int exit_code)
{
	free_cmd(head);
	free_shell();
	exit (exit_code);
}
