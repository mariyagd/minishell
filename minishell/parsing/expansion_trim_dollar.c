/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expansion_trim_dollar.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:24:54 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/19 11:50:58 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/*
 * If malloc error -> function returns 0
 */
static int	copy_string(t_token *curr, char **s, int pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*s = malloc(sizeof(char) * ft_strlen(curr->content));
	if (!*s)
		return (0);
	i = 0;
	while (curr->content[i])
	{
		if (i == pos)
			i++;
		(*s)[j] = curr->content[i];
		i++;
		j++;
	}
	(*s)[j] = '\0';
	free(curr->content);
	curr->content = *s;
	return (1);
}

/*
 * if copy_string returns 0 -> there is a malloc error
 * -> exit the program
 */
int	trim_dollar(t_token *curr, int pos)
{
	int		i;
	int		start;
	char	*s;

	s = NULL;
	i = 0;
	start = 0;
	while (curr->content[i])
	{
		if (is_double_quote(curr->content[i]))
		{
			start = i;
			i = loop_through(curr->content, i);
			if (pos > start && pos < i)
				return (1);
		}
		i++;
	}
	if (!copy_string(curr, &s, pos))
		return (ERROR_EXIT);
	return (0);
}
