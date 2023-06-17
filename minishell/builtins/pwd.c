/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:36:17 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/06 17:04:16 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	print_getcwd_error(char *s)
{
	ft_dprintf(2, "minishell: cd: getcwd: %s\n", s);
	g_shell->exit_status = 1;
}

void	_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		print_getcwd_error(strerror(errno));
		return ;
	}
	ft_printf("%s\n", cwd);
	free(cwd);
	g_shell->exit_status = 0;
	return ;
}
