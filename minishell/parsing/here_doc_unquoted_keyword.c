/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_unquoted_keyword.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:45:55 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/17 09:18:02 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	check_heredoc_dollar(t_token *token, int i)
{
	while (token->content[i])
	{
		if (is_dollar(token->content[i]))
		{
			if (is_dollar_to_expand(token, i))
				return (prepare_expand(token, i));
			else if (is_dollar(token->content[i + 1]))
				i = loop_dollars(token->content, i);
			else if (is_quote(token->content[i + 1]))
			{
				token->res = trim_dollar(token, i);
				if (token->res == ERROR_EXIT)
					return (ERROR_EXIT);
				i += token->res;
			}
			else if (token->content[i + 1] == '\0')
				break ;
			else
				i++;
		}
		else
			i++;
	}
	token->id = WORD;
	return (i);
}

static int	expand_here_doc(t_token *token, int pos)
{
	if (token)
	{
		if (token->id == DOLLAR && pos < (int)ft_strlen(token->content))
		{
			pos = check_heredoc_dollar(token, pos);
			if (pos == ERROR_EXIT)
				return (0);
			if (token->id == DELETE)
				return (1);
			expand_here_doc(token, pos);
		}
	}
	return (1);
}

static void	set_heredoc_id(t_token *token)
{
	if (ft_strchr(token->content, '$'))
		token->id = DOLLAR;
	else
		token->id = WORD;
}

static int	write1(t_token *token, char *key_word, int fd)
{
	if (!token->content || \
			ft_strncmp(token->content, key_word, ft_strlen(key_word) + 1) == 0)
		return (0);
	set_heredoc_id(token);
	if (token->id == DOLLAR)
	{
		if (!expand_here_doc(token, 0))
			return (0);
		else if (token->id == DELETE)
			ft_dprintf(fd, "\n");
		else
			ft_dprintf(fd, "%s\n", token->content);
		free(token->content);
	}
	else
	{
		ft_dprintf(fd, "%s\n", token->content);
		free(token->content);
		token->content = NULL;
	}
	return (1);
}

void	keyword_is_unquoted(char *key_word, int fd)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		error_message("ft_calloc failed");
		exit(1);
	}
	while (1)
	{
		token->content = readline("> ");
		if (!write1(token, key_word, fd))
			break ;
	}
	rl_on_new_line();
	free(token->content);
	free(token);
}
