/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:04:29 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/06 12:04:13 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	env_list_size(t_env **head)
{
	t_env	*env;
	int		i;

	env = *head;
	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

static void	free_env_var(t_env *curr)
{
	free(curr->var_name);
	if (curr->var_value)
		free(curr->var_value);
	free(curr);
}

static void	delete_env_helper(t_env **head, t_env *curr, \
								t_env *prev, int i)
{
	int		size;

	size = env_list_size(head);
	if (i == 0 && size == 1)
	{
		free_env_var(curr);
		*head = NULL;
		return ;
	}
	else if (i == 0 && size > 1)
	{
		*head = curr->next;
		prev = *head;
	}
	else if (i == size - 1)
		prev->next = NULL;
	else
		prev->next = curr->next;
	free_env_var(curr);
	return ;
}

static void	delete_env_var(t_env **head, char *s)
{
	int		i;
	t_env	*curr;
	t_env	*prev;

	i = 0;
	curr = *head;
	prev = NULL;
	while (curr && ft_strncmp(s, curr->var_name, ft_strlen(s)) != 0)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	if (!curr)
		return ;
	if (ft_strncmp(s, curr->var_name, ft_strlen(s)) == 0)
		delete_env_helper(head, curr, prev, i);
	g_shell->exit_status = 0;
}

void	_unset(t_cmd *cmd)
{
	int	i;
	int	res;
	int	save;

	i = 1;
	res = 0;
	save = 1;
	while (cmd->cmd[i])
	{
		res = check_if_valid_identifier(cmd->cmd[i], "unset");
		if (res)
			delete_env_var(&g_shell->env, cmd->cmd[i]);
		else if (!res)
			save = res;
		i++;
	}
	if (!save)
		g_shell->exit_status = 1;
}
