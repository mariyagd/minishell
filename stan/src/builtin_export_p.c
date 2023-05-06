/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:40:28 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 21:25:38 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_comp(char **s1, char **s2)
{
	return (ft_strcmp(*s1, *s2));
}

static int	_join(char **s, t_var *var)
{
	char	*s2;

	s2 = ft_strjoin(var->name, "=");
	if (!s2 || !ft_append(&s2, var->value))
		enomem();
	ft_free(*s);
	*s = s2;
	var_fini(var);
	return (1);
}

//	if char \e is found, it's replaced by string \E , and value => $'value'
//	else char " is escaped and value => "value"

static int	_dressup(char **s)
{
	t_var	var;

	if (!var_init(&var, *s))
		return (error("var_init", *s));
	if (var.value)
	{
		if (ft_strchr(var.value, '\e'))
		{
			if (!ft_replace(&var.value, "\e", "\\E")
				|| !ft_prepend(&var.value, "$'") || !ft_append(&var.value, "'"))
				enomem();
		}
		else
		{
			if (!ft_replace(&var.value, "\"", "\\\"")
				|| !ft_prepend(&var.value, "\"") || !ft_append(&var.value, "\""))
				enomem();
		}
	}
	else if (!ft_strdup2("\"\"", &var.value))
		enomem();
	return (_join(s, &var));
}

int	builtin_export_p(void)
{
	t_arr	lst;
	char	*s;
	size_t	i;

	if (!ft_arr_init(&lst, ft_count_arr(g_shell->env.data), sizeof(char *)))
		enomem();
	i = -1;
	while (++i < g_shell->env.nelem)
	{
		s = *(char **) ft_arr_get(&g_shell->env, i);
		s = ft_strdup(s);
		if (!s || !_dressup(&s) || !ft_arr_append(&lst, &s, 0))
			enomem();
	}
	ft_bsort(lst.data, lst.nelem, lst.unit, (t_compar) & _comp);
	i = -1;
	while (++i < lst.nelem)
	{
		s = *(char **) ft_arr_get(&lst, i);
		ft_printf("declare -x %s\n", s);
	}
	ft_arr_fini(&lst, &ft_del);
	return (0);
}
