/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_subst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:59:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/05 00:14:33 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	node_subst(t_node *nd, t_node *nd2, int leftside, t_node **root)
{
	nd2->parent = nd->parent;
	if (nd->parent)
	{
		if (nd->parent->left == nd)
			nd->parent->left = nd2;
		else
			nd->parent->right = nd2;
	}
	else
		*root = nd2;
	nd->parent = nd2;
	if (leftside)
		nd2->left = nd;
	else
		nd2->right = nd;
}
