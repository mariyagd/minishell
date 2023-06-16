/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_check_if_quoted_keyword.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:47:22 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 10:56:01 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	check_if_quoted_keyword(char *key_word)
{
	int	i;

	i = 0;
	while (key_word[i])
	{
		if (is_quote(key_word[i]))
			return (1);
		i++;
	}
	return (0);
}

void	write_in_heredoc_helper(char *key_word, int fd)
{
	if (check_if_quoted_keyword(key_word))
		keyword_is_quoted(key_word, fd);
	else
		keyword_is_unquoted(key_word, fd);
}
