/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:45:52 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/13 01:57:48 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_node_fini(t_node *nd)
{
	if (nd->left)
		node_del(&nd->left);
	if (nd->right)
		node_del(&nd->right);
	if (nd->cmdgrp)
		cmdgrp_del(&nd->cmdgrp);
}

int	node_del(t_node **nd)
{
	assert(*nd);
	_node_fini(*nd);
	ft_free(*nd);
	*nd = 0;
	return (0);
}
