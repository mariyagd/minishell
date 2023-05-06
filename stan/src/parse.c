/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:51:08 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/10 09:01:01 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse(t_token *tok, t_node **nd, t_node **root)
{
	if ((*nd)->tp == nd_undef)
		return (parse_undef(nd, tok));
	else if ((*nd)->tp == nd_cmd)
		return (parse_cmd(nd, tok, root));
	else if ((*nd)->tp == nd_and || (*nd)->tp == nd_or)
		return (parse_logop(nd, tok, root));
	else
	{
		ft_dprintf(2, "error: parse: nd->tp = %d\n", (*nd)->tp);
		assert(0);
	}
	return (0);
}
