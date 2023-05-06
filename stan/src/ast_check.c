/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:46:27 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 18:58:08 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_check_cmdgrp(const t_node *nd)
{
	t_arr	*cmds;
	size_t	i;

	cmds = &nd->cmdgrp->cmds;
	i = -1;
	while (++i < cmds->nelem)
	{
		if (!cmd_valid(*(t_cmd **) ft_arr_get(cmds, i)))
			return (0);
	}
	return (1);
}

int	ast_check(const t_node *nd)
{
	if (nd->tp == nd_cmd)
	{
		if (!_check_cmdgrp(nd))
			return (0);
	}
	else if (nd->tp == nd_paren)
		return (0);
	if (nd->left && !ast_check(nd->left))
		return (0);
	if (nd->right && !ast_check(nd->right))
		return (0);
	return (1);
}
