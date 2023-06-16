/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:39:06 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/10 17:25:33 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	column_size(t_env **head)
{
	t_env	*tmp;
	int		count;

	tmp = *head;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

char	*joined_malloc(int len_name, int len_value)
{
	char	*joined_1;

	joined_1 = malloc(sizeof(char) * (len_name + len_value + 2));
	if (!joined_1)
	{
		malloc_error_print_message(strerror(errno));
		return (NULL);
	}
	return (joined_1);
}

char	*name_plus_value(char *name, char *value)
{
	char	*joined;
	int		len_name;
	int		len_value;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len_name = ft_strlen(name);
	len_value = 0;
	if (value)
		len_value = ft_strlen(value);
	joined = joined_malloc(len_name, len_value);
	while (i < len_name)
		joined[i++] = name[j++];
	joined[i] = '=';
	j = 0;
	i++;
	while (j < len_value)
		joined[i++] = value[j++];
	joined[i] = '\0';
	return (joined);
}

int	copy_env_tab(void)
{
	int		column;
	int		i;
	t_env	*env;

	env = g_shell->env;
	i = 0;
	column = column_size(&env);
	if (column == 0)
		return (1);
	g_shell->save_env = malloc(sizeof(char *) * (column + 1));
	if (!g_shell->save_env)
	{
		malloc_error_print_message(strerror(errno));
		return (0);
	}
	while (env)
	{
		g_shell->save_env[i] = name_plus_value(env->var_name, env->var_value);
		if (!g_shell->save_env[i])
			return (0);
		i++;
		env = env->next;
	}
	g_shell->save_env[i] = NULL;
	return (1);
}
