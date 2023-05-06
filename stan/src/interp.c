/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:18 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 15:07:11 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	'nd' keeps track of last node used

static int	_interp(t_shell *sh)
{
	t_token	tok;
	t_node	*root;
	t_node	*nd;

	root = node_new(0);
	nd = root;
	while (*sh->_ptr)
	{
		ft_memset(&tok, 0, sizeof(t_token));
		sh->_ptr = tokenize(sh->_ptr, &tok);
		if (tok.tp == tok_semicolon || tok.tp == tok_invalid)
			break ;
		if (tok.tp == tok_ampersand)
			return (error(0, "syntax") + node_del(&root));
		if (!parse(&tok, &nd, &root))
			return (token_fini(&tok) + node_del(&root));
		token_fini(&tok);
	}
	if (!ast_check(root))
		return (error(0, "syntax") + node_del(&root));
	exec(root);
	return (1 + node_del(&root));
}

//	returned value is ignored

int	interp(const char *s)
{
	assert(g_shell->_input == 0);
	g_shell->_input = (char *) s;
	g_shell->_ptr = (char *) s;
	while (*g_shell->_ptr)
	{
		if (!_interp(g_shell))
			break ;
	}
	shell_reset(g_shell);
	return (1);
}
