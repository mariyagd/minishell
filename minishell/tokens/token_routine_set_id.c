/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_routine_set_id.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:26:32 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/21 09:53:12 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	set_id_expansion(t_token *token, int flag)
{
	if (ft_strchr(token->content, '$'))
	{
		if (flag == KEY_WORD)
		{
			return (DOLLAR_KEY_W);
		}
		else
			return (DOLLAR);
	}
	else
	{
		if (flag == KEY_WORD)
			return (KEY_WORD);
		else
			return (WORD);
	}
}

int	check_for_heredoc(t_token **head, int pos)
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
	if (prev->id == HERE_DOC || prev->id == L_CHEVRON || \
			prev->id == R_CHEVRON || prev->id == APPEND)
		return (1);
	return (0);
}

void	set_id(t_token **head, t_token *token)
{
	int	res;

	res = 0;
	res = check_for_heredoc(head, token->pos);
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

/*void	set_id_after_expansion(t_token **head)
{
	t_token	*token;

	token = *head;
	while (token)
	{
		if (token->id == HERE_DOC || token->id == L_CHEVRON || \
				token->id == R_CHEVRON || token->id == APPEND)
		{
			if (token->next != NULL)
			{
				token = token->next;
				token->id = KEY_WORD;
			}
			else
				break ;
		}
		else
		{
			if (token->next)
				token = token->next;
			else
				break ;
		}
	}
	return ;
}*/

int	set_id_after_expansion(t_token *token, int flag)
{
	if (ft_strchr(token->content, '$'))
	{
		if (flag == DOLLAR_KEY_W)
		{
			return (DOLLAR_KEY_W);
		}
		else
			return (DOLLAR);
	}
	else
	{
		if (flag == DOLLAR_KEY_W)
			return (KEY_WORD);
		else
			return (WORD);
	}
}

void	set_id_before_expansion(t_token **head)
{
	t_token	*token;

	token = *head;
	while (token)
	{
		if (token->id == PIPELINE)
			token = token->next;
		else if (token->id == HERE_DOC)
		{
			token->next->id = KEY_WORD;
			token = token->next->next;
		}
		else if (token->id == APPEND || token->id == R_CHEVRON || \
				token->id == L_CHEVRON)
		{
			token->next->id = set_id_expansion(token->next, KEY_WORD);
			token = token->next->next;
		}
		else
		{
			token->id = set_id_expansion(token, WORD);
			token = token->next;
		}
	}
	return ;
}
