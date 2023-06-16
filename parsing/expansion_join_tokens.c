/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expansion_join_tokens.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:55:29 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/18 18:23:22 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	get_expanded_size(char *s, int i)
{
	int	size;

	size = 0;
	while (is_white_space(s[i]))
		i++;
	while (s[i] && !is_white_space(s[i]))
	{
		i++;
		size++;
	}
	return (size);
}

static int	get_new_size(t_token **new)
{
	t_token	*ptr;
	int		size;
	int		i;

	size = 0;
	ptr = *new;
	while (ptr)
	{
		i = 0;
		if (ptr->id == EXPANDED)
			size += get_expanded_size(ptr->content, i);
		else if (ptr->id != DELETE)
		{
			while (ptr->content[i])
			{
				size++;
				i++;
			}
		}
		ptr = ptr->next;
	}
	return (size);
}

static void	copy_helper(t_token **new, t_token *curr)
{
	int		i;
	int		j;
	t_token	*ptr;

	i = 0;
	j = 0;
	ptr = *new;
	while (ptr)
	{
		if (ptr->id == EXPANDED)
		{
			while (ptr->content[j] && is_white_space(ptr->content[j]))
				j++;
			while (ptr->content[j] && !is_white_space(ptr->content[j]))
				curr->content[i++] = ptr->content[j++];
		}
		else if (ptr->id != DELETE)
			while (ptr->content[j])
				curr->content[i++] = ptr->content[j++];
		ptr = ptr->next;
		j = 0;
	}
	curr->content[i] = '\0';
}

static int	copy_join_tokens(t_token **new, t_token *curr, int size)
{
	free(curr->content);
	curr->content = NULL;
	curr->content = malloc((size + 1) * sizeof(char));
	if (!curr->content)
	{
		malloc_error_print_message(strerror(errno));
		return (ERROR_EXIT);
	}
	copy_helper(new, curr);
	free_token(new);
	return (0);
}

int	join_tokens(t_token **new, t_token *curr)
{
	int		size;

	size = get_new_size(new);
	if (size == 0)
	{
		free_token(new);
		curr->id = DELETE;
		return (1);
	}
	if (copy_join_tokens(new, curr, size) == ERROR_EXIT)
		return (ERROR_EXIT);
	return (1);
}
