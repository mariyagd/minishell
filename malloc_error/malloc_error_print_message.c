/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error_print_message.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:22:35 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/10 12:04:21 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	malloc_error_print_message(char *s)
{
	ft_dprintf(2, "minishell: malloc: %s\n", s);
	g_shell->error_exit = 1;
	g_shell->exit_status = 1;
}

void	error_message(char *s)
{
	ft_dprintf(2, "minishell: %s\n", s);
	g_shell->exit_status = 1;
}

void	error_message2(char *s1, char *s2)
{
	ft_dprintf(2, "minishell: %s %s\n", s1, s2);
	g_shell->exit_status = 1;
}
