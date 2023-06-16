/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:08:07 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/24 21:14:46 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*get_env_var_value(char *var_name)
{
	t_env	*env;

	env = g_shell->env;
	while (env != NULL)
	{
		if (ft_strncmp(env->var_name, var_name, ft_strlen(var_name)) == 0)
			return (env->var_value);
		env = env->next;
	}
	return (NULL);
}
