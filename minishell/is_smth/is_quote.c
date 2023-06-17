/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:42:32 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/08 10:42:51 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/* IS QUOTE */

int	is_double_quote(char c)
{
	if (c == '\"')
		return (1);
	return (0);
}

int	is_simple_quote(char c)
{
	if (c == '\'')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	if (is_double_quote(c) || is_simple_quote(c))
		return (1);
	return (0);
}
