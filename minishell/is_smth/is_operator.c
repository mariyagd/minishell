/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:39:10 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/09 14:01:48 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/* PIPELINE IS A METACHARCTER AND CONTROL OPERATOR*/

int	is_pipeline(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

/* CHEVRON IS A METACHARACTER AND REDIRECTION OPERATOR */

int	is_lchevron(char c)
{
	if (c == '<')
		return (1);
	return (0);
}

int	is_rchevron(char c)
{
	if (c == '>')
		return (1);
	return (0);
}

int	is_chevron(char c)
{
	if (is_lchevron(c) || is_rchevron(c))
		return (1);
	return (0);
}

/* OPERATOR IS A PIPELINE OR A CHEVRON */

int	is_operator(char c)
{
	if (is_pipeline(c) || is_chevron(c))
		return (1);
	return (0);
}
