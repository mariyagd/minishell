/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_undef.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:59:57 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/10 09:12:46 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_undef(t_node **nd, t_token *tok)
{
	t_node	*nd2;

	assert((*nd)->tp == nd_undef);
	if (tok->tp <= 5)
	{
		(*nd)->tp = nd_cmd;
		(*nd)->cmdgrp = cmdgrp_new();
		if (!(*nd)->cmdgrp)
			return (enomem());
		if (!cmdgrp_add((*nd)->cmdgrp, tok))
			return (error(0, "syntax"));
	}
	else if (tok->tp == tok_lparen)
	{
		(*nd)->tp = nd_paren;
		nd2 = node_new(*nd);
		if (!nd2)
			return (enomem());
		(*nd)->left = nd2;
		*nd = nd2;
	}
	else
		return (error(0, "syntax"));
	return (1);
}
