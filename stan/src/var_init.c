/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:24:41 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 21:40:27 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	split given string like:  somename='somevalue'
//	return 0 if varname is invalid
//	equal-sign might be missing
//	value might be missing, which means it's empty string

int	var_init(t_var *var, const char *s)
{
	char	*p;

	ft_memset(var, 0, sizeof(t_var));
	if (*s == '=')
		return (0);
	p = ft_strchr(s, '=');
	if (!p)
		p = ft_strchr(s, 0);
	else
		var->has_equal = 1;
	var->name = ft_strndup(s, p - s);
	if (!var->name)
		enomem();
	if (*p && *++p)
	{
		var->value = ft_strdup(p);
		if (!var->value)
			enomem();
	}
	if (!var_valid(var))
	{
		var_fini(var);
		return (0);
	}
	return (1);
}
