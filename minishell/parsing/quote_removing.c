/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:22:28 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 12:47:03 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	copy_string_unquoted(t_token *curr, char *new_str, \
								int start, int pos)
{
	int		j;
	int		i;
	int		save;

	j = 0;
	i = 0;
	save = 0;
	while (curr->content[i])
	{
		if (i == start)
			i++;
		else if (i == pos)
		{
			i++;
			save = j;
		}
		else
		{
			new_str[j] = curr->content[i];
			i++;
			j++;
		}
	}
	new_str[j] = '\0';
	return (save);
}

int	string_replace(t_token *curr, int start, int pos)
{
	int		save;
	char	*new_str;

	new_str = malloc(sizeof(char) * (ft_strlen(curr->content) - 2 + 1));
	if (!new_str)
	{
		malloc_error_print_message(strerror(errno));
		return (ERROR_EXIT);
	}
	save = copy_string_unquoted(curr, new_str, start, pos);
	free(curr->content);
	curr->content = NULL;
	curr->content = new_str;
	return (save);
}

int	remove_q(t_token *curr, int pos)
{
	int	start;

	start = pos;
	pos = loop_through(curr->content, pos);
	pos = string_replace(curr, start, pos);
	if (pos == ERROR_EXIT)
		return (ERROR_EXIT);
	return (pos++);
}

int	quote_removing(t_token **head, t_token *curr, int pos)
{
	if (!head || !*head)
		return (1);
	if (curr->content[pos] == '\0')
	{
		if (curr->next)
		{
			pos = 0;
			curr = curr->next;
			quote_removing(head, curr, pos);
		}
		return (1);
	}
	else if (is_quote(curr->content[pos]))
	{
		pos = remove_q(curr, pos);
		if (pos == ERROR_EXIT)
			return (free_token(head), 0);
		quote_removing(head, curr, pos);
	}
	else
	{
		pos++;
		quote_removing(head, curr, pos);
	}
	return (1);
}
