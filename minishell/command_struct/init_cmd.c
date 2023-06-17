/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:54:50 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/17 10:28:48 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	cmd_backadd(t_cmd **head, t_cmd *new)
{
	t_cmd	*ptr;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	ptr = *head;
	while (ptr)
	{
		if (!ptr->next)
			break ;
		ptr = ptr->next;
	}
	ptr->next = new;
}

static void	init_fds(t_cmd *cmd)
{
	cmd->ffd_in = -1;
	cmd->ffd_out = -1;
	cmd->save_fdout = -1;
	cmd->save_fdin = -1;
}

/*
 * init_cmd() function:
 *
 * GOAL: This function will malloc a new t_cmd structure 
 *       and all of its elements.
 *
 * Returned values:
 * 	- NULL for malloc error
 * 	- the cmd structure for success
 *
 * 	If res == 0 (!res), we free the current cmd structure and return NULL.
 * 	Then create_cmd_linked_list() will free the whole linked list.
 */
static t_cmd	*init_cmd(t_token **token)
{
	t_cmd	*cmd;
	int		res;

	res = 0;
	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
	{
		malloc_error_print_message("ft_calloc failed");
		return (NULL);
	}
	cmd->next = NULL;
	res = create_cmd(token, cmd);
	if (!res)
	{
		free_cmd(&cmd);
		return (NULL);
	}
	res = create_redir(token, cmd);
	if (!res)
	{
		free_cmd(&cmd);
		return (NULL);
	}
	init_fds(cmd);
	return (cmd);
}

static void	create_cmd_linked_list(t_token **token, t_cmd *head)
{
	t_cmd	*new;
	t_token	*ptr;

	ptr = *token;
	new = NULL;
	while (ptr)
	{
		while (ptr && ptr->id != PIPELINE)
			ptr = ptr->next;
		if (!ptr)
			break ;
		ptr = ptr->next;
		new = init_cmd(&ptr);
		if (!new)
		{
			free_cmd(&head);
			return ;
		}
		cmd_backadd(&head, new);
	}
}

/*
 * cmd_linked_list function
 * GOAL: create a linked list of commands
 *
 * NOTE: if there is a malloc error, we call malloc_error_print_message 
 * 	     function, which printf the error message and set g_shell->exit_error
 * 	     to 1. 
 *
 * 	- Firstly we allocate the head. 
 * 	- If there was a malloc error, return NULL.
 *  - If there is a pipeline, we create a new command and link it to the list
 *    with create_cmd_linked_list function.
 *	- If a malloc error occurs while linking,
 *	  we free the whole list and set the head to NULL.
 *
 *  We also free token list because we don't need it anymore.
 */
t_cmd	*cmd_linked_list(t_token **token)
{
	t_cmd	*head;
	t_token	*ptr;

	if (!token || !*token)
		return (NULL);
	ptr = *token;
	head = NULL;
	head = init_cmd(&ptr);
	if (!head)
		return (NULL);
	while (ptr && ptr->id != PIPELINE)
		ptr = ptr->next;
	create_cmd_linked_list(&ptr, head);
	free_token(token);
	if (!head)
		return (NULL);
	return (head);
}
