/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:47:06 by srapopor          #+#    #+#             */
/*   Updated: 2023/02/25 18:55:32 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	scan_quotes(char c, t_scan *scan)
{
	if (c == '\'' && !scan->within_double_quotes)
	{
		scan->within_single_quotes = !scan->within_single_quotes;
		return (1);
	}
	else if (c == '\"' && !scan->within_single_quotes)
	{
		scan->within_double_quotes = !scan->within_double_quotes;
		return (1);
	}
	return (0);
}
