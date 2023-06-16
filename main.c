/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:56:41 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 14:02:16 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_shell	*g_shell;

char	*readline_routine(void)
{
	char	*line;

	line = NULL;
	line = readline("minishell$ ");
	if (!line)
	{
		rl_clear_history();
		return (NULL);
	}
	if (line[0])
		add_history(line);
	return (line);
}

void	check_for_malloc_error(t_cmd **head)
{
	if (g_shell->error_exit == 1)
		free_and_exit_prog(head, 1);
}

/* FOR TESTING
 *
 print_cmd(&cmd);
 */
/*
void	print_cmd(t_cmd **head)
{
	t_cmd	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_printf("command print\n");
	if (!head || !*head)
		return ;
	ptr = *head;
	while (ptr)
	{
		if (ptr->cmd)
		{
			while (ptr->cmd[j])
			{
				ft_printf("cmd[%d] = ", i);
				ft_printf("%s\n", ptr->cmd[j]);
				j++;
			}
		}
		j = 0;
		if (ptr->redir)
		{
			while (ptr->redir[j])
			{
				ft_printf("redir[%d] = ", i);
				ft_printf("%s\n", ptr->redir[j]);
				j++;
			}
		}
		if (ptr->path)
		{
			ft_printf("path[%d] = ", i);
			ft_printf("%s\n", ptr->path);
		}
		j = 0;
		i++;
		ptr = ptr->next;
	}
	printf("command print end\n");
}
*/

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_token	*token;
	t_cmd	*cmd;
	int		exit_status;

	(void)av;
	(void)ac;
	if (!init_shell(envp))
		return (1);
	while (1)
	{
		parent_signal_handler();
		line = readline_routine();
		if (!line)
			break ;
		token = parsing(line);
		cmd = cmd_linked_list(&token);
		execution(&cmd);
		check_for_malloc_error(&cmd);
		free_cmd(&cmd);
	}
	exit_status = g_shell->exit_status;
	free_shell();
	printf("exit\n");
	return (exit_status);
}

/* FOR TESTING PRINTING ENV
 *
 * use print_env();
 *
static void	print_env()
{
	t_env	*ptr;

	ptr = g_shell->env;
	if (!g_shell || !g_shell->env)
		return ;
	while (g_shell->env)
	{
		ft_printf("print_env function: %s\n", g_shell->env->var_name);
		if (g_shell->env->var_value)
			ft_printf("print_env function: %s\n", g_shell->env->var_value);
		g_shell->env = g_shell->env->next;
	}
	g_shell->env = ptr;
}*/
