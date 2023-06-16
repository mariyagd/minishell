/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_routine_delete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:46:16 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/18 11:39:49 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	token_list_size(t_token	**head)
{
	t_token	*tmp;
	int		count;

	tmp = *head;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

static t_token	*delete_helper(t_token **head, t_token *curr, \
								t_token *prev, int i)
{
	int		size;

	size = token_list_size(head);
	if (i == 0 && size == 1)
	{
		free(curr->content);
		free(curr);
		*head = NULL;
		return (*head);
	}
	else if (i == 0 && size > 1)
	{
		*head = curr->next;
		prev = *head;
	}
	else if (i == size - 1)
		prev->next = NULL;
	else
		prev->next = curr->next;
	free(curr->content);
	free(curr);
	curr = NULL;
	return (prev);
}

t_token	*delete_token(t_token **head)
{
	int		i;
	t_token	*curr;
	t_token	*prev;

	i = 0;
	curr = *head;
	prev = NULL;
	while (curr->id != DELETE)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	return (delete_helper(head, curr, prev, i));
}
