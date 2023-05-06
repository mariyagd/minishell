/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/25 09:53:11 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_export(t_cmdgrp *cgrp, t_cmd *cmd)
{
	size_t	i;
	char	*s;
	t_var	var;

	(void) cgrp;
	if (cmd->args.nelem == 1)
		return (builtin_export_p());
	i = 0;
	while (++i < cmd->args.nelem)
	{
		s = *(char **) ft_arr_get(&cmd->args, i);
		if (!*s || !var_init(&var, s))
			return (1);
		if (!var.value && var.has_equal && !ft_strdup2("", &var.value))
			enomem();
		assert(var.value);
		if (!env_set(&g_shell->env, var.name, var.value))
			enomem();
		var_fini(&var);
	}
	return (0);
}
