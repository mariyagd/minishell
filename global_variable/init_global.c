/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:45:47 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 12:08:44 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/* EST_CE QUÓN GARDE SAVE_ENV */
void	free_shell(void)
{
	free_env(&g_shell->env);
	if (g_shell->save_env)
		free_tab2d(g_shell->save_env);
	if (g_shell)
		free(g_shell);
}

static int	shell_no_env(void)
{
	t_env	*env_no;

	env_no = malloc(sizeof(t_env));
	if (!env_no)
	{
		malloc_error_print_message(strerror(errno));
		return (0);
	}
	env_no->var_name = ft_strdup("SHLVL");
	env_no->var_value = ft_strdup("1");
	env_no->next = NULL;
	g_shell->env = env_no;
	return (1);
}

void	reset_oldpwd(void)
{
	t_env	*env;

	env = g_shell->env;
	while (env)
	{
		if (ft_strncmp(env->var_name, "OLDPWD", 7) == 0)
		{
			free(env->var_value);
			env->var_value = NULL;
			break ;
		}
		env = env->next;
	}
}

int	init_shell(char **envp)
{
	g_shell = ft_calloc(1, sizeof(t_shell));
	if (!g_shell)
	{
		ft_dprintf(2, "minishell: malloc: %s\n", strerror(errno));
		return (0);
	}
	if (!*envp)
	{
		if (!shell_no_env())
			return (0);
	}
	else
	{
		g_shell->env = get_envp(envp);
		if (!g_shell->env)
			return (free_shell(), 0);
		if (!increment_shlvl())
			return (free_shell(), 0);
		reset_oldpwd();
	}
	return (1);
}
