/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:04:51 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/09 10:19:43 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	print_export_unset_error(char *identifier, char *command)
{
	ft_dprintf(2, "minishell: %s: ", command);
	ft_dprintf(2, "`%s': not a valid identifier\n", identifier);
	g_shell->exit_status = 1;
}

/* 
 * NOTE: is_punct refers to all punctuation characters of the ascii table,
 * except the underscore. This is why we add s[i] == '_' to the condition.
 */

int	check_if_valid_identifier(char *s, char *command)
{
	int	i;

	i = 0;
	if (is_punct(s[0]) || ft_isdigit(s[0]) || s[0] == '_')
	{
		print_export_unset_error(s, command);
		return (0);
	}
	while (s[i] && s[i] != '=')
		i++;
	i--;
	if (is_punct(s[i]) || s[i] == ' ')
	{
		print_export_unset_error(s, command);
		return (0);
	}
	return (1);
}

/* 
 * NOTE: check_if_var_exists() is used in export.c and unset.c.
 * It checks if the variable exists in the environment.
 * If it does, it returns 1, else it returns 0.
 */

int	check_if_var_exists(char *s)
{
	t_env	*env;

	env = g_shell->env;
	while (env)
	{
		if (ft_strncmp(s, env->var_name, ft_strlen(s)) == 0)
			return (1);
		env = env->next;
	}
	return (0);
}
