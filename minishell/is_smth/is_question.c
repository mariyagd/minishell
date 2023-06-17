/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_question.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:33:22 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/18 12:44:28 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	is_question(char c)
{
	if (c == '?')
		return (1);
	return (0);
}

int	is_punct(char c)
{
	if ((c >= 33 && c <= 47) || \
		(c >= 58 && c <= 64) || \
		(c >= 91 && c <= 94) || \
		(c == 96) || \
		(c >= 123 && c <= 126))
		return (1);
	return (0);
}
