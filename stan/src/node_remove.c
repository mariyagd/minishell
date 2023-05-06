/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:16:50 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/05 01:20:23 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	node_remove(t_node *nd, t_node *child, t_node **root)
{
	assert(nd->left == child || nd->right == child);
	child->parent = nd->parent;
	if (nd->parent)
	{
		if (nd->parent->left == nd)
			nd->parent->left = child;
		else
			nd->parent->right = child;
	}
	else
		*root = child;
}
