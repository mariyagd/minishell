/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:11:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/12 19:09:38 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_cmdgrp *cgrp, t_cmd *cmd)
{
	size_t	i;

	(void) cgrp;
	(void) cmd;
	i = -1;
	while (++i < g_shell->env.nelem)
		ft_printf("%s\n", *(char **) ft_arr_get(&g_shell->env, i));
	return (0);
}
