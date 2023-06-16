/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_white_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:10:51 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/13 14:05:56 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	is_newline(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

int	is_white_space(char c)
{
	if (is_blank(c) || is_newline(c))
		return (1);
	return (0);
}
