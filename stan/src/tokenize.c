/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:17:03 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/25 19:32:58 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_tokspec
{
	char		*str;
	size_t		len;
	t_toktype	tp;
}	t_tokspec;

static int	_skip_spaces(const char **s)
{
	while (**s && ft_isspace(**s))
		++(*s);
	if (!(**s))
		return (0);
	return (1);
}

char	*tokenize(const char *s, t_token *tok)
{
	t_tokspec				*spec;
	static const t_tokspec	tokspecs[] = {{"&&", 2, tok_and},
	{">>", 2, tok_append}, {"<<", 2, tok_heredoc}, {"||", 2, tok_or},
	{"(", 1, tok_lparen}, {")", 1, tok_rparen}, {">", 1, tok_output},
	{"<", 1, tok_input}, {"|", 1, tok_pipe}, {";", 1, tok_semicolon},
	{"&", 1, tok_ampersand}, {0}};

	if (!_skip_spaces(&s))
	{
		tok->tp = tok_invalid;
		return ((char *) s);
	}
	spec = (t_tokspec *) &tokspecs[0];
	while (spec->str)
	{
		if (*s == *spec->str
			&& (spec->len == 1 || !ft_strncmp(s, spec->str, spec->len)))
		{
			tok->tp = spec->tp;
			return ((char *) s + spec->len);
		}
		++spec;
	}
	return (tokenize_var(s, tok));
}
