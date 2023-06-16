/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_shlvl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:58:07 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 14:03:20 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	var_value_not_numeric(t_env *env)
{
	free(env->var_value);
	env->var_value = ft_strdup("1");
	if (!env->var_value)
	{
		malloc_error_print_message("ft_strdup failed");
		return (0);
	}
	return (1);
}

static int	var_value_is_numeric(t_env *env)
{
	int		i;

	i = ft_atoi(env->var_value) + 1;
	free(env->var_value);
	env->var_value = NULL;
	env->var_value = ft_itoa(i);
	if (!env->var_value)
	{
		malloc_error_print_message("ft_itoa failed");
		return (0);
	}
	return (1);
}

static t_env	*create_new(void)
{
	t_env	*new;

	new = ft_calloc(1, sizeof(t_env));
	if (!new)
	{
		malloc_error_print_message("ft_calloc failed");
		return (NULL);
	}
	new->var_name = ft_strdup("SHLVL");
	if (!new->var_name)
	{
		free(new);
		malloc_error_print_message("ft_strdup failed");
		return (NULL);
	}
	new->var_value = ft_strdup("1");
	if (!new->var_value)
	{
		free(new->var_name);
		free(new);
		malloc_error_print_message("ft_strdup failed");
		return (NULL);
	}
	return (new);
}

static int	create_shlvl(void)
{
	t_env	*env;
	t_env	*prev;
	t_env	*new;

	env = g_shell->env;
	prev = NULL;
	new = create_new();
	if (!new)
		return (0);
	while (env->next)
	{
		prev = env;
		env = env->next;
	}
	if (prev)
	{
		prev->next = new;
		new->next = env;
	}
	else
		g_shell->env = new;
	return (1);
}

int	increment_shlvl(void)
{
	t_env	*env;

	env = g_shell->env;
	while (env)
	{
		if (ft_strncmp(env->var_name, "SHLVL", 6) == 0)
		{
			if (!is_numeric(env->var_value))
			{
				if (!var_value_not_numeric(env))
					return (0);
				return (1);
			}
			else
			{
				if (!var_value_is_numeric(env))
					return (0);
				return (1);
			}
		}
		env = env->next;
	}
	if (!create_shlvl())
		return (0);
	return (1);
}
