/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg_to_full_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:47:06 by srapopor          #+#    #+#             */
/*   Updated: 2023/02/25 21:02:10 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_add_env_var(t_arr *new_string, char **str)
{
	char	*var_name;
	int		i;
	char	*env_variable;

	i = 1;
	while ((*str)[i] && !ft_strchr("\"|<> \'()&\n", (*str)[i]))
		++i;
	if (!ft_strndup2((*str) + 1, i - 1, &var_name))
		enomem();
	*str += i;
	env_variable = ft_env_var(var_name, g_shell->env.data);
	ft_free(var_name);
	if (!env_variable)
		return ;
	while (*env_variable)
	{
		if (!ft_arr_append(new_string, env_variable, 0))
			enomem();
		++env_variable;
	}
}

static void	_print_retval(t_arr *new_str)
{
	char	buf[12];
	char	*p;

	ft_itoa(g_shell->retval, buf);
	p = &buf[0];
	while (*p)
	{
		if (!ft_arr_append(new_str, p, 0))
			enomem();
		++p;
	}
}

//	this function scans the 'str', expanding variables, and puts the result
//	into 'new_string'

void	add_arg_to_full_command(t_arr *new_string, char *str)
{
	t_scan	scan;

	ft_memset(&scan, 0, sizeof(t_scan));
	while (*str)
	{
		scan_quotes(*str, &scan);
		if (*str == '$' && !scan.within_single_quotes)
		{
			if (*(str + 1) == '?')
			{
				_print_retval(new_string);
				str += 2;
			}
			else
				_add_env_var(new_string, &str);
			continue ;
		}
		if (!ft_arr_append(new_string, str, 0))
			enomem();
		++str;
	}
}
