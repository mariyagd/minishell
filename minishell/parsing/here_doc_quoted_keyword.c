/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_quoted_keyword.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:28:24 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 14:03:54 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	write2(char	*line, char *new_keyword, int fd)
{
	if (!line || ft_strncmp(line, new_keyword, ft_strlen(line) + 1) == 0)
		return (0);
	else
	{
		ft_dprintf(fd, "%s\n", line);
		free(line);
		line = NULL;
	}
	return (1);
}

static t_token	*create_token(t_token *token, char *key_word)
{
	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		error_message("ft_calloc failed");
		exit(1);
	}
	token->content = ft_strdup(key_word);
	if (!token->content)
	{
		error_message("ft_strdup failed");
		free(token);
		exit(1);
	}
	return (token);
}

int	here_doc_quote_removing(t_token *token, int pos)
{
	if (token->content[pos] == '\0')
		return (1);
	if (is_quote(token->content[pos]))
	{
		pos = remove_q(token, pos);
		if (pos == ERROR_EXIT)
			return (0);
		here_doc_quote_removing(token, pos);
	}
	else
	{
		pos++;
		here_doc_quote_removing(token, pos);
	}
	return (1);
}

void	keyword_is_quoted(char *key_word, int fd)
{
	t_token	*token;
	char	*line;

	line = NULL;
	token = NULL;
	token = create_token(token, key_word);
	if (!here_doc_quote_removing(token, 0))
	{
		free(token->content);
		free(token);
		exit(1);
	}
	while (1)
	{
		line = readline("> ");
		if (!write2(line, token->content, fd))
			break ;
	}
	if (line)
		free(line);
	free(token->content);
	free(token);
}
