/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/16 00:17:57 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exit(t_cmdgrp *cgrp, t_cmd *cmd)
{
	char	**p;
	int		i;

	(void) cgrp;
	p = ft_arr_get(&cmd->args, 1);
	if (!p)
		i = g_shell->retval;
	else
	{
		if (!ft_atoi(*p, &i))
		{
			ft_dprintf(1, "exit\n");
			ft_dprintf(2, "error: exit: numeric argument required\n");
			return (finish(1, 0));
		}
	}
	return (finish(i, 1));
}
