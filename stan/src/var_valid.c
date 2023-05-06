/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:04:22 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 17:24:55 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_varname_valid(const char *s)
{
	if (!ft_isalpha(*s) && *s != '_')
		return (0);
	while (*++s)
	{
		if (!ft_isalnum(*s) && *s != '_')
			return (0);
	}
	return (1);
}

//	nb: variable name cant be a variable itself, but value can be a variable

int	var_valid(const t_var *var)
{
	if (!var->name || !_varname_valid(var->name))
		return (0);
	return (1);
}
