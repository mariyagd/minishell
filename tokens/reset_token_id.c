/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_token_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:54:02 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/16 20:24:54 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	check_for_heredoc2(t_token **head, int pos)
{
	t_token	*token;
	t_token	*prev;

	if (!head || !*head || pos == 0)
		return (0);
	token = *head;
	prev = NULL;
	while (token)
	{
		if (prev && prev->pos == pos)
			break ;
		if (token->next != NULL)
			prev = token;
		token = token->next;
	}
	if (prev->id == HERE_DOC)
		return (1);
	return (0);
}

static void	set_id2(t_token **head, t_token *token)
{
	int	res;

	res = 0;
	res = check_for_heredoc2(head, token->pos);
	if (res == 1)
		token->id = KEY_WORD;
	else if (ft_strncmp(token->content, "|", 2) == 0)
		token->id = PIPELINE;
	else if (ft_strncmp(token->content, "<", 2) == 0)
		token->id = L_CHEVRON;
	else if (ft_strncmp(token->content, ">", 2) == 0)
		token->id = R_CHEVRON;
	else if (ft_strncmp(token->content, "<<", 3) == 0)
		token->id = HERE_DOC;
	else if (ft_strncmp(token->content, ">>", 3) == 0)
		token->id = APPEND;
	else if (ft_strchr(token->content, '$'))
		token->id = DOLLAR;
	else
		token->id = WORD;
	return ;
}

void	set_id_for_expansion(t_token **head)
{
	t_token	*token;

	token = *head;
	while (token)
	{
		set_id2(head, token);
		token = token->next;
	}
	return ;
}
