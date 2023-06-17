/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:59:32 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/09 10:03:04 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	change_env_var(char *s, char *var_name, int i)
{
	t_env	*env;

	env = g_shell->env;
	while (env)
	{
		if (ft_strncmp(var_name, env->var_name, ft_strlen(var_name)) == 0)
			break ;
		env = env->next;
	}
	free(env->var_value);
	env->var_value = NULL;
	env->var_value = ft_substr(s, i + 1, ft_strlen(s) - (i + 1));
	if (!env->var_value)
	{
		malloc_error_print_message("ft_strdup failed");
		return (0);
	}
	return (1);
}

static int	export_with_args_helper(char *var_name, char *s, int i)
{
	int		res;
	t_env	*new;

	res = check_if_var_exists(var_name);
	if (!res)
	{
		new = new_env(s);
		if (!new)
			return (0);
		if (!g_shell->env)
			g_shell->env = new;
		else
			link_env(&g_shell->env, new);
	}
	else if (res && s[i] == '=')
	{
		if (!change_env_var(s, var_name, i))
			return (0);
	}
	return (1);
}

static int	export_with_args(char *s)
{
	int		res;
	int		i;
	char	*var_name;

	i = 0;
	res = check_if_valid_identifier(s, "export");
	if (!res)
		return (0);
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=' && (is_blank(s[i - 1]) || is_blank(s[i + 1])))
	{
		print_export_unset_error(s, "export");
		return (0);
	}
	var_name = ft_substr(s, 0, i);
	if (!var_name)
	{
		malloc_error_print_message("ft_substr failed");
		return (ERROR_EXIT);
	}
	res = export_with_args_helper(var_name, s, i);
	free(var_name);
	return (res);
}

static void	export_no_args(void)
{
	t_env	*env;

	env = g_shell->env;
	while (env)
	{
		if (env->var_value)
		{
			ft_printf("declare -x %s=", env->var_name);
			ft_printf("\"%s\"\n", env->var_value);
		}
		else
			ft_printf("declare -x %s\n", env->var_name);
		env = env->next;
	}
}

/*
 * ZERO - 0 - always indicates an malloc error, and the programme must exit
 * ONE - 1 - indicates success, even if the function print an error message
 */

void	_export(t_cmd *cmd)
{
	int	i;
	int	res;
	int	save;

	save = 1;
	i = size_tab2d(cmd->cmd);
	if (i == 1)
	{
		export_no_args();
		return ;
	}
	i = 1;
	while (cmd->cmd[i])
	{
		res = export_with_args(cmd->cmd[i]);
		if (res == ERROR_EXIT)
			free_and_exit_prog(&cmd, 1);
		else if (!res)
			save = res;
		i++;
	}
	if (!save)
		g_shell->exit_status = 1;
	else
		g_shell->exit_status = 0;
}
