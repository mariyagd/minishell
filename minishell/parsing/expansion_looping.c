/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expansion_looping.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:54:34 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/18 19:05:32 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/* used in trim_dollar*/
/*
 * int	loop_simple_quotes(char *s, int i)
{
	i++;
	while (!is_simple_quote(s[i]))
		i++;
	return (i);
}
*/

/* used in trim_dollar*/
/*
int	loop_double_quotes(char *s, int i)
{
	int		j;
	int		count;

	j = 0;
	count = 0;
	while (s[j] && j < i)
	{
		if (is_simple_quote(s[j]))
			j = loop_simple_quotes(s, i);
		else if (is_double_quote(s[j]))
		{
			count++;
			j++;
		}
		else
			j++;
	}
	if (count != 0 && count % 2 == 0)
		return (0);
	return (1);
}
*/

/* used in check_dollar*/
int	loop_dollars(char *s, int i)
{
	while (is_dollar(s[i]) && s[i])
		i++;
	if (s[i] != '\0' && !is_white_space(s[i]))
		i--;
	return (i);
}

/*
 * char c will stock the quote - double or simple
 * this is why c = s[i]
 *
 * used in not_within_squotes
 */
int	loop_through(char *s, int i)
{
	char	c;

	c = s[i];
	i++;
	while (s[i] != c)
		i++;
	return (i);
}	
