/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:10:32 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/18 10:15:40 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/* A METACHARACTER IS A BLANK, A NEWLINE, A CHEVRON OR A PIPELINE */

int	is_metacharacter(char c)
{
	if (is_blank(c) || is_newline(c) || is_operator(c))
		return (1);
	return (0);
}

/* A DELIMITER IS A METACHARACTER OR A SPECIAL CHARACTER (I.E. DOLLAR) */

int	is_delimiter(char c)
{
	if (is_metacharacter(c))
		return (1);
	return (0);
}

/* A WORD IS NOT A DELIMITER */

int	is_word(char c)
{
	if (!is_delimiter(c))
		return (1);
	return (0);
}
