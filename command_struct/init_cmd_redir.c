/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:37:00 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/17 10:56:46 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	get_redir_size(t_token *ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr->id != PIPELINE)
	{
		if (ptr->id == L_CHEVRON || ptr->id == R_CHEVRON || \
				ptr->id == APPEND)
		{
			if (ptr->next && ptr->next->id == KEY_WORD)
				i = i + 2;
			else
				i = i + 1;
		}
		else if (ptr->id == HERE_DOC)
			i = i + 1;
		ptr = ptr->next;
	}
	return (i);
}

static int	copy_redir_helper(t_token *ptr, t_cmd *cmd, int i)
{
	cmd->redir[i] = ft_strdup(ptr->content);
	if (!cmd->redir[i])
	{
		malloc_error_print_message("ft_strdup failed");
		return (-1);
	}
	if (ptr->id == HERE_DOC)
		return (i);
	if (!ptr->next || ptr->next->id != KEY_WORD)
		return (i);
	i++;
	ptr = ptr->next;
	cmd->redir[i] = ft_strdup(ptr->content);
	if (!cmd->redir[i])
	{
		malloc_error_print_message("ft_strdup failed");
		return (-1);
	}
	return (i);
}

/*
 * copy_redir() function
 *
 * GOAL: This function will copy the redirections from the token list
 * 	     to the cmd->redir.
 *
 * Returned values:
 * 	- 1 for success
 * 	- 0 for malloc error
 *
 * Procedure:
 * 	- If we encounter a redirection operator the token id is marked as
 * 	  L_CHEVRON, R_CHEVRON, APPEND, HERE_DOC.
 * 	- We use copy_redir_helper() function to copy the redirections.
 * 		-> This function will alway generate 2 mallocs because each
 * 		   operator is followed by a file name.
 * 		-> If the malloc fails, the function returns 0 (if !i) {return (0);}.
 * 		-> Else, it returns the index of the current redir element.
 */

static int	copy_redir(t_token **token, t_cmd *cmd)
{
	t_token	*ptr;
	int		i;

	ptr = *token;
	i = 0;
	while (ptr && ptr->id != PIPELINE)
	{
		if (ptr->id == L_CHEVRON || ptr->id == R_CHEVRON || \
				ptr->id == APPEND || ptr->id == HERE_DOC)
		{
			i = copy_redir_helper(ptr, cmd, i);
			if (i == -1)
				return (0);
			i++;
		}
		if (ptr->next)
			ptr = ptr->next;
		else
			break ;
	}
	return (1);
}

/*
 * create_redir() function
 *
 * GOAL: This function will malloc and fill the redir element 
 *       of the cmd structure.
 *
 * NOTE: This function is called by init_cmd() function.
 * 
 * Returned values:
 * 	- 1 for success
 *	- 0 for malloc error
 *
 * Procedure:
 * 	- We firstly call get_redir_size() function to know how many rediections
 * 	  we have to malloc. 
 * 	- If the size is 0, it means there is no redirections to do.
 * 	  As cmd was generated with calloc, cmd->redir is already set to NULL.
 * 	  So we just return 1.
 * 	- Else, we malloc the redir element with the size we got.
 * 	- Then we call copy_redir() function to copy the redirections 
 * 	- If copy_redir() returns 0 for malloc error, 
 * 	  we free the redir element and return 0.
 *	- Else, we return 1.
 */
int	create_redir(t_token **token, t_cmd *cmd)
{
	t_token	*ptr;
	int		i;
	int		res;

	res = 0;
	ptr = *token;
	i = get_redir_size(ptr);
	if (i == 0)
		return (1);
	cmd->redir = ft_calloc(i + 1, sizeof(char *));
	if (!cmd->redir)
	{
		malloc_error_print_message("ft_calloc failed");
		return (0);
	}
	res = copy_redir(token, cmd);
	if (!res)
	{
		free_tab2d(cmd->redir);
		return (0);
	}
	return (1);
}
