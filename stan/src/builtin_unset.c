/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/11 21:03:12 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_unset(t_cmdgrp *cgrp, t_cmd *cmd)
{
	size_t	i;
	char	*s;

	(void) cgrp;
	i = 0;
	while (++i < cmd->args.nelem)
	{
		s = *(char **) ft_arr_get(&cmd->args, i);
		if (!*s)
			continue ;
		if (!env_unset(&g_shell->env, s))
			error("env_unset", s);
	}
	return (0);
}
